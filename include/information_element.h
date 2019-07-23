#pragma once

#include <vector>
#include <cstdint>

// TS 24.007 - chapter 11

class InformationElement
{

public:
    enum class Format
    {
        T,
        V,
        TV,
        LV,
        TLV,
        LV_E,
        TLV_E
    };

    bool isSet() const;

    virtual int code(std::vector<uint8_t> & data, InformationElement::Format format) const;
    virtual int decode(InformationElement::Format format, std::vector<uint8_t> &data);

protected:
    bool present = false; // set if ie is optional and found in a pdu

private:

    virtual int code_T(std::vector<uint8_t> &data) const;
    virtual int code_V(std::vector<uint8_t> &data) const;
    virtual int code_TV(std::vector<uint8_t> &data) const;
    virtual int code_LV(std::vector<uint8_t> &data) const;
    virtual int code_TLV(std::vector<uint8_t> &data) const;
    virtual int code_LV_E(std::vector<uint8_t> &data) const;
    virtual int code_TLV_E(std::vector<uint8_t> &data) const;

    virtual int decode_T(std::vector<uint8_t> &data);
    virtual int decode_V(std::vector<uint8_t> &data);
    virtual int decode_TV(std::vector<uint8_t> &data);
    virtual int decode_LV(std::vector<uint8_t> &data);
    virtual int decode_TLV(std::vector<uint8_t> &data);
    virtual int decode_LV_E(std::vector<uint8_t> &data);
    virtual int decode_TLV_E(std::vector<uint8_t> &data);
};
