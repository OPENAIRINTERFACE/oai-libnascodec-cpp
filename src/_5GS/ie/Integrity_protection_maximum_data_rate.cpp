#include <_5GS/ie/Integrity_protection_maximum_data_rate.h>
#include <helpers.h>

namespace _5GS
{
namespace IE
{

const std::string Integrity_protection_maximum_data_rate::name = "Integrity protection maximum data rate";

Integrity_protection_maximum_data_rate::Integrity_protection_maximum_data_rate()
{

}

Integrity_protection_maximum_data_rate::Integrity_protection_maximum_data_rate(Value uplink, Value downlink)
{
    setUplink(uplink);
    setDownlink(downlink);
}

void Integrity_protection_maximum_data_rate::setUplink(const Integrity_protection_maximum_data_rate::Value value)
{
    m_presentUplink = true;
    m_present = m_presentUplink && m_presentDownlink;
    m_uplink = value;
}

Integrity_protection_maximum_data_rate::Value Integrity_protection_maximum_data_rate::getUplink() const
{
    raise_exception_if_uplink_not_present();
    return m_uplink;
}

void Integrity_protection_maximum_data_rate::raise_exception_if_uplink_not_present() const
{
    if (!m_presentUplink)
    {
        throw std::invalid_argument("No value for uplink");
    }
}

void Integrity_protection_maximum_data_rate::setDownlink(const Integrity_protection_maximum_data_rate::Value value)
{
    m_presentDownlink = true;
    m_present = m_presentUplink && m_presentDownlink;
    m_downlink = value;
}

Integrity_protection_maximum_data_rate::Value Integrity_protection_maximum_data_rate::getDownlink() const
{
    raise_exception_if_downlink_not_present();
    return m_downlink;
}

void Integrity_protection_maximum_data_rate::raise_exception_if_downlink_not_present() const
{
    if (!m_presentDownlink)
    {
        throw std::invalid_argument("No value for downlink");
    }
}

int Integrity_protection_maximum_data_rate::code_V(std::vector<uint8_t> &data) const
{
    raise_exception_if_not_present(className(this));
    data.push_back(static_cast<uint8_t>(m_uplink));
    data.push_back(static_cast<uint8_t>(m_downlink));
    return 2;
}

Integrity_protection_maximum_data_rate::Value Integrity_protection_maximum_data_rate::fromUint8_t(const uint8_t v)
{
    switch (v)
    {
    case static_cast<uint8_t>(Value::Full_data_rate):
        return Value::Full_data_rate;
    }
    return Value::_64_kbps;
}

int Integrity_protection_maximum_data_rate::decode_V(const std::vector<uint8_t> &data)
{
    if (data.size() < 2)
    {
        throw NasCodecException(std::string("No data to decode: ") + std::string(__PRETTY_FUNCTION__));
    }
    m_uplink = fromUint8_t(data[0]);
    m_downlink = fromUint8_t(data[1]);

    m_present = true;
    m_presentUplink = true;
    m_presentDownlink = true;
    return 2;
}

std::string Integrity_protection_maximum_data_rate::to_string() const
{
    if (not isSet())
    {
        return "-";
    }
    return "uplink(" +
           Integrity_protection_maximum_data_rate::value_to_string(m_uplink) +
           ")&downlink(" +
           Integrity_protection_maximum_data_rate::value_to_string(m_downlink) +
           ")";
}

std::string Integrity_protection_maximum_data_rate::value_to_string(const Integrity_protection_maximum_data_rate::Value value)
{
    switch (value)
    {
    case Integrity_protection_maximum_data_rate::Value::Full_data_rate:
        return "Full data rate";
    case Integrity_protection_maximum_data_rate::Value::_64_kbps:
        return "64 kbps";
    }
    throw std::invalid_argument("Not a value");
}

} // namespace IE
} // namespace _5GS