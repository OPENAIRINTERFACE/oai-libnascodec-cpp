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

    // return number of byte read or written else -1 for error

    virtual int code(std::vector<uint8_t> &data, const InformationElement::Format format) const;
    virtual int decode(const std::vector<uint8_t> &data, const InformationElement::Format format);

    virtual int code_ex(std::vector<uint8_t> &data, const InformationElement::Format format) const;
    virtual int decode_ex(const std::vector<uint8_t> &data, const InformationElement::Format format);

protected:
    bool present = false; // set if ie is optional and found in a pdu
    void raise_exception_if_not_present() const;

private:
    virtual int code_T(std::vector<uint8_t> &data) const;
    virtual int code_V(std::vector<uint8_t> &data) const;
    virtual int code_TV(std::vector<uint8_t> &data) const;
    virtual int code_LV(std::vector<uint8_t> &data) const;
    virtual int code_TLV(std::vector<uint8_t> &data) const;
    virtual int code_LV_E(std::vector<uint8_t> &data) const;
    virtual int code_TLV_E(std::vector<uint8_t> &data) const;

    virtual int code_T_ex(std::vector<uint8_t> &data) const;
    virtual int code_V_ex(std::vector<uint8_t> &data) const;
    virtual int code_TV_ex(std::vector<uint8_t> &data) const;
    virtual int code_LV_ex(std::vector<uint8_t> &data) const;
    virtual int code_TLV_ex(std::vector<uint8_t> &data) const;
    virtual int code_LV_E_ex(std::vector<uint8_t> &data) const;
    virtual int code_TLV_E_ex(std::vector<uint8_t> &data) const;

    virtual int decode_T(const std::vector<uint8_t> &data);
    virtual int decode_V(const std::vector<uint8_t> &data);
    virtual int decode_TV(const std::vector<uint8_t> &data);
    virtual int decode_LV(const std::vector<uint8_t> &data);
    virtual int decode_TLV(const std::vector<uint8_t> &data);
    virtual int decode_LV_E(const std::vector<uint8_t> &data);
    virtual int decode_TLV_E(const std::vector<uint8_t> &data);

    virtual int decode_T_ex(const std::vector<uint8_t> &data);
    virtual int decode_V_ex(const std::vector<uint8_t> &data);
    virtual int decode_TV_ex(const std::vector<uint8_t> &data);
    virtual int decode_LV_ex(const std::vector<uint8_t> &data);
    virtual int decode_TLV_ex(const std::vector<uint8_t> &data);
    virtual int decode_LV_E_ex(const std::vector<uint8_t> &data);
    virtual int decode_TLV_E_ex(const std::vector<uint8_t> &data);
};
