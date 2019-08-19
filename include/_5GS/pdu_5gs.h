#pragma once

#include <header.h>
#include <_5GS/ie/Message_type.h>

namespace _5GS
{
class Pdu5gs : public Nas
{
public:
    // common IE to all 5GS messages
    IE::Message_type m_message_type;

    // codec
    virtual int code(std::vector<uint8_t> &data) const;
    virtual int decode(const std::vector<uint8_t> &data);

    virtual std::string header_to_string() const;

private:
    int codeMMHeader(std::vector<uint8_t> &data) const;

};
} // namespace _5GS
