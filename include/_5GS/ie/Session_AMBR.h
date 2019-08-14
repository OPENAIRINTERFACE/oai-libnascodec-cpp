#pragma once

#include <iostream>
#include <vector>
#include <information_element.h>
#include <_5GS/ie/Unit_for_Session_AMBR.h>

namespace _5GS
{

namespace IE
{

class Session_AMBR_Fields
{
public:
    Unit_for_Session_AMBR m_downlink_unit;
    uint16_t m_downlink;
    Unit_for_Session_AMBR m_uplink_unit;
    uint16_t m_uplink;

    Session_AMBR_Fields() = default;
    Session_AMBR_Fields(Unit_for_Session_AMBR downlink_unit,
                        uint16_t downlink,
                        Unit_for_Session_AMBR uplink_unit,
                        uint16_t uplink);

    bool operator==(const Session_AMBR_Fields &other) const;

};

class Session_AMBR : public InformationElement
{

public:
    // TS 24.501- 9.11.4.14

    Session_AMBR() = default;
    explicit Session_AMBR(const Session_AMBR_Fields &value);

    void set(const Session_AMBR_Fields &value);
    Session_AMBR_Fields get() const;

    virtual std::string getName() const;
    virtual std::string valueToString() const;

    static std::string value_to_string(const Session_AMBR_Fields value);
    static Session_AMBR_Fields uint8_t_to_Value(const uint8_t &byte);

protected:
    int code_LV(std::vector<uint8_t> &data) const;
    int decode_LV(const std::vector<uint8_t> &data);

private:
    Session_AMBR_Fields m_value;
};

} // namespace IE

} // namespace _5GS
