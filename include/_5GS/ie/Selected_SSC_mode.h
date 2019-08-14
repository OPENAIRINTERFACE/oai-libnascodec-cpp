#pragma once

#include <iostream>
#include <vector>
#include <information_element.h>

#include <_5GS/ie/SSC_mode.h>

namespace _5GS
{

namespace IE
{

class Selected_SSC_mode : public SSC_mode
{

public:
    Selected_SSC_mode() = default;
    explicit Selected_SSC_mode(const SSC_mode::Value value);

    virtual std::string getName() const;
};

} // namespace IE

} // namespace _5GS
