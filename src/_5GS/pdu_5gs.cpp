#include <_5GS/pdu_5gs.h>

namespace _5GS
{

int Pdu5gs::code(std::vector<uint8_t> &data) const
{
    try
    {
        return code_ex(data);
    }
    catch (const std::exception &exception)
    {
        return -1;
    }
    return -1;
}

int Pdu5gs::code_ex(std::vector<uint8_t> &data) const
{
    throw std::runtime_error(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int Pdu5gs::decode(const std::vector<uint8_t> &data)
{
    try
    {
        return decode_ex(data);
    }
    catch (const std::exception &exception)
    {
        return -1;
    }
    return -1;
}

int Pdu5gs::decode_ex(const std::vector<uint8_t> &data)
{
    throw std::runtime_error(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int Pdu5gs::codeMMHeader(std::vector<uint8_t> &data) const
{
    return this->message_type.code_ex(data, InformationElement::Format::V);
}

}; // namespace _5GS
