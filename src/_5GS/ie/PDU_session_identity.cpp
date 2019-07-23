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

int PDU_session_identity::code_V(std::vector<uint8_t> &data) const
{
    if (!this->present)
    {
        return -1;
    }
    // FIXME  catch vector pushback exception
    data.push_back(static_cast<uint8_t>(this->value));
    return 0;
}

} // namespace IE
} // namespace _5GS
