#include <_5GS/ie/Session_AMBR.h>
#include <buffers.h>

namespace _5GS
{
namespace IE
{

// class Session_AMBR_Fields

Session_AMBR_Fields::Session_AMBR_Fields(
    Unit_for_Session_AMBR downlink_unit,
    uint16_t downlink,
    Unit_for_Session_AMBR uplink_unit,
    uint16_t uplink) : m_downlink_unit(downlink_unit),
                       m_downlink(downlink),
                       m_uplink_unit(uplink_unit),
                       m_uplink(uplink){

                       };

bool Session_AMBR_Fields::operator==(const Session_AMBR_Fields &other) const
{
    // FIXME
    if (m_downlink_unit != other.m_downlink_unit)
    {
        return false;
    }
    if (m_downlink != other.m_downlink)
    {
        return false;
    }
    if (m_uplink_unit != other.m_uplink_unit)
    {
        return false;
    }
    if (m_uplink != other.m_uplink)
    {
        return false;
    }

    return true;
}

// class Session_AMBR

std::string Session_AMBR::getName() const
{
    return "Session AMBR";
}

Session_AMBR::Session_AMBR(const Session_AMBR_Fields &value)
{
    set(value);
}

void Session_AMBR::set(const Session_AMBR_Fields &value)
{
    m_present = true;
    m_value = value;
}

Session_AMBR_Fields Session_AMBR::get() const
{
    raise_exception_if_not_present(className(this));
    return m_value;
}

int Session_AMBR::code_LV(std::vector<uint8_t> &data) const
{
    raise_exception_if_not_present(className(this));

    int size = 0;
    data.push_back(6);
    size += 1;
    size += m_value.m_downlink_unit.code(data, InformationElement::Format::V);
    // FIXME add coders for simple type
    data.push_back((m_value.m_downlink & 0xff00) >> 8);
    data.push_back(m_value.m_downlink & 0xff);
    size += 2;
    size += m_value.m_uplink_unit.code(data, InformationElement::Format::V);
    data.push_back((m_value.m_uplink & 0xff00) >> 8);
    data.push_back(m_value.m_uplink & 0xff);
    size += 2;

    return size;
}

int Session_AMBR::decode_LV(const std::vector<uint8_t> &data)
{
    int size = 0;
    // skip length
    size = 1;
    // downlink
    size += m_value.m_downlink_unit.decode(std::vector<uint8_t>(data.begin() + size, data.end()),
                                           InformationElement::Format::V);
    m_value.m_downlink = (data[size] << 8) + data[size + 1];
    size += 2;
    // uplink
    size += m_value.m_uplink_unit.decode(std::vector<uint8_t>(data.begin() + size, data.end()),
                                         InformationElement::Format::V);
    m_value.m_uplink = (data[size] << 8) + data[size + 1];
    size += 2;
    // check size
    if (size != data[0] + 1)
    {
        throw NasCodecException(std::string(__PRETTY_FUNCTION__) +
                                std::string(" Invalid length: found ") +
                                std::to_string(data[0]) +
                                std::string(" expected ") +
                                std::to_string(size));
    }

    m_present = true;
    return size;
}

std::string Session_AMBR::valueToString() const
{
    if (not isSet())
    {
        return "-";
    }
    return "downlink_unit(" + m_value.m_downlink_unit.valueToString() + ")" +
           "&downlink(" + std::to_string(m_value.m_downlink) + ")" +
           "&uplink_unit(" + m_value.m_uplink_unit.valueToString() + ")" +
           "&uplink(" + std::to_string(m_value.m_uplink) + ")";
}

} // namespace IE
} // namespace _5GS
