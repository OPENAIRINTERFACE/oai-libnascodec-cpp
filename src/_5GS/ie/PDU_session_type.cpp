#include <_5GS/ie/PDU_session_type.h>
#include <helpers.h>

namespace _5GS
{
namespace IE
{

const std::string PDU_session_type::name = "PDU session type";

PDU_session_type::PDU_session_type()
{
}

PDU_session_type::PDU_session_type(Value value)
{
    this->set(value);
}

void PDU_session_type::set(PDU_session_type::Value value)
{
    this->present = true;
    this->value = value;
}

PDU_session_type::Value PDU_session_type::get() const
{
    this->raise_exception_if_not_present(className(this));
    return this->value;
}

int PDU_session_type::code_TV_ex(std::vector<uint8_t> &data) const
{
    this->raise_exception_if_not_present(className(this));

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
        throw std::runtime_error(
            std::string("No data to decode") +
            std::string(__PRETTY_FUNCTION__));
    }
    v = data[0] & 0x0f;
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
        throw std::runtime_error(
            std::string(__PRETTY_FUNCTION__) +
            std::string(" Invalid data:\n") +
            dump_wireshark(data));
    }
    this->present = true;
    return 1;
}

std::string PDU_session_type::to_string() const
{
    if (not this->isSet())
    {
        return "-";
    }
    return PDU_session_type::value_to_string(this->value);
}

std::string PDU_session_type::value_to_string(const PDU_session_type::Value value)
{
    switch (value)
    {
    case PDU_session_type::Value::IPv4:
        return "IPv4";
    case PDU_session_type::Value::IPv6:
        return "IPv6";
    case PDU_session_type::Value::IPv4v6:
        return "IPv4v6";
    case PDU_session_type::Value::Unstructured:
        return "Unstructured";
    case PDU_session_type::Value::Ethernet:
        return "Ethernet";
    case PDU_session_type::Value::reserved:
        return "reserved";
    }
    throw std::invalid_argument("Not a value");
}

} // namespace IE
} // namespace _5GS
