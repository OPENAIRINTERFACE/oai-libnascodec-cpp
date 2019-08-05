#include <_5GS/pdu_5gs_sm.h>

namespace _5GS
{

Pdu5gsSm::Pdu5gsSm(IE::PDU_session_identity psi,
                   IE::Procedure_transaction_identity pti)
{
       this->pdu_session_identity = psi;
       this->procedure_transaction_identity = pti;
}

int Pdu5gsSm::codeSMHeader(std::vector<uint8_t> &data) const
{
       int size = 0;
       size += this->pdu_session_identity.code_ex(data, InformationElement::Format::V);
       size += this->procedure_transaction_identity.code_ex(data, InformationElement::Format::V);
       size += this->message_type.code_ex(data, InformationElement::Format::V);
       return size;
}

std::string Pdu5gsSm::header_to_string() const
{
       std::string str;
       // TODO add security header
       str += this->pdu_session_identity.name +
              "=" +
              this->pdu_session_identity.to_string() +
              ", ";

       str += this->procedure_transaction_identity.name +
              "=" +
              this->procedure_transaction_identity.to_string() +
              ", ";

       str += this->message_type.name +
              "=" +
              this->message_type.to_string();

       return str;
}

int Pdu5gsSm::decode_ex(const std::vector<uint8_t> &data)
{
       // TODO security header
       this->pdu_session_identity.decode_V_ex(data[2]);
       this->procedure_transaction_identity.decode_V_ex(data[3]);
       this->message_type.decode_V_ex(data[4]);
       return 5;
}

}; // namespace _5GS
