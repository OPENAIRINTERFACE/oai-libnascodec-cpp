#include <_5GS/ie/PDU_session_identity.h>
#include <buffers.h>

namespace _5GS
{
namespace IE
{

PDU_session_identity::PDU_session_identity(PDU_session_identity::Value value)
{
    set(value);
}

std::string PDU_session_identity::getName() const
{
    return "PDU session identity";
}

void PDU_session_identity::set(PDU_session_identity::Value id)
{
    m_present = true;
    m_value = id;
}

PDU_session_identity::Value PDU_session_identity::get() const
{
    raise_exception_if_not_present(className(this));
    return m_value;
}

int PDU_session_identity::code_V(std::vector<uint8_t> &data) const
{
    raise_exception_if_not_present(className(this));
    data.push_back(static_cast<uint8_t>(m_value));
    return 1;
}

int PDU_session_identity::decode_V(const std::vector<uint8_t> &data)
{
    return decode_V(data[0]);
}

int PDU_session_identity::decode_V(const uint8_t &data)
{
    m_value = PDU_session_identity::uint8_t_to_Value(data);
    m_present = true;
    return 1;
}

PDU_session_identity::Value PDU_session_identity::uint8_t_to_Value(const uint8_t &byte)
{
    if (byte > static_cast<uint8_t>(PDU_session_identity::Value::reserved))
    {
        return PDU_session_identity::Value::reserved;
    }
    return static_cast<PDU_session_identity::Value>(byte);
}

std::string PDU_session_identity::valueToString() const
{
    if (not isSet())
    {
        return "-";
    }
    return PDU_session_identity::value_to_string(m_value);
}

std::string PDU_session_identity::value_to_string(PDU_session_identity::Value value)
{
    switch (value)
    {
    case PDU_session_identity::Value::No_PDU_session_identity_assigned:
        return "No PDU session identity assigned";
    case PDU_session_identity::Value::PDU_session_identity_value_1:
        return "PDU session identity value 1";
    case PDU_session_identity::Value::PDU_session_identity_value_2:
        return "PDU session identity value 2";
    case PDU_session_identity::Value::PDU_session_identity_value_3:
        return "PDU session identity value 3";
    case PDU_session_identity::Value::PDU_session_identity_value_4:
        return "PDU session identity value 4";
    case PDU_session_identity::Value::PDU_session_identity_value_5:
        return "PDU session identity value 5";
    case PDU_session_identity::Value::PDU_session_identity_value_6:
        return "PDU session identity value 6";
    case PDU_session_identity::Value::PDU_session_identity_value_7:
        return "PDU session identity value 7";
    case PDU_session_identity::Value::PDU_session_identity_value_8:
        return "PDU session identity value 8";
    case PDU_session_identity::Value::PDU_session_identity_value_9:
        return "PDU session identity value 9";
    case PDU_session_identity::Value::PDU_session_identity_value_10:
        return "PDU session identity value 10";
    case PDU_session_identity::Value::PDU_session_identity_value_11:
        return "PDU session identity value 11";
    case PDU_session_identity::Value::PDU_session_identity_value_12:
        return "PDU session identity value 12";
    case PDU_session_identity::Value::PDU_session_identity_value_13:
        return "PDU session identity value 13";
    case PDU_session_identity::Value::PDU_session_identity_value_14:
        return "PDU session identity value 14";
    case PDU_session_identity::Value::PDU_session_identity_value_15:
        return "PDU session identity value 15";
    // All other value are "Reserved"
    default:
        return "Reserved";
    }
    throw std::invalid_argument("Not a value");
}

} // namespace IE
} // namespace _5GS
