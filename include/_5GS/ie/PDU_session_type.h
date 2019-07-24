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

    void set(Value id);
    Value get() const;

private:
    static const uint8_t identifier = 0x90; // half octet for iei
    Value value;

    int code_TV_ex(std::vector<uint8_t> & data) const;
    int decode_TV_ex(const std::vector<uint8_t> & data);
};

} // namespace IE

} // namespace _5GS
