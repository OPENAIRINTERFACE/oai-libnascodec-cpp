#pragma once

#include <iostream>
#include <vector>
#include <information_element.h>

namespace _5GS
{

namespace IE
{

class SSC_mode : public InformationElement
{

public:
    // TS 24.501- 9.11.4.16

    /** @enum Value SSC modes */
    enum class Value : uint8_t
    {
        SSC_mode_1 = 1, /**< SSC mode 1 */
        SSC_mode_2,     /**< SSC mode 2 */
        SSC_mode_3,     /**< SSC mode 3 */
        unused_1,       /**< unused, shall be interpreted as SSC mode 1 if received by the network */
        unused_2,       /**< unused, shall be interpreted as SSC mode 2 if received by the network */
        unused_3        /**< unused, shall be interpreted as SSC mode 3 if received by the network */
    };

    SSC_mode() = default;
    explicit SSC_mode(const Value value);

    void set(Value id);
    Value get() const;

    virtual std::string getName() const;
    virtual std::string valueToString() const;

    static std::string value_to_string(const Value value);
    static Value uint8_t_to_Value(const uint8_t &byte);

    virtual uint8_t code_half_V() const;

protected:
    int code_V(std::vector<uint8_t> &data) const;
    int decode_V(const std::vector<uint8_t> &data);
    int code_TV(std::vector<uint8_t> &data, const uint8_t iei) const;
    int decode_TV(const std::vector<uint8_t> &data, const uint8_t iei);

private:
    Value m_value;
};

} // namespace IE

} // namespace _5GS
