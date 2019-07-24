#include <nas.h>
#include <_5GS/PDU_session_establishment_request.h>

namespace _5GS
{

PDU_session_establishment_request::PDU_session_establishment_request(void) {
    this->message_type.set(IE::Message_type::Value::PDU_session_establishment_request);
}

int PDU_session_establishment_request::code_ex(std::vector<uint8_t> & data) const
{
    int size = 0;
    size += Nas::codeProtocolDiscriminator(data, Nas::ProtocolDiscriminator::_5GS_session_management_messages);
    size += Nas::codeSecurityHeaderType(data, Nas::SecurityHeaderType::Plain_5GS_NAS_message__not_security_protected);
    // mandatory parameters
    size += this->codeSMHeader(data);
    size += this->integrity_protection_maximum_data_rate.code_ex(data,  InformationElement::Format::V);
    // add optional parameters
    size += this->pdu_session_type.code(data, InformationElement::Format::TV);
    return size;
}

}; // namespace _5GS

