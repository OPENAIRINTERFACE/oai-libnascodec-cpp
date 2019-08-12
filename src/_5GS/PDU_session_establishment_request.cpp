#include <nas.h>
#include <_5GS/PDU_session_establishment_request.h>
#include <helpers.h>

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
    //IE::SSC_mode sm,
    //IE::_5GSM_capability,
    int placeholder)
    : Pdu5gsSm::Pdu5gsSm(psi, pti)

{
    m_message_type.set(IE::Message_type::Value::PDU_session_establishment_request);
    m_integrity_protection_maximum_data_rate = ipmdr;
    m_pdu_session_type = pst;
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
    str += ")";
    return str;
}

}; // namespace _5GS
