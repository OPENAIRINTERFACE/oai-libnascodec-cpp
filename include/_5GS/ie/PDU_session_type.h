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

    static const std::string name;

    enum class Value : uint8_t
    {
        IPv4 = 1,
        IPv6,
        IPv4v6,
        Unstructured,
        Ethernet,
        reserved = 7
    };

    PDU_session_type();
    PDU_session_type(Value value);

    void set(Value id);
    Value get() const;

    std::string to_string() const;

    static std::string value_to_string(const Value value);

private:
    static const uint8_t identifier = 0x90; // half octet for iei
    Value value;

    int code_TV_ex(std::vector<uint8_t> &data) const;
    int decode_TV_ex(const std::vector<uint8_t> &data);
};

} // namespace IE

} // namespace _5GS
