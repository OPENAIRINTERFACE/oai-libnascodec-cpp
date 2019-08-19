#include <nas.h>
#include <_5GS/PDU_session_establishment_request.h>
#include <buffers.h>

namespace _5GS
{

PDU_session_establishment_request::PDU_session_establishment_request()
{
    m_message_type.set(IE::Message_type::Value::PDU_session_establishment_request);
}

PDU_session_establishment_request::PDU_session_establishment_request(
    IE::PDU_session_identity psi,
    IE::Procedure_transaction_identity pti,
    // Mandatory
    IE::Integrity_protection_maximum_data_rate ipmdr,
    // Optionals
    IE::PDU_session_type pst,
    IE::SSC_mode sm,
    IE::SM_PDU_DN_request_container spdnc,
    //IE::_5GSM_capability,
    int placeholder)
    // initializers
    : Pdu5gsSm::Pdu5gsSm(psi, pti),
      m_integrity_protection_maximum_data_rate(ipmdr),
      m_pdu_session_type(pst),
      m_ssc_mode(sm),
      m_sm_pdu_dn_request_container(spdnc)
{
    m_message_type.set(IE::Message_type::Value::PDU_session_establishment_request);
}

int PDU_session_establishment_request::code(std::vector<uint8_t> &data) const
{
    int size = 0;
    try
    {
        size += Nas::codeProtocolDiscriminator(data, Nas::ProtocolDiscriminator::_5GS_session_management_messages);

        // mandatory parameters
        size += codeSMHeader(data);
        size += m_integrity_protection_maximum_data_rate.code(data, InformationElement::Format::V);
        // add optional parameters
        if (m_pdu_session_type.isSet())
        {
            size += m_pdu_session_type.code(data, InformationElement::Format::TV, static_cast<uint8_t>(Iei::PDU_session_type));
        }
        if (m_ssc_mode.isSet())
        {
            size += m_ssc_mode.code(data, InformationElement::Format::TV, static_cast<uint8_t>(Iei::SSC_Mode));
        }
        if (m_sm_pdu_dn_request_container.isSet())
        {
            size += m_sm_pdu_dn_request_container.code(data, InformationElement::Format::TLV, static_cast<uint8_t>(Iei::SM_PDU_DN_request_container));
        }
    }
    catch (const std::exception &exception)
    {
        std::string test = std::string("Error coding ") + className(this);
        throw NasCodecException(
            stack_and_format_exception(
                exception.what(),
                std::string("Error coding ") + className(this)));
    }
    return size;
}

int PDU_session_establishment_request::decode(const std::vector<uint8_t> &data)
{
    unsigned int offset = 0;
    offset = Pdu5gsSm::decode(data);
    const std::vector<uint8_t> ipmdr_data(&data[offset], &data[offset + 2]);
    offset += m_integrity_protection_maximum_data_rate.decode_V(ipmdr_data);
    while (offset < data.size())
    {
        const std::vector<uint8_t> iei_data(data.cbegin() + offset, data.cend());
        uint8_t iei = iei_data[0];
        if (iei > 0x90)
        {
            iei = iei & 0xf0;
        }
        switch (iei)
        {
        case PDU_session_establishment_request::Iei::PDU_session_type:
            offset += m_pdu_session_type.decode(iei_data, InformationElement::Format::TV, iei);
            break;
        case PDU_session_establishment_request::Iei::SSC_Mode:
            offset += m_ssc_mode.decode(iei_data, InformationElement::Format::TV, iei);
            break;
        case PDU_session_establishment_request::Iei::SM_PDU_DN_request_container:
            offset += m_sm_pdu_dn_request_container.decode(iei_data, InformationElement::Format::TLV, iei);
            break;
        default:
            break;
        }
    }
    return offset;
}

std::string PDU_session_establishment_request::to_string() const
{
    std::string str;
    str = "PDU_session_establishment_request";
    str += "(";
    // Header
    str += header_to_string();
    // Mandatory parameters
    str += ", " + m_integrity_protection_maximum_data_rate.to_string();
    // Optional parameters
    if (m_pdu_session_type.isSet())
    {
        str += ", " + m_pdu_session_type.to_string();
    }
    if (m_ssc_mode.isSet())
    {
        str += ", " + m_ssc_mode.to_string();
    }
    if (m_sm_pdu_dn_request_container.isSet())
    {
        str += ", " + m_sm_pdu_dn_request_container.to_string();
    }
    str += ")";
    return str;
}

}; // namespace _5GS
