#pragma once

#include <iostream>
#include <vector>
#include <information_element.h>

#include <_5GS/ie/String.h>

namespace _5GS
{

namespace IE
{

class SM_PDU_DN_request_container : public IE::String
{
    // TS 24.501 9.11.4.15

public:
    SM_PDU_DN_request_container() = default;
    explicit SM_PDU_DN_request_container(const std::string &value);

    virtual std::string getName() const;
};

} // namespace IE

} // namespace _5GS
