#include <_5GS/ie/Integrity_protection_maximum_data_rate.h>

namespace _5GS
{
namespace IE
{

void Integrity_protection_maximum_data_rate::setUplink(Integrity_protection_maximum_data_rate::Value value)
{
    this->presentUplink = true;
    this->present = this->presentUplink && this->presentDownlink;
    this->uplink = value;
}

Integrity_protection_maximum_data_rate::Value Integrity_protection_maximum_data_rate::getUplink() const
{
    this->raise_exception_if_uplink_not_present();
    return this->uplink;
}

void Integrity_protection_maximum_data_rate::raise_exception_if_uplink_not_present() const
{
    if (!this->presentUplink)
    {
        throw std::invalid_argument("No value for uplink");
    }
}

void Integrity_protection_maximum_data_rate::setDownlink(Integrity_protection_maximum_data_rate::Value value)
{
    this->presentDownlink = true;
    this->present = this->presentUplink && this->presentDownlink;
    this->downlink = value;
}

Integrity_protection_maximum_data_rate::Value Integrity_protection_maximum_data_rate::getDownlink() const
{
    this->raise_exception_if_downlink_not_present();
    return this->downlink;
}

void Integrity_protection_maximum_data_rate::raise_exception_if_downlink_not_present() const
{
    if (!this->presentDownlink)
    {
        throw std::invalid_argument("No value for downlink");
    }
}

int Integrity_protection_maximum_data_rate::code_V_ex(std::vector<uint8_t> &data) const
{
    this->raise_exception_if_not_present();
    data.push_back(static_cast<uint8_t>(this->uplink));
    data.push_back(static_cast<uint8_t>(this->downlink));
    return 2;
}

Integrity_protection_maximum_data_rate::Value Integrity_protection_maximum_data_rate::fromUint8_t(uint8_t v)
{
    switch (v)
    {
    case static_cast<uint8_t>(Value::Full_data_rate):
        return Value::Full_data_rate;
    }
    return Value::_64_kbps;
}

int Integrity_protection_maximum_data_rate::decode_V_ex(const std::vector<uint8_t> &data)
{
    if (data.size() < 2)
    {
        throw std::runtime_error("No data to decode");
    }
    this->uplink = fromUint8_t(data[0]);
    this->downlink = fromUint8_t(data[1]);

    this->present = true;
    this->presentUplink = true;
    this->presentDownlink = true;
    return 2;
}

} // namespace IE
} // namespace _5GS