#pragma once

#include <iostream>
#include <vector>
#include <information_element.h>

namespace _5GS
{

namespace IE
{

class QoS_rule : public InformationElement
{

public:
    // TS 24.501- 9.11.4.13

    // FIXME QoS rules is a complex structure - not much is implemented
    // broke into more classes

    enum class Rule_operation_code : uint8_t
    {
        Reserved0,
        Create_new_QoS_rule,
        Delete_existing_QoS_rule,
        Modify_existing_QoS_rule_and_add_packet_filters,
        Modify_existing_QoS_rule_and_replace_all_packet_filters,
        Modify_existing_QoS_rule_and_delete_packet_filters,
        Modify_existing_QoS_rule_without_modifying_packet_filters,
        Reserved7
    };

    enum class DQR_bit : bool
    {
        the_QoS_rule_is_not_the_default_QoS_rule,
        the_QoS_rule_is_the_default_QoS_rule
    };

    QoS_rule() = default;
    explicit QoS_rule(const DQR_bit dqr, const Rule_operation_code operation);

    void set(const int value); // FIXME
    int get() const; // FIXME

    virtual std::string getName() const;
    virtual std::string valueToString() const;

protected:
    int code_V(std::vector<uint8_t> &data) const;
    int decode_V(const std::vector<uint8_t> &data); // FIXME;

private:
    DQR_bit m_dqr_bit;
    Rule_operation_code m_operation;
};

} // namespace IE

} // namespace _5GS
