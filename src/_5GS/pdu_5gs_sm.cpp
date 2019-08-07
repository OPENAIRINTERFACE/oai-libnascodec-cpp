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
       size += this->pdu_session_identity.code(data, InformationElement::Format::V);
       size += this->procedure_transaction_identity.code(data, InformationElement::Format::V);
       size += this->message_type.code(data, InformationElement::Format::V);
       return size;
}

std::string Pdu5gsSm::header_to_string() const
{
       std::string str;
       // TODO add security header

       // FIXME factorize
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

int Pdu5gsSm::decode(const std::vector<uint8_t> &data)
{
       // TODO security header
       int offset = 1;
       int size = offset;
       // XXX tmp: copy for easier writing or slice for performance ?
       std::vector<uint8_t> tmp = data;

       // FIXME factorize
       tmp.erase(tmp.begin(), tmp.begin() + size);
       size = this->pdu_session_identity.decode_V(data[offset]);
       offset += size;

       tmp.erase(tmp.begin(), tmp.begin() + size);
       size = this->procedure_transaction_identity.decode_V(data[offset + 1]);
       offset += size;

       tmp.erase(tmp.begin(), tmp.begin() + size);
       this->message_type.decode(tmp, InformationElement::Format::V);
       offset += size;

       return offset;
}

}; // namespace _5GS
