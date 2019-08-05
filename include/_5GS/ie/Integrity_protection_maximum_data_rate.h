#pragma once

#include <iostream>
#include <vector>
#include <information_element.h>

namespace _5GS
{

namespace IE
{

class Integrity_protection_maximum_data_rate : public InformationElement
{
public:
    // TS 24.501 - 9.11.4.7

    static const std::string name;

    enum class Value : uint8_t
    {
        _64_kbps,
        Full_data_rate = 255
    };

    Integrity_protection_maximum_data_rate();
    Integrity_protection_maximum_data_rate(Value uplink, Value downlink);

    void setUplink(Value value);
    Value getUplink() const;

    void setDownlink(Value value);
    Value getDownlink() const;

    int code_V_ex(std::vector<uint8_t> &data) const;
    int decode_V_ex(const std::vector<uint8_t> &data);

    static Value fromUint8_t(uint8_t v);

    std::string to_string() const;
    static std::string value_to_string(const Value value);

private:
    // FIXME dry - make class helper for uplink downlink ?
    Value uplink, downlink;
    bool presentUplink = false;
    bool presentDownlink = false;
    void raise_exception_if_uplink_not_present() const;
    void raise_exception_if_downlink_not_present() const;
};

} // namespace IE

} // namespace _5GS
