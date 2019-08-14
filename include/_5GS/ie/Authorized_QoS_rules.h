#pragma once

#include <iostream>
#include <vector>
#include <information_element.h>

#include <_5GS/ie/QoS_rules.h>

namespace _5GS
{

namespace IE
{

class Authorized_QoS_rules : public IE::QoS_rules
{
    // TS 24.501 9.11.4.13

public:
    Authorized_QoS_rules() = default;
    explicit Authorized_QoS_rules(const std::vector<QoS_rule> &rules);

    virtual std::string getName() const;
};

} // namespace IE

} // namespace _5GS
