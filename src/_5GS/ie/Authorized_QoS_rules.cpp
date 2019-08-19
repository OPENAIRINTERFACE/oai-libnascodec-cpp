#include <_5GS/ie/Authorized_QoS_rules.h>
#include <buffers.h>

namespace _5GS
{
namespace IE
{

std::string Authorized_QoS_rules::getName() const
{
    return "Authorized QoS rules";
}

Authorized_QoS_rules::Authorized_QoS_rules(const std::vector<QoS_rule> &rules) : QoS_rules(rules)
{
}

} // namespace IE
} // namespace _5GS
