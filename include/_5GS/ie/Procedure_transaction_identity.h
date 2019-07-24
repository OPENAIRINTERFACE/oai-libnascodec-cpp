#pragma once

#include <iostream>
#include <vector>
#include <information_element.h>

namespace _5GS
{

namespace IE
{

class Procedure_transaction_identity : public InformationElement
{
public:
    // TS 24.007 - 11.2.3.1a
    enum class Value : uint8_t
    {
        No_procedure_transaction_identity_assigned = 0,
        // All value authorized
        Reserved = 255
    };
        
    void set(uint8_t value);
    uint8_t get() const;

    int code_V_ex(std::vector<uint8_t> & data) const;
    int decode_V_ex(const std::vector<uint8_t> & data);

private:
    uint8_t value;

};

} // namespace IE

} // namespace _5GS
