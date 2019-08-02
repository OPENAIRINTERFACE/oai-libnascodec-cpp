#include <nas.h>
#include <_5GS/PDU_session_establishment_request.h>
#include <helpers.h>

namespace _5GS
{

PDU_session_establishment_request::PDU_session_establishment_request(void)
{
    this->message_type.set(IE::Message_type::Value::PDU_session_establishment_request);
}

int PDU_session_establishment_request::code_ex(std::vector<uint8_t> &data) const
{
    int size = 0;
    try
    {
        size += Nas::codeProtocolDiscriminator(data, Nas::ProtocolDiscriminator::_5GS_session_management_messages);
        size += Nas::codeSecurityHeaderType(data, Nas::SecurityHeaderType::Plain_5GS_NAS_message__not_security_protected);
        // mandatory parameters
        size += this->codeSMHeader(data);
        size += this->integrity_protection_maximum_data_rate.code_ex(data, InformationElement::Format::V);
        // add optional parameters
        size += this->pdu_session_type.code(data, InformationElement::Format::TV);
    }
    catch (const std::exception &exception)
    {
        std::string test = std::string("Error coding ") + className(this);
        throw std::runtime_error(
            stack_and_format_exception(
                exception.what(),
                std::string("Error coding ") + className(this)));
    }
    return size;
}

int PDU_session_establishment_request::decode_ex(const std::vector<uint8_t> &data)
{
    unsigned int offset = 0;
    offset = Pdu5gsSm::decode_ex(data);
    const std::vector<uint8_t> ipmdr_data(&data[offset], &data[offset + 2]);
    offset += this->integrity_protection_maximum_data_rate.decode_V_ex(ipmdr_data);
    while ( offset < data.size() )
    {
        const std::vector<uint8_t> iei_data(data.cbegin() + offset, data.cend());
        uint8_t iei = iei_data[0];
        if ( iei > 0x90 ) {
            iei = iei & 0xf0;
        }
        switch (iei) {
            case PDU_session_establishment_request::Iei::PDU_session_type:
                offset += this->pdu_session_type.decode_ex(iei_data, InformationElement::Format::TV);
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
    str += this->header_to_string();
    // Mandatory parameters
    str += ", " +
           this->integrity_protection_maximum_data_rate.name +
           "=" + this->integrity_protection_maximum_data_rate.to_string();
    // Optional parameters
    if (this->pdu_session_type.isSet())
    {
        str += ", " +
               this->pdu_session_type.name +
               "=" +
               this->pdu_session_type.to_string();
    }
    str += ")";
    return str;
}

}; // namespace _5GS
