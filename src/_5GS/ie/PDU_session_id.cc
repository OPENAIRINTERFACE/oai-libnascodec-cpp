#include <_5GS/ie/PDU_session_ID.h>

namespace _5GS
{
namespace IE
{

void PDU_session_ID::set(PDU_session_ID::Value id)
{
    this->present = true;
    this->value = id;
}

PDU_session_ID::Value PDU_session_ID::get() const
{
    return this->value;
}

std::vector<uint8_t> PDU_session_ID::code_V() const
{
    std::vector<uint8_t> data;
    char c;
    int v;
    v = static_cast<int>(this->value);
    c = (char)  v;
    data.push_back(c);
    return data;
}


} // namespace IE
} // namespace _5GS

