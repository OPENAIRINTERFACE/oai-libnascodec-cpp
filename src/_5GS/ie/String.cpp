#include <_5GS/ie/String.h>
#include <buffers.h>

namespace _5GS
{
namespace IE
{

String::String(const std::string &value)
{
    set(value);
}

void String::set(const std::string &value)
{
    m_present = true;
    m_value = value;
}

std::string String::get() const
{
    raise_exception_if_not_present(className(this));
    return m_value;
}

int String::code_TLV(std::vector<uint8_t> &data, const uint8_t iei) const
{
    raise_exception_if_not_present(className(this));
    data.push_back(iei);
    // FIXME check size overflow
    data.push_back(m_value.size());
    std::move(m_value.begin(), m_value.end(), std::back_inserter(data));
    return 1 + 1 + m_value.size(); /* T + L + V sizes */
}

int String::decode_TLV(const std::vector<uint8_t> &data, const uint8_t iei)
{
    if ( data[0] != iei) {
            throw NasCodecException(std::string("Invalid iei for ") + std::string(__PRETTY_FUNCTION__));
    }
    int size = data[1];
    m_value.clear();
    for (int index = 2 ; index < 2 + size ; index ++) {
        m_value += data[index];
    }
    m_present = true;
    return size + 2;
}

std::string String::getName() const
{
    return "String";
}

std::string String::valueToString() const
{
    if (not isSet())
    {
        return std::string("-");
    }
    return m_value;
}

}; // namespace IE
}; // namespace _5GS
