#include <_5GS/pdu_5gs_sm.h>

namespace _5GS
{

int Pdu5gsSm::codeSMHeader(std::vector<uint8_t> & data) const {
    int size = 0;
    size += this->pdu_session_identity.code_ex(data, InformationElement::Format::V);
    size += this->procedure_transaction_identity.code_ex(data, InformationElement::Format::V);
    size += this->message_type.code_ex(data, InformationElement::Format::V);
    return size;
}

}; // namespace _5GS
