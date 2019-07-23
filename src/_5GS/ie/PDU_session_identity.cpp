#include <_5GS/ie/PDU_session_identity.h>

namespace _5GS
{
namespace IE
{

void PDU_session_identity::set(PDU_session_identity::Value id)
{
    this->present = true;
    this->value = id;
}

PDU_session_identity::Value PDU_session_identity::get() const
{
    return this->value;
}

std::vector<uint8_t> PDU_session_identity::code_V() const
{
    std::vector<uint8_t> data;
    data.push_back(static_cast<uint8_t>(this->value));
    return data;
}

} // namespace IE
} // namespace _5GS
