#pragma once

#include <iostream>
#include <vector>

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

    virtual std::vector<uint8_t> code(InformationElement::Format format) const;
    virtual std::vector<uint8_t> decode(InformationElement::Format format, std::vector<uint8_t> & data);

protected:
    bool present = false; // set if ie is optional and found in a pdu

private:
    // FIXME use ref instead copy for std::vector<uint8_t> for perf
    virtual std::vector<uint8_t> code_T() const;
    virtual std::vector<uint8_t> code_V() const;
    virtual std::vector<uint8_t> code_TV() const;
    virtual std::vector<uint8_t> code_LV() const;
    virtual std::vector<uint8_t> code_TLV() const;
    virtual std::vector<uint8_t> code_LV_E() const;
    virtual std::vector<uint8_t> code_TLV_E() const;

    virtual std::vector<uint8_t> decode_T(std::vector<uint8_t> & data);
    virtual std::vector<uint8_t> decode_V(std::vector<uint8_t> & data);
    virtual std::vector<uint8_t> decode_TV(std::vector<uint8_t> & data);
    virtual std::vector<uint8_t> decode_LV(std::vector<uint8_t> & data);
    virtual std::vector<uint8_t> decode_TLV(std::vector<uint8_t> & data);
    virtual std::vector<uint8_t> decode_LV_E(std::vector<uint8_t> & data);
    virtual std::vector<uint8_t> decode_TLV_E(std::vector<uint8_t> & data);
};

// FIXME to remove ?
std::istream & operator>>(std::istream & input, std::vector<uint8_t> & data);
std::ostream & operator<<(std::ostream & output, std::vector<uint8_t> & data);
