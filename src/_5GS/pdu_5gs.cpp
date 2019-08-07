#include <_5GS/pdu_5gs.h>

namespace _5GS
{

int Pdu5gs::code(std::vector<uint8_t> &data) const
{
    throw std::runtime_error(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int Pdu5gs::decode(const std::vector<uint8_t> &data)
{
    throw std::runtime_error(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int Pdu5gs::codeMMHeader(std::vector<uint8_t> &data) const
{
    return this->message_type.code(data, InformationElement::Format::V);
}

std::string Pdu5gs::header_to_string() const
{
    std::string str;
    // TODO add security header
    // Message type
    str += this->message_type.name + "=" + this->message_type.to_string();
    return str;
}

}; // namespace _5GS
