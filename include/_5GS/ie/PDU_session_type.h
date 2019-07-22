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
    enum class Value
    {
        IPv4 = 1,
        IPv6,
        IPv4v6,
        Unstructured, 
        Ethernet,
        reserved = 7,

    };

private:
    const uint8_t iei = 0x90; // half octet for iei
    bool present = false;
    Value value;

public:

    void set(Value id);
    Value get() const;

    std::vector<uint8_t> code_TV() const;
    //std::vector<uint8_t> decode_TV(std::vector<uint8_t> &data);

};

} // namespace IE

} // namespace _5GS
