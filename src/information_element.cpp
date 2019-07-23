#include <vector>
#include <information_element.h>

bool InformationElement::isSet() const
{
    return this->present;
}

std::vector<uint8_t> InformationElement::code(InformationElement::Format format) const
{
    // FIXME add doc for empty return value
    std::vector<uint8_t> data;

    switch (format)
    {
    case InformationElement::Format::T:
        return this->code_T();
    case InformationElement::Format::V:
        return this->code_V();
    case InformationElement::Format::TV:
        return this->code_TV();
    case InformationElement::Format::LV:
        return this->code_LV();
    case InformationElement::Format::TLV:
        return this->code_TLV();
    case InformationElement::Format::LV_E:
        return this->code_LV_E();
    case InformationElement::Format::TLV_E:
        return this->code_TLV_E();
    }
    return data;
};

std::vector<uint8_t> InformationElement::decode(InformationElement::Format format, std::vector<uint8_t> & data)
{
    switch (format)
    {
    case InformationElement::Format::T:
        return this->decode_T(data);
    case InformationElement::Format::V:
        return this->decode_V(data);
    case InformationElement::Format::TV:
        return this->decode_TV(data);
    case InformationElement::Format::LV:
        return this->decode_LV(data);
    case InformationElement::Format::TLV:
        return this->decode_TLV(data);
    case InformationElement::Format::LV_E:
        return this->decode_LV_E(data);
    case InformationElement::Format::TLV_E:
        return this->decode_TLV_E(data);
    }
    // FIXME
    return data;
};

std::vector<uint8_t> InformationElement::code_T() const
{
    std::vector<uint8_t> data;
    return data;
}

std::vector<uint8_t> InformationElement::code_V() const
{
    std::vector<uint8_t> data;
    return data;
}

std::vector<uint8_t> InformationElement::code_TV() const
{
    std::vector<uint8_t> data;
    return data;
}

std::vector<uint8_t> InformationElement::code_LV() const
{
    std::vector<uint8_t> data;
    return data;
}

std::vector<uint8_t> InformationElement::code_TLV() const

{
    std::vector<uint8_t> data;
    return data;
}

std::vector<uint8_t> InformationElement::code_LV_E() const
{
    std::vector<uint8_t> data;
    return data;
}

std::vector<uint8_t> InformationElement::code_TLV_E() const
{
    std::vector<uint8_t> data;
    return data;
}

std::vector<uint8_t> InformationElement::decode_T(std::vector<uint8_t> & data)
{
    return data;
}

std::vector<uint8_t> InformationElement::decode_V(std::vector<uint8_t> & data)
{
    return data;
}

std::vector<uint8_t> InformationElement::decode_TV(std::vector<uint8_t> & data)
{
    return data;
}

std::vector<uint8_t> InformationElement::decode_LV(std::vector<uint8_t> & data)
{
    return data;
}

std::vector<uint8_t> InformationElement::decode_TLV(std::vector<uint8_t> & data)
{
    return data;
}

std::vector<uint8_t> InformationElement::decode_LV_E(std::vector<uint8_t> & data)
{
    return data;
}

std::vector<uint8_t> InformationElement::decode_TLV_E(std::vector<uint8_t> & data)
{
    return data;
}

std::ostream & operator<<(std::ostream & output, std::vector<uint8_t> & data)
{
    for (const auto & el : data)
    {
        output << el;
    }
    return output;
}
