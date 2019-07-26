#include <_5GS/ie/PDU_session_identity.h>
#include <helpers.h>

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
    this->raise_exception_if_not_present(className(this));
    return this->value;
}

int PDU_session_identity::code_V_ex(std::vector<uint8_t> &data) const
{
    this->raise_exception_if_not_present(className(this));
    data.push_back(static_cast<uint8_t>(this->value));
    return 1;
}

int PDU_session_identity::decode_V_ex(const std::vector<uint8_t> &data)
{
    // TODO
    throw std::runtime_error(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
    return -1;
}

} // namespace IE
} // namespace _5GS
