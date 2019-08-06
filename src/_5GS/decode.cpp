#include <nas.h>
#include <_5GS/decode.h>
#include <_5GS/ie/Message_type.h>
#include <helpers.h>

int _5GS::Decode::decode(const std::vector<uint8_t> &data)
{
    IE::Message_type message_type;
    std::vector<uint8_t> tmp;
    int size = 0;
    switch (Nas::decodeProtocolDiscriminator(data))
    {
    case Nas::ProtocolDiscriminator::_5GS_session_management_messages:
        tmp.push_back(data[3]);
        message_type.decode_V_ex(tmp);
    case Nas::ProtocolDiscriminator::_5GS_mobility_management_messages:
        tmp.push_back(data[2]);
        message_type.decode_V_ex(tmp);
        break;
    default:
        throw std::runtime_error("This is not a 5GS nas message, dump follows:\n" + std::string(dump_wireshark(data)));
    }
    switch (message_type.get())
    {
    case IE::Message_type::Value::PDU_session_establishment_request:
    {
        PDU_session_establishment_request pdu;
        size = pdu.decode_ex(data);
        this->onPduSessionEstablishmentRequest(pdu);
        break;
    }
    default:
        throw std::runtime_error(std::string("Not implemented: ") + message_type.to_string());
    }
    return size;
}

void _5GS::Decode::onPduSessionEstablishmentRequest(const _5GS::PDU_session_establishment_request &pdu)
{
    throw std::runtime_error(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}
