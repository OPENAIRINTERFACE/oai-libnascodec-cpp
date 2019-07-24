#include <_5GS/ie/Message_type.h>

namespace _5GS
{
namespace IE
{

void Message_type::set(Message_type::Value value)
{
    this->present = true;
    this->value = value;
}

Message_type::Value Message_type::get() const
{
    this->raise_exception_if_not_present();
    return this->value;
}

int Message_type::code_V_ex(std::vector<uint8_t> &data) const
{
    this->raise_exception_if_not_present();
    data.push_back(static_cast<uint8_t>(this->value));
    return 1;
}

int Message_type::decode_V_ex(const std::vector<uint8_t> &data)
{
    // TODO
    throw std::runtime_error("Not implemented");
    return -1;
}

}; // namespace IE
}; // namespace _5GS
