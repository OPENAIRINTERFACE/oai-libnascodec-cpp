#pragma once

#include <iostream>
#include <vector>
#include <information_element.h>

#include <_5GS/ie/PDU_session_type.h>

namespace _5GS
{

namespace IE
{

class Selected_PDU_session_type : public PDU_session_type
{

    // TS 24.501 9.11.4.11

public:
    Selected_PDU_session_type() = default;
    explicit Selected_PDU_session_type(const PDU_session_type::Value value);

    virtual std::string getName() const;
};

} // namespace IE

} // namespace _5GS
