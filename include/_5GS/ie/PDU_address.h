#pragma once

#include <iostream>
#include <vector>
#include <information_element.h>

namespace _5GS
{

namespace IE
{

class PDU_address : public InformationElement
{

public:

    // TS 24.501- 9.11.4.10

    class Value
    {
    public:
        const static size_t INTERFACE_V6_MAX_SIZE = 8;

        enum class Type : uint8_t
        {
            IPv4 = 1,
            IPv6,
            IPv4v6,
        };
    
        explicit Value() = default;
        explicit Value(const std::uint32_t address_v4);
        explicit Value(const std::string interface_v6);
        explicit Value(const std::string interface_v6, const std::uint32_t address_v4);

        // FIXME scope & getter & setters ?
        Type m_type;
        std::uint32_t m_ipv4;
        // NOTE : m_ipv6 is not an ipv6 address !
        // "If the PDU session type value indicates IPv6, the PDU address
        // information in octet 4 to octet 11 contains an interface identifier
        // for the IPv6 link local address."
        // See also RFC6459 5.2, RFC3162 3.2
        std::string m_interface_v6;

    };

    explicit PDU_address() = default;
    explicit PDU_address(const Value &value);

    void set(const Value &value);
    Value get() const;

    virtual std::string getName() const;
    virtual std::string valueToString() const;

    static std::string value_to_string(const Value value);

protected:
    int code_TLV(std::vector<uint8_t> &data, const uint8_t iei) const;
    int decode_TLV(const std::vector<uint8_t> &data, const uint8_t iei);

private:
    Value m_value;
};

} // namespace IE

} // namespace _5GS

bool operator==(const _5GS::IE::PDU_address::Value &a,
                const _5GS::IE::PDU_address::Value &b);
