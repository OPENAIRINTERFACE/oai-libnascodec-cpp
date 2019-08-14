#pragma once

#include <iostream>
#include <vector>
#include <information_element.h>

#include <_5GS/ie/String.h>

namespace _5GS
{

namespace IE
{

class DNN : public IE::String
{
    // TS 24.501 9.11.2.1A

public:
    DNN() = default;
    explicit DNN(const std::string &value);

    virtual std::string getName() const;
};

} // namespace IE

} // namespace _5GS
