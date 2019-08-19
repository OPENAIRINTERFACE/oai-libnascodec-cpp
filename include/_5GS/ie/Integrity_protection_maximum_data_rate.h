#pragma once

#include <iostream>
#include <vector>
#include <information_element.h>
#include <_5GS/ie/Maximum_data_rate_per_UE_for_user_plane.h>

namespace _5GS
{

namespace IE
{

class Integrity_protection_maximum_data_rate : public InformationElement
{
public:
    // TS 24.501 - 9.11.4.7

    class Value
    {
    public:
        explicit Value() = default;
        explicit Value(const Maximum_data_rate_per_UE_for_user_plane &uplink, const Maximum_data_rate_per_UE_for_user_plane &downlink);

        Maximum_data_rate_per_UE_for_user_plane m_uplink;
        Maximum_data_rate_per_UE_for_user_plane m_downlink;
    };

    explicit Integrity_protection_maximum_data_rate() = default;
    explicit Integrity_protection_maximum_data_rate(const Value &fields);

    Value get() const;

    int code_V(std::vector<uint8_t> &data) const;
    int decode_V(const std::vector<uint8_t> &data);

    static std::string value_to_string(const Value value);
    virtual std::string valueToString() const;
    virtual std::string getName() const;

    virtual bool isSet() const;

    Value m_fields;
};

} // namespace IE

} // namespace _5GS

bool operator==(const _5GS::IE::Integrity_protection_maximum_data_rate::Value &a,
                const _5GS::IE::Integrity_protection_maximum_data_rate::Value &b);
