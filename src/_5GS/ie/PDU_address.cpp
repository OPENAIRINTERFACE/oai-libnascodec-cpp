#include <arpa/inet.h>
#include <_5GS/ie/PDU_address.h>
#include <buffers.h>

namespace _5GS
{
namespace IE
{

std::string PDU_address::getName() const
{
    return "PDU address";
}

PDU_address::PDU_address(const PDU_address::Value &value)
{
    set(value);
}

void PDU_address::set(const PDU_address::Value &value)
{
    m_present = true;
    m_value = value;
}

PDU_address::Value PDU_address::get() const
{
    raise_exception_if_not_present(className(this));
    return m_value;
}

int PDU_address::code_TLV(std::vector<uint8_t> &data, const uint8_t iei) const
{
    int size = 0;
    std::uint32_t ipv4 = htonl(m_value.m_ipv4);
    std::vector<std::uint8_t> tmp_v4((uint8_t *)&ipv4, (uint8_t *)&ipv4 + sizeof(ipv4));
    std::vector<std::uint8_t> tmp_v6(m_value.m_interface_v6.begin(), m_value.m_interface_v6.end());
    tmp_v6.resize(8);

    raise_exception_if_not_present(className(this));

    data.push_back(iei);
    data.push_back(static_cast<uint8_t>(m_value.m_type));
    size += 2;
    switch (m_value.m_type)
    {
    case PDU_address::Value::Type::IPv4:
        data += tmp_v4;
        size += tmp_v4.size();
        break;
    case PDU_address::Value::Type::IPv6:
        data += tmp_v6;
        size += tmp_v6.size();
        break;
    case PDU_address::Value::Type::IPv4v6:
        data += tmp_v6;
        size += tmp_v6.size();
        data += tmp_v4;
        size += tmp_v4.size();
        break;
    }
    return size;
}

int PDU_address::decode_TLV(const std::vector<uint8_t> &data, const uint8_t iei)
{
    int size = 0;
    if (data.size() == 0)
    {
        throw NasCodecException(
            std::string("No data to decode ") +
            std::string(__PRETTY_FUNCTION__));
    }

    if (data[0] != iei)
    {
        throw NasCodecException(std::string(__PRETTY_FUNCTION__) + std::string("invalid iei"));
    }

    try
    {

        switch (static_cast<PDU_address::Value::Type>(data[1]))
        {
        case PDU_address::Value::Type::IPv4:
            m_value.m_ipv4 = (data[2] << 24) + (data[3] << 16) + (data[4] << 8) + data[5];
            size = 6;
            break;
        case PDU_address::Value::Type::IPv6:
            m_value.m_interface_v6.clear();
            for (int index = 2; index < 10; index++)
            {
                if (data[index] != 0)
                {
                    m_value.m_interface_v6 += data[index];
                }
            }
            size = 10;
            break;
        case PDU_address::Value::Type::IPv4v6:
            m_value.m_interface_v6.clear();
            for (int index = 2; index < 10; index++)
            {
                if (data[index] != 0)
                {
                    m_value.m_interface_v6 += data[index];
                }
            }
            m_value.m_ipv4 = (data[10] << 24) + (data[11] << 16) + (data[12] << 8) + data[13];
            size = 14;
            break;
        default:
            throw NasCodecException(
                std::string(__PRETTY_FUNCTION__) +
                std::string(" Invalid PDU address type:\n") +
                dump_wireshark(data));
        }
        m_value.m_type = static_cast<PDU_address::Value::Type>(data[1]);
    }
    catch (...)
    {
        throw NasCodecException(
            std::string(__PRETTY_FUNCTION__) +
            std::string(" Invalid pdu address data:\n") +
            dump_wireshark(data));
    }
    m_present = true;
    return size;
}

std::string PDU_address::valueToString() const
{
    if (not isSet())
    {
        return "-";
    }
    return PDU_address::value_to_string(m_value);
}

std::string PDU_address::value_to_string(const PDU_address::Value value)
{
    switch (value.m_type)
    {
    case PDU_address::Value::Type::IPv4:
        return "IPv4(" + ipv4_uint32_to_string(value.m_ipv4) + ")";
    case PDU_address::Value::Type::IPv6:
        return "IPv6('" + value.m_interface_v6 + "')";
    case PDU_address::Value::Type::IPv4v6:
        return "IPv4v6('" + value.m_interface_v6 + "', " + ipv4_uint32_to_string(value.m_ipv4) + ") ";
    }
    throw std::invalid_argument("Not a PDU address value");
}

// Value class

PDU_address::Value::Value(const std::uint32_t address_v4)
{
    m_type = PDU_address::Value::Type::IPv4;
    m_ipv4 = address_v4;
}

PDU_address::Value::Value(const std::string interface_v6)
{
    m_type = PDU_address::Value::Type::IPv6;

    if (interface_v6.size() > PDU_address::Value::INTERFACE_V6_MAX_SIZE)
    {
        throw NasCodecException("String too long (" +
                                std::to_string(interface_v6.size()) + ">" +
                                std::to_string(PDU_address::Value::INTERFACE_V6_MAX_SIZE) + "): " +
                                interface_v6);
    }
    m_interface_v6 = interface_v6;
}

PDU_address::Value::Value(const std::string interface_v6, const std::uint32_t address_v4)
{
    m_type = PDU_address::Value::Type::IPv4v6;

    if (interface_v6.size() > PDU_address::Value::INTERFACE_V6_MAX_SIZE)
    {
        throw NasCodecException("String too long (" +
                                std::to_string(interface_v6.size()) + ">" +
                                std::to_string(PDU_address::Value::INTERFACE_V6_MAX_SIZE) + "): " +
                                interface_v6);
    }
    m_interface_v6 = interface_v6;
    m_ipv4 = address_v4;
}

} // namespace IE
} // namespace _5GS

bool operator==(const _5GS::IE::PDU_address::Value &a,
                const _5GS::IE::PDU_address::Value &b)
{
    switch (a.m_type)
    {
    case _5GS::IE::PDU_address::Value::Type::IPv4:
        return (a.m_type == b.m_type) &&
               (a.m_ipv4 == b.m_ipv4);
    case _5GS::IE::PDU_address::Value::Type::IPv6:
        return (a.m_type == b.m_type) &&
               (a.m_interface_v6 == b.m_interface_v6);
    case _5GS::IE::PDU_address::Value::Type::IPv4v6:
        return (a.m_type == b.m_type) &&
               (a.m_ipv4 == b.m_ipv4) &&
               (a.m_interface_v6 == b.m_interface_v6);
    }
    throw std::invalid_argument("Not a PDU address value");
}
