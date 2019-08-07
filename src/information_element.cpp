#include <vector>
#include <stdexcept>
#include <information_element.h>

bool InformationElement::isSet() const
{
    return this->present;
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
        return this->code_T(data, iei);
    case InformationElement::Format::V:
        return this->code_V(data);
    case InformationElement::Format::TV:
        return this->code_TV(data, iei);
    case InformationElement::Format::LV:
        return this->code_LV(data);
    case InformationElement::Format::TLV:
        return this->code_TLV(data, iei);
    case InformationElement::Format::LV_E:
        return this->code_LV_E(data);
    case InformationElement::Format::TLV_E:
        return this->code_TLV_E(data, iei);
    }
    throw std::runtime_error("Not implemented format");
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
        return this->decode_T(data, iei);
    case InformationElement::Format::V:
        return this->decode_V(data);
    case InformationElement::Format::TV:
        return this->decode_TV(data, iei);
    case InformationElement::Format::LV:
        return this->decode_LV(data);
    case InformationElement::Format::TLV:
        return this->decode_TLV(data, iei);
    case InformationElement::Format::LV_E:
        return this->decode_LV_E(data);
    case InformationElement::Format::TLV_E:
        return this->decode_TLV_E(data, iei);
    }
    throw std::runtime_error(std::string("Format not implemented: ") + std::string(__PRETTY_FUNCTION__));
    return -1;
};

int InformationElement::code_T(std::vector<uint8_t> &data, const uint8_t iei) const
{
    throw std::runtime_error(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::code_V(std::vector<uint8_t> &data) const
{
    throw std::runtime_error(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::code_TV(std::vector<uint8_t> &data, const uint8_t iei) const
{
    throw std::runtime_error(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::code_LV(std::vector<uint8_t> &data) const
{
    throw std::runtime_error(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::code_TLV(std::vector<uint8_t> &data, const uint8_t iei) const
{
    throw std::runtime_error(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::code_LV_E(std::vector<uint8_t> &data) const
{
    throw std::runtime_error(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::code_TLV_E(std::vector<uint8_t> &data, const uint8_t iei) const
{
    throw std::runtime_error(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}


int InformationElement::decode_T(const std::vector<uint8_t> &data, const uint8_t iei)
{
    throw std::runtime_error("Not implemented");
}

int InformationElement::decode_V(const std::vector<uint8_t> &data)
{
    throw std::runtime_error("Not implemented");
}

int InformationElement::decode_TV(const std::vector<uint8_t> &data, const uint8_t iei)
{
    throw std::runtime_error(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::decode_LV(const std::vector<uint8_t> &data)
{
    throw std::runtime_error(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::decode_TLV(const std::vector<uint8_t> &data, const uint8_t iei)
{
    throw std::runtime_error(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::decode_LV_E(const std::vector<uint8_t> &data)
{
    throw std::runtime_error(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::decode_TLV_E(const std::vector<uint8_t> &data, const uint8_t iei)
{
    throw std::runtime_error(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

void InformationElement::raise_exception_if_not_present(const std::string &name) const
{
    if (!this->present)
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
        throw std::runtime_error("IEI can't be 0 for T* types\n");
    default:
        return;
    }
}
