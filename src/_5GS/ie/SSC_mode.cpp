#include <_5GS/ie/SSC_mode.h>
#include <buffers.h>

namespace _5GS
{
namespace IE
{

std::string SSC_mode::getName() const
{
    return "SSC mode";
}

// Constructors

SSC_mode::SSC_mode(Value value)
{
    set(value);
}

void SSC_mode::set(SSC_mode::Value value)
{
    m_present = true;
    m_value = value;
}

// getters & setters

SSC_mode::Value SSC_mode::get() const
{
    raise_exception_if_not_present(className(this));
    return m_value;
}

// V coders and decoders

uint8_t SSC_mode::code_half_V() const
{
    return static_cast<uint8_t>(m_value);
}

int SSC_mode::code_V(std::vector<uint8_t> &data) const
{
    raise_exception_if_not_present(className(this));
    data.push_back(static_cast<uint8_t>(m_value));
    return 1;
}

int SSC_mode::decode_V(const std::vector<uint8_t> &data)
{
    m_value = uint8_t_to_Value(data[0]);
    m_present = true;
    return 1;
}

// TV coders and decoders

int SSC_mode::code_TV(std::vector<uint8_t> &data, const uint8_t iei) const
{
    raise_exception_if_not_present(className(this));

    uint8_t c, v;
    v = static_cast<uint8_t>(m_value);
    c = (iei & 0xf0) | v;
    data.push_back(c);
    return 1;
}

int SSC_mode::decode_TV(const std::vector<uint8_t> &data, const uint8_t iei)
{
    uint8_t v;

    if (data.size() == 0)
    {
        throw NasCodecException(
            std::string("No data to decode") +
            std::string(__PRETTY_FUNCTION__));
    }

    if ((iei & 0x0f) != 0)
    {
        throw NasCodecException(
            std::string("Invalid IEI") +
            std::string(__PRETTY_FUNCTION__));
    }

    v = data[0] & 0x0f;

    if ((data[0] & 0xf0) != iei)
    {
        throw NasCodecException(std::string(__PRETTY_FUNCTION__) + std::string("invalide iei"));
    }

    try
    {
        m_value = uint8_t_to_Value(v);
    }
    catch (NasCodecException)
    {
        throw NasCodecException(
            std::string(__PRETTY_FUNCTION__) +
            std::string(" Invalid data:\n") +
            dump_wireshark(data));
    }

    m_present = true;
    return 1;
}

// Converter functions

SSC_mode::Value SSC_mode::uint8_t_to_Value(const uint8_t &byte)
{
    switch (byte)
    {
    case static_cast<uint8_t>(SSC_mode::Value::SSC_mode_1):
        return SSC_mode::Value::SSC_mode_1;
    case static_cast<uint8_t>(SSC_mode::Value::SSC_mode_2):
        return SSC_mode::Value::SSC_mode_2;
    case static_cast<uint8_t>(SSC_mode::Value::SSC_mode_3):
        return SSC_mode::Value::SSC_mode_3;
    case static_cast<uint8_t>(SSC_mode::Value::unused_1):
        return SSC_mode::Value::unused_1;
    case static_cast<uint8_t>(SSC_mode::Value::unused_2):
        return SSC_mode::Value::unused_2;
    case static_cast<uint8_t>(SSC_mode::Value::unused_3):
        return SSC_mode::Value::unused_3;
    }
    throw NasCodecException(
        std::string(__PRETTY_FUNCTION__) +
        std::string(" Invalid data:\n") + std::to_string(byte));
}

// Strings function

std::string SSC_mode::valueToString() const
{
    if (not isSet())
    {
        return "-";
    }
    return SSC_mode::value_to_string(m_value);
}

std::string SSC_mode::value_to_string(const SSC_mode::Value value)
{
    switch (value)
    {
    case SSC_mode::Value::SSC_mode_1:
        return "SSC mode 1";
    case SSC_mode::Value::SSC_mode_2:
        return "SSC mode 2";
    case SSC_mode::Value::SSC_mode_3:
        return "SSC mode 3";
    case SSC_mode::Value::unused_1:
        return "unused 1";
    case SSC_mode::Value::unused_2:
        return "unused 2";
    case SSC_mode::Value::unused_3:
        return "unused 3";
    }
    throw std::invalid_argument("Not a value");
}

} // namespace IE
} // namespace _5GS
