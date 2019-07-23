#include <vector>
#include <information_element.h>

bool InformationElement::isSet() const
{
    return this->present;
}

int InformationElement::code(std::vector<uint8_t> & data, InformationElement::Format format) const
{
    switch (format)
    {
    case InformationElement::Format::T:
        return this->code_T(data);
    case InformationElement::Format::V:
        return this->code_V(data);
    case InformationElement::Format::TV:
        return this->code_TV(data);
    case InformationElement::Format::LV:
        return this->code_LV(data);
    case InformationElement::Format::TLV:
        return this->code_TLV(data);
    case InformationElement::Format::LV_E:
        return this->code_LV_E(data);
    case InformationElement::Format::TLV_E:
        return this->code_TLV_E(data);
    }
    return -1;
};

int InformationElement::decode(InformationElement::Format format, std::vector<uint8_t> & data)
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
    return -1;
};

int InformationElement::code_T(std::vector<uint8_t> & data) const
{
    return -1;
}

int InformationElement::code_V(std::vector<uint8_t> & data) const
{
    return -1;
}

int InformationElement::code_TV(std::vector<uint8_t> & data) const
{
    return -1;
}

int InformationElement::code_LV(std::vector<uint8_t> & data) const
{
    return -1;
}

int InformationElement::code_TLV(std::vector<uint8_t> & data) const
{
    return -1;
}

int InformationElement::code_LV_E(std::vector<uint8_t> & data) const
{
    return -1;
}

int InformationElement::code_TLV_E(std::vector<uint8_t> & data) const
{
    return -1;
}

int InformationElement::decode_T(std::vector<uint8_t> & data)
{
    return -1;
}

int InformationElement::decode_V(std::vector<uint8_t> & data)
{
    return -1;
}

int InformationElement::decode_TV(std::vector<uint8_t> & data)
{
    return -1;
}

int InformationElement::decode_LV(std::vector<uint8_t> & data)
{
    return -1;
}

int InformationElement::decode_TLV(std::vector<uint8_t> & data)
{
    return -1;
}

int InformationElement::decode_LV_E(std::vector<uint8_t> & data)
{
    return -1;
}

int InformationElement::decode_TLV_E(std::vector<uint8_t> & data)
{
    return -1;
}
