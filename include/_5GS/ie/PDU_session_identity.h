#pragma once

#include <iostream>
#include <vector>
#include <information_element.h>

namespace _5GS
{

namespace IE
{

class PDU_session_identity : public InformationElement
{
public:
    // TS 24.007 - 11.2.3.1c.1
    enum class Value : uint8_t
    {
        No_PDU_session_identity_assigned,
        PDU_session_identity_value_1,
        PDU_session_identity_value_2,
        PDU_session_identity_value_3,
        PDU_session_identity_value_4,
        PDU_session_identity_value_5,
        PDU_session_identity_value_6,
        PDU_session_identity_value_7,
        PDU_session_identity_value_8,
        PDU_session_identity_value_9,
        PDU_session_identity_value_10,
        PDU_session_identity_value_11,
        PDU_session_identity_value_12,
        PDU_session_identity_value_13,
        PDU_session_identity_value_14,
        PDU_session_identity_value_15
    };

    void set(Value value);
    Value get() const;

    std::vector<uint8_t> code_V() const;
    //std::vector<uint8_t> decode_V(std::vector<uint8_t> & data);

private:
    Value value;

};

} // namespace IE

} // namespace _5GS
