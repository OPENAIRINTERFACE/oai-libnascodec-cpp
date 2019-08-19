#pragma once

#include <iostream>
#include <vector>
#include <information_element.h>

namespace _5GS
{

namespace IE
{

class String : public InformationElement
{
public:
    // Generic string ie to inherit

    String() = default;
    explicit String(const std::string &value);

    void set(const std::string &value);
    std::string get() const;

    int code_TLV(std::vector<uint8_t> &data, const uint8_t iei) const;
    int decode_TLV(const std::vector<uint8_t> &data, const uint8_t iei);

    static std::string value_to_string(const std::string &value);

    virtual std::string getName() const;
    virtual std::string valueToString() const;

private:
    std::string m_value;
};

} // namespace IE

} // namespace _5GS
