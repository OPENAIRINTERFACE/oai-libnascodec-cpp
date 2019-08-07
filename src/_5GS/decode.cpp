#include <nas.h>
#include <_5GS/decode.h>
#include <_5GS/ie/Message_type.h>
#include <helpers.h>

using namespace _5GS;

int Decode::decode(const std::vector<uint8_t> &data) const
{
    IE::Message_type::Value message_type = Decode::identify_5GS_message_type(data);
    std::vector<uint8_t> tmp;
    int size = 0;

    switch (message_type)
    {
    case IE::Message_type::Value::PDU_session_establishment_request:
    {
        PDU_session_establishment_request pdu;
        size = pdu.decode(data);
        onPduSessionEstablishmentRequest(pdu);
        break;
    }
    default:
        throw std::runtime_error(std::string("Not implemented: ") + IE::Message_type::value_to_string(message_type));
    }
    return size;
}

IE::Message_type::Value Decode::identify(const std::vector<uint8_t> &data) const
{
    IE::Message_type::Value message_type = Decode::identify_5GS_message_type(data);

    switch (message_type)
    {
    case IE::Message_type::Value::PDU_session_establishment_request:
    {
        onPduSessionEstablishmentRequest(data);
        break;
    }
    default:
        throw std::runtime_error(std::string("Not implemented: ") + IE::Message_type::value_to_string(message_type));
    }
    return message_type;
}

IE::Message_type::Value Decode::identify_5GS_message_type(const std::vector<uint8_t> &data)
{
    IE::Message_type message_type;
    std::vector<uint8_t> tmp;

    switch (Nas::decodeProtocolDiscriminator(data))
    {
    case Nas::ProtocolDiscriminator::_5GS_session_management_messages:
        tmp.push_back(data[3]);
        message_type.decode(tmp, InformationElement::Format::V);
    case Nas::ProtocolDiscriminator::_5GS_mobility_management_messages:
        tmp.push_back(data[2]);
        message_type.decode(tmp, InformationElement::Format::V);
        break;
    default:
        throw std::runtime_error("This is not a 5GS nas message, dump follows:\n" + std::string(dump_wireshark(data)));
    }
    return message_type.get();
}
// PDU stubs

void Decode::onPduSessionEstablishmentRequest(const PDU_session_establishment_request &pdu) const
{
    throw std::runtime_error(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

void Decode::onPduSessionEstablishmentRequest(const std::vector<uint8_t> &data) const
{
    throw std::runtime_error(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}