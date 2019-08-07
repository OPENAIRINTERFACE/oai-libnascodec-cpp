#include <vector>
#include <stdexcept>
#include <information_element.h>

bool InformationElement::isSet() const
{
    return this->present;
}

int InformationElement::code(std::vector<uint8_t> &data, const InformationElement::Format format) const
{
    try
    {
        return code_ex(data, format);
    }
    catch (const std::exception &exception)
    {
        return -1;
    }
    return -1;
}

int InformationElement::code_ex(std::vector<uint8_t> &data, const InformationElement::Format format) const
{
    switch (format)
    {
    case InformationElement::Format::T:
        return this->code_T_ex(data);
    case InformationElement::Format::V:
        return this->code_V_ex(data);
    case InformationElement::Format::TV:
        return this->code_TV_ex(data);
    case InformationElement::Format::LV:
        return this->code_LV_ex(data);
    case InformationElement::Format::TLV:
        return this->code_TLV_ex(data);
    case InformationElement::Format::LV_E:
        return this->code_LV_E_ex(data);
    case InformationElement::Format::TLV_E:
        return this->code_TLV_E_ex(data);
    }
    throw std::runtime_error("Not implemented format");
    return -1;
};

int InformationElement::decode(const std::vector<uint8_t> &data, const InformationElement::Format format)
{
    try
    {
        return decode_ex(data, format);
    }
    catch (const std::exception &exception)
    {
        return -1;
    }
    return -1;
}

int InformationElement::decode_ex(const std::vector<uint8_t> &data, const InformationElement::Format format)
{
    switch (format)
    {
    case InformationElement::Format::T:
        return this->decode_T_ex(data);
    case InformationElement::Format::V:
        return this->decode_V_ex(data);
    case InformationElement::Format::TV:
        return this->decode_TV_ex(data);
    case InformationElement::Format::LV:
        return this->decode_LV_ex(data);
    case InformationElement::Format::TLV:
        return this->decode_TLV_ex(data);
    case InformationElement::Format::LV_E:
        return this->decode_LV_E_ex(data);
    case InformationElement::Format::TLV_E:
        return this->decode_TLV_E_ex(data);
    }
    throw std::runtime_error(std::string("Format not implemented: ") + std::string(__PRETTY_FUNCTION__));
    return -1;
};

int InformationElement::code_T_ex(std::vector<uint8_t> &data) const
{
    throw std::runtime_error(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::code_V_ex(std::vector<uint8_t> &data) const
{
    throw std::runtime_error(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::code_TV_ex(std::vector<uint8_t> &data) const
{
    throw std::runtime_error(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::code_LV_ex(std::vector<uint8_t> &data) const
{
    throw std::runtime_error(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::code_TLV_ex(std::vector<uint8_t> &data) const
{
    throw std::runtime_error(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::code_LV_E_ex(std::vector<uint8_t> &data) const
{
    throw std::runtime_error(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::code_TLV_E_ex(std::vector<uint8_t> &data) const
{
    throw std::runtime_error(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::code_T(std::vector<uint8_t> &data) const
{
    try
    {
        code_T_ex(data);
    }
    catch (const std::exception &exception)
    {
        return -1;
    }
    return 0;
}

int InformationElement::code_V(std::vector<uint8_t> &data) const
{
    try
    {
        code_T_ex(data);
    }
    catch (const std::exception &exception)
    {
        return -1;
    }
    return 0;
}

int InformationElement::code_TV(std::vector<uint8_t> &data) const
{
    try
    {
        code_T_ex(data);
    }
    catch (const std::exception &exception)
    {
        return -1;
    }
    return 0;
}

int InformationElement::code_LV(std::vector<uint8_t> &data) const
{
    try
    {
        code_T_ex(data);
    }
    catch (const std::exception &exception)
    {
        return -1;
    }
    return 0;
}

int InformationElement::code_TLV(std::vector<uint8_t> &data) const
{
    try
    {
        code_T_ex(data);
    }
    catch (const std::exception &exception)
    {
        return -1;
    }
    return 0;
}

int InformationElement::code_LV_E(std::vector<uint8_t> &data) const
{
    try
    {
        code_T_ex(data);
    }
    catch (const std::exception &exception)
    {
        return -1;
    }
    return 0;
}

int InformationElement::code_TLV_E(std::vector<uint8_t> &data) const
{
    try
    {
        code_T_ex(data);
    }
    catch (const std::exception &exception)
    {
        return -1;
    }
    return 0;
}

int InformationElement::decode_T_ex(const std::vector<uint8_t> &data)
{
    throw std::runtime_error("Not implemented");
}

int InformationElement::decode_V_ex(const std::vector<uint8_t> &data)
{
    throw std::runtime_error("Not implemented");
}

int InformationElement::decode_TV_ex(const std::vector<uint8_t> &data)
{
    throw std::runtime_error(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::decode_LV_ex(const std::vector<uint8_t> &data)
{
    throw std::runtime_error(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::decode_TLV_ex(const std::vector<uint8_t> &data)
{
    throw std::runtime_error(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::decode_LV_E_ex(const std::vector<uint8_t> &data)
{
    throw std::runtime_error(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::decode_TLV_E_ex(const std::vector<uint8_t> &data)
{
    throw std::runtime_error(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

int InformationElement::decode_T(const std::vector<uint8_t> &data)
{
    try
    {
        decode_T_ex(data);
    }
    catch (const std::exception &exception)
    {
        return -1;
    }
    return 0;
}

int InformationElement::decode_V(const std::vector<uint8_t> &data)
{
    try
    {
        decode_T_ex(data);
    }
    catch (const std::exception &exception)
    {
        return -1;
    }
    return 0;
}

int InformationElement::decode_TV(const std::vector<uint8_t> &data)
{
    try
    {
        decode_T_ex(data);
    }
    catch (const std::exception &exception)
    {
        return -1;
    }
    return 0;
}

int InformationElement::decode_LV(const std::vector<uint8_t> &data)
{
    try
    {
        decode_T_ex(data);
    }
    catch (const std::exception &exception)
    {
        return -1;
    }
    return 0;
}

int InformationElement::decode_TLV(const std::vector<uint8_t> &data)
{
    try
    {
        decode_T_ex(data);
    }
    catch (const std::exception &exception)
    {
        return -1;
    }
    return 0;
}

int InformationElement::decode_LV_E(const std::vector<uint8_t> &data)
{
    try
    {
        decode_T_ex(data);
    }
    catch (const std::exception &exception)
    {
        return -1;
    }
    return 0;
}

int InformationElement::decode_TLV_E(const std::vector<uint8_t> &data)
{
    try
    {
        decode_T_ex(data);
    }
    catch (const std::exception &exception)
    {
        return -1;
    }
    return 0;
}

void InformationElement::raise_exception_if_not_present(const std::string name) const
{
    if (!this->present)
    {
        throw std::invalid_argument(std::string("No value for IE InformationElement ") + name);
    }
}

