#pragma once

#include <iostream>
#include <vector>
#include <information_element.h>

namespace _5GS
{

namespace IE
{

class PDU_session_type : public InformationElement
{

public:
    // TS 24.501- 9.11.4.11

    enum class Value : uint8_t
    {
        IPv4 = 1,
        IPv6,
        IPv4v6,
        Unstructured,
        Ethernet,
        reserved = 7
    };

    PDU_session_type() = default;
    explicit PDU_session_type(const Value value);

    void set(Value id);
    Value get() const;

    virtual std::string getName() const;
    virtual std::string valueToString() const;

    static std::string value_to_string(const Value value);
    static Value uint8_t_to_Value(const uint8_t &byte);

    virtual uint8_t code_half_V() const;

protected:
    int code_V(std::vector<uint8_t> &data) const;
    int decode_V(const std::vector<uint8_t> &data); // FIXME;
    int code_TV(std::vector<uint8_t> &data, const uint8_t iei) const;
    int decode_TV(const std::vector<uint8_t> &data, const uint8_t iei);

private:
    Value m_value;
};

} // namespace IE

} // namespace _5GS
