#include <vector>
#include <stdexcept>
#include <information_element.h>

bool InformationElement::isSet() const
{
    return m_present;
}

int InformationElement::code(std::vector<uint8_t> &data, const InformationElement::Format format, const uint8_t iei) const
{
    if (iei == 0)
    {
        raise_exception_for_format_with_T(format);
    }

    switch (format)
    {
    case InformationElement::Format::T:
        return code_T(data, iei);
    case InformationElement::Format::V:
        return code_V(data);
    case InformationElement::Format::TV:
        return code_TV(data, iei);
    case InformationElement::Format::LV:
        return code_LV(data);
    case InformationElement::Format::TLV:
        return code_TLV(data, iei);
    case InformationElement::Format::LV_E:
        return code_LV_E(data);
    case InformationElement::Format::TLV_E:
        return code_TLV_E(data, iei);
    }
    throw NasCodecException("Not implemented format");
    return -1;
};

int InformationElement::decode(const std::vector<uint8_t> &data, const InformationElement::Format format, const uint8_t iei)
{
    if (iei == 0)
    {
        raise_exception_for_format_with_T(format);
    }

    switch (format)
    {
    case InformationElement::Format::T:
        return decode_T(data, iei);
    case InformationElement::Format::V:
        return decode_V(data);
    case InformationElement::Format::TV:
        return decode_TV(data, iei);
    case InformationElement::Format::LV:
        return decode_LV(data);
    case InformationElement::Format::TLV:
        return decode_TLV(data, iei);
    case InformationElement::Format::LV_E:
        return decode_LV_E(data);
    case InformationElement::Format::TLV_E:
        return decode_TLV_E(data, iei);
    }
    throw NasCodecException(std::string("Format not implemented: ") + std::string(__PRETTY_FUNCTION__));
    return -1;
};

uint8_t InformationElement::code_half_V() const
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::code_T(std::vector<uint8_t> &data, const uint8_t iei) const
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::code_V(std::vector<uint8_t> &data) const
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::code_TV(std::vector<uint8_t> &data, const uint8_t iei) const
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::code_LV(std::vector<uint8_t> &data) const
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::code_TLV(std::vector<uint8_t> &data, const uint8_t iei) const
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::code_LV_E(std::vector<uint8_t> &data) const
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::code_TLV_E(std::vector<uint8_t> &data, const uint8_t iei) const
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::decode_T(const std::vector<uint8_t> &data, const uint8_t iei)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::decode_V(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::decode_TV(const std::vector<uint8_t> &data, const uint8_t iei)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::decode_LV(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::decode_TLV(const std::vector<uint8_t> &data, const uint8_t iei)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::decode_LV_E(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::decode_TLV_E(const std::vector<uint8_t> &data, const uint8_t iei)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

void InformationElement::raise_exception_if_not_present(const std::string &name) const
{
    if (!m_present)
    {
        throw std::invalid_argument(std::string("No value for IE InformationElement ") + name);
    }
}

void InformationElement::raise_exception_for_format_with_T(const InformationElement::Format format) const
{
    switch (format)
    {
    case InformationElement::Format::T:
    case InformationElement::Format::TV:
    case InformationElement::Format::TLV:
    case InformationElement::Format::TLV_E:
        throw NasCodecException("IEI can't be 0 for T* types\n");
    default:
        return;
    }
}

std::string InformationElement::getName() const
{
    throw NasCodecException("getName not implemented");
}

std::string InformationElement::valueToString() const
{
    throw NasCodecException("valueToString Not implemented");
}

std::string InformationElement::to_string() const
{
    return getName() + "=" + valueToString();
}
