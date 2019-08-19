#include <_5GS/ie/Integrity_protection_maximum_data_rate.h>
#include <buffers.h>

namespace _5GS
{
namespace IE
{

// class Integrity_protection_maximum_data_rate::Value

Integrity_protection_maximum_data_rate::Value::Value(
    const Maximum_data_rate_per_UE_for_user_plane &uplink,
    const Maximum_data_rate_per_UE_for_user_plane &downlink) : m_uplink(uplink), m_downlink(downlink)
{
}

// class  Integrity_protection_maximum_data_rate

Integrity_protection_maximum_data_rate::Integrity_protection_maximum_data_rate(const Value &fields) : m_fields(fields)
{
}

bool Integrity_protection_maximum_data_rate::isSet() const
{
    if (m_fields.m_uplink.isSet() == false)
    {
        return false;
    }
    if (m_fields.m_downlink.isSet() == false)
    {
        return false;
    }

    return true;
}

Integrity_protection_maximum_data_rate::Value Integrity_protection_maximum_data_rate::get() const
{
    return m_fields;
}

int Integrity_protection_maximum_data_rate::code_V(std::vector<uint8_t> &data) const
{
    raise_exception_if_not_present(className(this));
    int size = 0;
    size += m_fields.m_uplink.code_V(data);
    size += m_fields.m_downlink.code_V(data);
    return size;
}

int Integrity_protection_maximum_data_rate::decode_V(const std::vector<uint8_t> &data)
{
    int size = 0;
    size += m_fields.m_uplink.decode_V(data);
    size += m_fields.m_downlink.decode_V(std::vector<uint8_t>(data.begin() + 1, data.end()));
    return size;
}

std::string Integrity_protection_maximum_data_rate::getName() const
{
    return "Integrity protection maximum data rate";
}

std::string Integrity_protection_maximum_data_rate::valueToString() const
{
    if (not isSet())
    {
        return "-";
    }
    return "uplink(" +
           m_fields.m_uplink.valueToString() +
           ")&downlink(" +
           m_fields.m_downlink.valueToString() +
           ")";
}

} // namespace IE
} // namespace _5GS

bool operator==(const _5GS::IE::Integrity_protection_maximum_data_rate::Value &a,
                const _5GS::IE::Integrity_protection_maximum_data_rate::Value &b)
{
    return (a.m_uplink == b.m_uplink) &&
           (a.m_downlink == b.m_downlink);
}
