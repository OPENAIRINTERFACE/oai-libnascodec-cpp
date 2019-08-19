#include <_5GS/ie/Unit_for_Session_AMBR.h>
#include <buffers.h>

namespace _5GS
{
namespace IE
{

std::string Unit_for_Session_AMBR::getName() const
{
    return "Unit for Session AMBR";
}

Unit_for_Session_AMBR::Unit_for_Session_AMBR(const Value value)
{
    set(value);
}

bool Unit_for_Session_AMBR::operator==(const Unit_for_Session_AMBR &other) const
{
    if (m_present != other.m_present)
    {
        return false;
    }
    if (m_value != other.m_value)
    {
        return false;
    }
    return true;
}

bool Unit_for_Session_AMBR::operator!=(const Unit_for_Session_AMBR &other) const {
    return !(*this == other);
  }

void Unit_for_Session_AMBR::set(const Value value)
{
    m_present = true;
    m_value = value;
}

Unit_for_Session_AMBR::Value Unit_for_Session_AMBR::get() const
{
    raise_exception_if_not_present(className(this));
    return m_value;
}

int Unit_for_Session_AMBR::code_V(std::vector<uint8_t> &data) const
{
    raise_exception_if_not_present(className(this));
    data.push_back(static_cast<uint8_t>(m_value));
    return 1;
}

int Unit_for_Session_AMBR::decode_V(const std::vector<uint8_t> &data)
{
    m_value = uint8_t_to_Value(data[0]);
    m_present = true;
    return 1;
}

Unit_for_Session_AMBR::Value Unit_for_Session_AMBR::uint8_t_to_Value(const uint8_t &byte)
{
    switch (byte)
    {
    case static_cast<uint8_t>(Unit_for_Session_AMBR::Value::value_is_not_used):
        return Unit_for_Session_AMBR::Value::value_is_not_used;
    case static_cast<uint8_t>(Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_1_Kbps):
        return Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_1_Kbps;
    case static_cast<uint8_t>(Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_4_Kbps):
        return Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_4_Kbps;
    case static_cast<uint8_t>(Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_16_Kbps):
        return Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_16_Kbps;
    case static_cast<uint8_t>(Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_64_Kbps):
        return Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_64_Kbps;
    case static_cast<uint8_t>(Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_256_Kbps):
        return Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_256_Kbps;
    case static_cast<uint8_t>(Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_1_Mbps):
        return Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_1_Mbps;
    case static_cast<uint8_t>(Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_4_Mbps):
        return Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_4_Mbps;
    case static_cast<uint8_t>(Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_16_Mbps):
        return Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_16_Mbps;
    case static_cast<uint8_t>(Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_64_Mbps):
        return Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_64_Mbps;
    case static_cast<uint8_t>(Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_256_Mbps):
        return Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_256_Mbps;
    case static_cast<uint8_t>(Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_1_Gbps):
        return Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_1_Gbps;
    case static_cast<uint8_t>(Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_4_Gbps):
        return Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_4_Gbps;
    case static_cast<uint8_t>(Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_16_Gbps):
        return Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_16_Gbps;
    case static_cast<uint8_t>(Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_64_Gbps):
        return Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_64_Gbps;
    case static_cast<uint8_t>(Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_256_Gbps):
        return Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_256_Gbps;
    case static_cast<uint8_t>(Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_1_Tbps):
        return Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_1_Tbps;
    case static_cast<uint8_t>(Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_4_Tbps):
        return Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_4_Tbps;
    case static_cast<uint8_t>(Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_16_Tbps):
        return Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_16_Tbps;
    case static_cast<uint8_t>(Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_64_Tbps):
        return Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_64_Tbps;
    case static_cast<uint8_t>(Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_256_Tbps):
        return Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_256_Tbps;
    case static_cast<uint8_t>(Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_1_Pbps):
        return Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_1_Pbps;
    case static_cast<uint8_t>(Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_4_Pbps):
        return Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_4_Pbps;
    case static_cast<uint8_t>(Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_16_Pbps):
        return Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_16_Pbps;
    case static_cast<uint8_t>(Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_64_Pbps):
        return Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_64_Pbps;
    case static_cast<uint8_t>(Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_256_Pbps):
    default: // Other values shall be interpreted as multiples of 256 Pbps in this version of the protocol.
        return Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_256_Pbps;
    }
    throw NasCodecException("Invalid value for PDU session type");
}

std::string Unit_for_Session_AMBR::valueToString() const
{
    if (not isSet())
    {
        return "-";
    }
    return Unit_for_Session_AMBR::value_to_string(m_value);
}

std::string Unit_for_Session_AMBR::value_to_string(const Unit_for_Session_AMBR::Value value)
{
    switch (value)
    {
    case Unit_for_Session_AMBR::Value::value_is_not_used:
        return "value is not used";
    case Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_1_Kbps:
        return "value is incremented in multiple of 1 Kbps";
    case Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_4_Kbps:
        return "value is incremented in multiple of 4 Kbps";
    case Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_16_Kbps:
        return "value is incremented in multiple of 16 Kbps";
    case Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_64_Kbps:
        return "value is incremented in multiple of 64 Kbps";
    case Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_256_Kbps:
        return "value is incremented in multiple of 256 Kbps";
    case Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_1_Mbps:
        return "value is incremented in multiple of 1 Mbps";
    case Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_4_Mbps:
        return "value is incremented in multiple of 4 Mbps";
    case Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_16_Mbps:
        return "value is incremented in multiple of 16 Mbps";
    case Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_64_Mbps:
        return "value is incremented in multiple of 64 Mbps";
    case Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_256_Mbps:
        return "value is incremented in multiple of 256 Mbps";
    case Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_1_Gbps:
        return "value is incremented in multiple of 1 Gbps";
    case Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_4_Gbps:
        return "value is incremented in multiple of 4 Gbps";
    case Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_16_Gbps:
        return "value is incremented in multiple of 16 Gbps";
    case Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_64_Gbps:
        return "value is incremented in multiple of 64 Gbps";
    case Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_256_Gbps:
        return "value is incremented in multiple of 256 Gbps";
    case Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_1_Tbps:
        return "value is incremented in multiple of 1 Tbps";
    case Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_4_Tbps:
        return "value is incremented in multiple of 4 Tbps";
    case Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_16_Tbps:
        return "value is incremented in multiple of 16 Tbps";
    case Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_64_Tbps:
        return "value is incremented in multiple of 64 Tbps";
    case Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_256_Tbps:
        return "value is incremented in multiple of 256 Tbps";
    case Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_1_Pbps:
        return "value is incremented in multiple of 1 Pbps";
    case Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_4_Pbps:
        return "value is incremented in multiple of 4 Pbps";
    case Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_16_Pbps:
        return "value is incremented in multiple of 16 Pbps";
    case Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_64_Pbps:
        return "value is incremented in multiple of 64 Pbps";
    case Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_256_Pbps:
        return "value is incremented in multiple of 256 Pbps";
    }
    throw std::invalid_argument("Not a value");
}

} // namespace IE
} // namespace _5GS
