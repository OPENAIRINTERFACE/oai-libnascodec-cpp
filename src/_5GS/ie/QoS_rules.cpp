#include <_5GS/ie/QoS_rules.h>
#include <buffers.h>

namespace _5GS
{
namespace IE
{

// class QoS_rules

QoS_rules::QoS_rules(const std::vector<QoS_rule> &rules)
{
    set(rules);
}

void QoS_rules::set(const std::vector<QoS_rule> &rules)
{
    m_present = true;
    m_rules = rules;
}

const std::vector<QoS_rule> QoS_rules::get() const
{
    raise_exception_if_not_present(className(this));
    return m_rules;
}

int QoS_rules::code_LV_E(std::vector<uint8_t> &data) const
{
    int size = 0;
    int offset_begin = data.size();
    raise_exception_if_not_present(className(this));
    // put dummy size (hex bad0) to reserve space
    data.push_back(0xba);
    data.push_back(0xd0);
    size = 2;
    // TODO add minimal QoS rule
    data.push_back(1);          // QoS rule identifier
    data.push_back(0);          // Length of QoS rules 2
    data.push_back(3);          // Length of QoS rules 1
    data.push_back(0b01010000); // Rule operation code + DQR + number of packet filter
    size += 5;
    // XXX fix total size size is number of QoS rules
    size = 1;
    data[offset_begin + 1] = size & 0x00ff;
    data[offset_begin + 0] = (size & 0xff00) >> 8;
    return size;
}

int QoS_rules::decode_LV_E(const std::vector<uint8_t> &data)
{
    int size = 0;
    throw NasCodecException(std::string(__PRETTY_FUNCTION__) + " not implemented");
    m_present = true;
    return size;
}

std::string QoS_rules::getName() const
{
    return "QoS rules";
}

std::string QoS_rules::valueToString() const
{
    if (not isSet())
    {
        return std::string("-");
    }
    return "Not implemented";
}

}; // namespace IE
}; // namespace _5GS
