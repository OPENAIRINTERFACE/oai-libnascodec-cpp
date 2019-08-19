#pragma once

#include <iostream>
#include <vector>
#include <information_element.h>

namespace _5GS
{

namespace IE
{

class Unit_for_Session_AMBR : public InformationElement
{

public:
    // TS 24.501- 9.11.4.14

    enum class Value : uint8_t
    {
        value_is_not_used,
        value_is_incremented_in_multiple_of_1_Kbps,
        value_is_incremented_in_multiple_of_4_Kbps,
        value_is_incremented_in_multiple_of_16_Kbps,
        value_is_incremented_in_multiple_of_64_Kbps,
        value_is_incremented_in_multiple_of_256_Kbps,
        value_is_incremented_in_multiple_of_1_Mbps,
        value_is_incremented_in_multiple_of_4_Mbps,
        value_is_incremented_in_multiple_of_16_Mbps,
        value_is_incremented_in_multiple_of_64_Mbps,
        value_is_incremented_in_multiple_of_256_Mbps,
        value_is_incremented_in_multiple_of_1_Gbps,
        value_is_incremented_in_multiple_of_4_Gbps,
        value_is_incremented_in_multiple_of_16_Gbps,
        value_is_incremented_in_multiple_of_64_Gbps,
        value_is_incremented_in_multiple_of_256_Gbps,
        value_is_incremented_in_multiple_of_1_Tbps,
        value_is_incremented_in_multiple_of_4_Tbps,
        value_is_incremented_in_multiple_of_16_Tbps,
        value_is_incremented_in_multiple_of_64_Tbps,
        value_is_incremented_in_multiple_of_256_Tbps,
        value_is_incremented_in_multiple_of_1_Pbps,
        value_is_incremented_in_multiple_of_4_Pbps,
        value_is_incremented_in_multiple_of_16_Pbps,
        value_is_incremented_in_multiple_of_64_Pbps,
        value_is_incremented_in_multiple_of_256_Pbps,
        // Other values shall be interpreted as multiples of 256 Pbps in this version of the protocol.

    };

    Unit_for_Session_AMBR() = default;
    explicit Unit_for_Session_AMBR(const Value value);

    bool operator==(const Unit_for_Session_AMBR &other) const;
    bool operator!=(const Unit_for_Session_AMBR &other) const;

    void set(const Value value);
    Value get() const;

    virtual std::string getName() const;
    virtual std::string valueToString() const;

    static std::string value_to_string(const Value value);
    static Value uint8_t_to_Value(const uint8_t &byte);

protected:
    int code_V(std::vector<uint8_t> &data) const;
    int decode_V(const std::vector<uint8_t> &data);

private:
    Value m_value;
};

} // namespace IE

} // namespace _5GS
