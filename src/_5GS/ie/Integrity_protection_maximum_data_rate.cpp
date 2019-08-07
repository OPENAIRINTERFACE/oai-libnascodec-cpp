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
    this->setUplink(uplink);
    this->setDownlink(downlink);
}

void Integrity_protection_maximum_data_rate::setUplink(const Integrity_protection_maximum_data_rate::Value value)
{
    this->m_presentUplink = true;
    this->m_present = this->m_presentUplink && this->m_presentDownlink;
    this->m_uplink = value;
}

Integrity_protection_maximum_data_rate::Value Integrity_protection_maximum_data_rate::getUplink() const
{
    this->raise_exception_if_uplink_not_present();
    return this->m_uplink;
}

void Integrity_protection_maximum_data_rate::raise_exception_if_uplink_not_present() const
{
    if (!this->m_presentUplink)
    {
        throw std::invalid_argument("No value for uplink");
    }
}

void Integrity_protection_maximum_data_rate::setDownlink(const Integrity_protection_maximum_data_rate::Value value)
{
    this->m_presentDownlink = true;
    this->m_present = this->m_presentUplink && this->m_presentDownlink;
    this->m_downlink = value;
}

Integrity_protection_maximum_data_rate::Value Integrity_protection_maximum_data_rate::getDownlink() const
{
    this->raise_exception_if_downlink_not_present();
    return this->m_downlink;
}

void Integrity_protection_maximum_data_rate::raise_exception_if_downlink_not_present() const
{
    if (!this->m_presentDownlink)
    {
        throw std::invalid_argument("No value for downlink");
    }
}

int Integrity_protection_maximum_data_rate::code_V(std::vector<uint8_t> &data) const
{
    this->raise_exception_if_not_present(className(this));
    data.push_back(static_cast<uint8_t>(this->m_uplink));
    data.push_back(static_cast<uint8_t>(this->m_downlink));
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
        throw std::runtime_error(std::string("No data to decode: ") + std::string(__PRETTY_FUNCTION__));
    }
    this->m_uplink = fromUint8_t(data[0]);
    this->m_downlink = fromUint8_t(data[1]);

    this->m_present = true;
    this->m_presentUplink = true;
    this->m_presentDownlink = true;
    return 2;
}

std::string Integrity_protection_maximum_data_rate::to_string() const
{
    if (not this->isSet())
    {
        return "-";
    }
    return "uplink(" +
           Integrity_protection_maximum_data_rate::value_to_string(this->m_uplink) +
           ")&downlink(" +
           Integrity_protection_maximum_data_rate::value_to_string(this->m_downlink) +
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