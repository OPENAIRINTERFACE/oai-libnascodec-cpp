#include <_5GS/ie/Maximum_data_rate_per_UE_for_user_plane.h>
#include <buffers.h>

namespace _5GS
{
namespace IE
{

Maximum_data_rate_per_UE_for_user_plane::Maximum_data_rate_per_UE_for_user_plane(const Value &value)
{
    set(value);
}

std::string Maximum_data_rate_per_UE_for_user_plane::getName() const
{
    return "Maximum data rate per UE for user-plane integrity protection";
}

void Maximum_data_rate_per_UE_for_user_plane::set(Maximum_data_rate_per_UE_for_user_plane::Value value)
{
    m_present = true;
    m_value = value;
}

Maximum_data_rate_per_UE_for_user_plane::Value Maximum_data_rate_per_UE_for_user_plane::get() const
{
    raise_exception_if_not_present(className(this));
    return m_value;
}

int Maximum_data_rate_per_UE_for_user_plane::code_V(std::vector<uint8_t> &data) const
{
    raise_exception_if_not_present(className(this));
    data.push_back(static_cast<uint8_t>(m_value));
    return 1;
}

int Maximum_data_rate_per_UE_for_user_plane::decode_V(const std::vector<uint8_t> &data)
{
    m_value = uint8_t_to_Value(data[0]);
    m_present = true;
    return 1;
}

Maximum_data_rate_per_UE_for_user_plane::Value Maximum_data_rate_per_UE_for_user_plane::uint8_t_to_Value(const uint8_t &byte)
{
    switch (byte)
    {
    case static_cast<uint8_t>(Maximum_data_rate_per_UE_for_user_plane::Value::Full_data_rate):
        return Maximum_data_rate_per_UE_for_user_plane::Value::Full_data_rate;
    case static_cast<uint8_t>(Maximum_data_rate_per_UE_for_user_plane::Value::_64_kbps):
    default:
        /** The receiving entity shall treat a spare value as "64 kbps". */
        return Maximum_data_rate_per_UE_for_user_plane::Value::_64_kbps;
    }
    throw NasCodecException("Invalid value for Maximum_data_rate_per_UE_for_user_plane type");
}

std::string Maximum_data_rate_per_UE_for_user_plane::valueToString() const
{
    if (not isSet())
    {
        return "-";
    }
    return Maximum_data_rate_per_UE_for_user_plane::value_to_string(m_value);
}

std::string Maximum_data_rate_per_UE_for_user_plane::value_to_string(const Maximum_data_rate_per_UE_for_user_plane::Value value)
{
    switch (value)
    {
    case Maximum_data_rate_per_UE_for_user_plane::Value::_64_kbps:
        return "64 kbps";
    case Maximum_data_rate_per_UE_for_user_plane::Value::Full_data_rate:
        return "Full data rate";
    }
    throw std::invalid_argument("Not a value");
}

bool operator==(const Maximum_data_rate_per_UE_for_user_plane &a,
                const Maximum_data_rate_per_UE_for_user_plane &b)
{
    return (a.m_value == b.m_value) && (a.m_present == b.m_present);
}


} // namespace IE
} // namespace _5GS
