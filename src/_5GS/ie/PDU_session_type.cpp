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
    this->raise_exception_if_not_present();
    return this->value;
}

int PDU_session_type::code_TV_ex(std::vector<uint8_t> &data) const
{
    this->raise_exception_if_not_present();

    uint8_t c, v;
    v = static_cast<uint8_t>(this->value);
    c = this->identifier | v;
    data.push_back(c);
    return 1;
}

int PDU_session_type::decode_TV_ex(const std::vector<uint8_t> &data)
{
    uint8_t v;
    if (data.size() == 0)
    {
        throw std::runtime_error("No data to decode");
    }
    v = data[0];
    switch (v)
    {
    case static_cast<uint8_t>(PDU_session_type::Value::Ethernet):
        this->value = PDU_session_type::Value::Ethernet;
        break;
    case static_cast<uint8_t>(PDU_session_type::Value::IPv4):
        this->value = PDU_session_type::Value::IPv4;
        break;
    case static_cast<uint8_t>(PDU_session_type::Value::IPv6):
        this->value = PDU_session_type::Value::IPv6;
        break;
    case static_cast<uint8_t>(PDU_session_type::Value::IPv4v6):
        this->value = PDU_session_type::Value::IPv4v6;
        break;
    case static_cast<uint8_t>(PDU_session_type::Value::Unstructured):
        this->value = PDU_session_type::Value::Unstructured;
        break;
    case static_cast<uint8_t>(PDU_session_type::Value::reserved):
        this->value = PDU_session_type::Value::reserved;
        break;
    default:
        throw std::runtime_error("Invalid data");
    }
    this->present = true;
    return 1;
}

} // namespace IE
} // namespace _5GS
