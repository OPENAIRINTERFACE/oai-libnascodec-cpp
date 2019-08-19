#pragma once

#include <iostream>
#include <vector>
#include <information_element.h>
#include <_5GS/ie/QoS_rule.h>

namespace _5GS
{

namespace IE
{

class QoS_rules : public InformationElement
{

public:
    // TS 24.501- 9.11.4.13

    // FIXME QoS rules is a complex structure - not much is implemented

    QoS_rules() = default;
    explicit QoS_rules(const std::vector<QoS_rule> &rules);

    void set(const std::vector<QoS_rule> &rules);
    const std::vector<QoS_rule> get() const;

    virtual std::string getName() const;
    virtual std::string valueToString() const;

protected:
    int code_LV_E(std::vector<uint8_t> &data) const;
    int decode_LV_E(const std::vector<uint8_t> &data);

private:
    std::vector<QoS_rule> m_rules;
};

} // namespace IE

} // namespace _5GS
