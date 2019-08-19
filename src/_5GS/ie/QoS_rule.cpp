#include <_5GS/ie/QoS_rule.h>
#include <buffers.h>

namespace _5GS
{
namespace IE
{

// class QoS_rule

QoS_rule::QoS_rule(const DQR_bit dqr, const Rule_operation_code operation) : m_dqr_bit(dqr),
                                                                 m_operation(operation)
{
    m_present = true;
}

void QoS_rule::set(int dummy)
{
    throw NasCodecException(std::string(__PRETTY_FUNCTION__) + " not implemented");
    m_present = true;
}

int QoS_rule::get() const
{
    raise_exception_if_not_present(className(this));
    throw NasCodecException(std::string(__PRETTY_FUNCTION__) + " not implemented");
    return 0;
}

int QoS_rule::code_V(std::vector<uint8_t> &data) const
{
    int size = 0;
    raise_exception_if_not_present(className(this));
    // put dummy size (hex bad0) to reserve space
    data.push_back(0xba);
    data.push_back(0xd0);

    // fix total size
    data[0] = size & 0x00ff;
    data[1] = size & 0xff00 >> 8;
    return size;
}

int QoS_rule::decode_V(const std::vector<uint8_t> &data)
{
    int size = 0;
    throw NasCodecException(std::string(__PRETTY_FUNCTION__) + " not implemented");
    m_present = true;
    return size;
}

std::string QoS_rule::getName() const
{
    return "QoS rules";
}

std::string QoS_rule::valueToString() const
{
    if (not isSet())
    {
        return std::string("-");
    }
    return "Not implemented";
}

}; // namespace IE
}; // namespace _5GS
