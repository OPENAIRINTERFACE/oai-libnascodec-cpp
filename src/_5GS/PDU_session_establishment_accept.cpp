#include <nas.h>
#include <_5GS/PDU_session_establishment_accept.h>
#include <helpers.h>

namespace _5GS
{

PDU_session_establishment_accept::PDU_session_establishment_accept()
{
    message_type.set(IE::Message_type::Value::PDU_session_establishment_accept);
}

PDU_session_establishment_accept::PDU_session_establishment_accept(
    IE::PDU_session_identity psi,
    IE::Procedure_transaction_identity pti,
    // Mandatory
    IE::PDU_session_type pst
    // Optionals
    )
    : Pdu5gsSm::Pdu5gsSm(psi, pti)

{
    // FIXME
    message_type.set(IE::Message_type::Value::PDU_session_establishment_accept);
    pdu_session_type = pst;
}

int PDU_session_establishment_accept::code(std::vector<uint8_t> &data) const
{
    int size = 0;
    try
    {
        size += Nas::codeProtocolDiscriminator(data, Nas::ProtocolDiscriminator::_5GS_session_management_messages);

        // mandatory parameters
        size += codeSMHeader(data);
        size += pdu_session_type.code(data, InformationElement::Format::V);
        // FIXME 
        // add optional parameters
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

int PDU_session_establishment_accept::decode(const std::vector<uint8_t> &data)
{
    unsigned int offset = 0;
    offset = Pdu5gsSm::decode(data);
    const std::vector<uint8_t> ipmdr_data(&data[offset], &data[offset + 2]);
    // FIXME 
    //offset += integrity_protection_maximum_data_rate.decode_V(ipmdr_data);
    offset += pdu_session_type.decode(data, InformationElement::Format::V);
    while (offset < data.size())
    {
        const std::vector<uint8_t> iei_data(data.cbegin() + offset, data.cend());
        uint8_t iei = iei_data[0];
        if (iei > 0x80)
        {
            iei = iei & 0xf0;
        }
        switch (iei)
        {
        //case PDU_session_establishment_accept::Iei::PDU_session_type:
        //    offset += pdu_session_type.decode(iei_data, InformationElement::Format::TV, iei);
        default:
            break;
        }
    }
    return offset;
}

std::string PDU_session_establishment_accept::to_string() const
{
    std::string str;
    str = "PDU_session_establishment_accept";
    str += "(";
    // Header
    str += header_to_string();
    // Mandatory parameters
    str += ", " + pdu_session_type.to_string();
    // Optional parameters
    /*
    if (pdu_session_type.isSet())
    {
        str += ", " +
               pdu_session_type.name +
               "=" +
               pdu_session_type.to_string();
    }
    str += ")";
     */
    return str;
}

}; // namespace _5GS
