#include <_5GS/ie/PDU_session_type.h>

namespace _5GS
{
namespace IE
{

void PDU_session_type::set(PDU_session_type::Value value)
{
    this->present = true;
    this->value = value;
}

PDU_session_type::Value PDU_session_type::get() const
{
    return this->value;
}

std::vector<uint8_t> PDU_session_type::code_TV() const
{
    std::vector<uint8_t> data;
    uint8_t c,v;
    v = static_cast<uint8_t>(this->value);
    c = this->identifier | v;
    data.push_back(c);
    return data;
}

} // namespace IE
} // namespace _5GS
