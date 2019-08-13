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

public:
    SM_PDU_DN_request_container();
    explicit SM_PDU_DN_request_container(const std::string &value);

    virtual std::string getName() const;
};

} // namespace IE

} // namespace _5GS
