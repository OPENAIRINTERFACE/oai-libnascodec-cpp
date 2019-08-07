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

    static const std::string name;

    enum class Value : uint8_t
    {
        No_procedure_transaction_identity_assigned = 0,
        // All value authorized
        Reserved = 255
    };

    Procedure_transaction_identity();
    Procedure_transaction_identity(const Value value);
    Procedure_transaction_identity(const uint8_t value);

    void set(const uint8_t value);
    uint8_t get() const;

    int code_V(std::vector<uint8_t> &data) const;
    int decode_V(const std::vector<uint8_t> &data);
    int decode_V(const uint8_t &byte);

    std::string to_string() const;
    static std::string value_to_string(const uint8_t value);
    static Value uint8_t_to_Value(const uint8_t &byte);

private:
    uint8_t m_value;
};

} // namespace IE

} // namespace _5GS
