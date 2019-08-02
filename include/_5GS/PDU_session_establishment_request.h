#pragma once

#include <_5GS/pdu_5gs_sm.h>
#include <_5GS/ie/PDU_session_type.h>
#include <_5GS/ie/Integrity_protection_maximum_data_rate.h>

namespace _5GS
{
class PDU_session_establishment_request : public Pdu5gsSm
{

public:
    // Mandatory
    IE::Integrity_protection_maximum_data_rate integrity_protection_maximum_data_rate;
    IE::PDU_session_type pdu_session_type;

    PDU_session_establishment_request();

    virtual int code_ex(std::vector<uint8_t> &data) const;
    virtual int decode_ex(const std::vector<uint8_t> &data);

    std::string to_string() const;

private:
    // XXX Iei are local to message type !
    // ie. iei 0x9- is used for :
    // - Network slice indication for Registration Request PDU
    // - PDU session type for PDU Session Establishment Request
    enum Iei {
        // TODO Must verify .... iei > 0x90 are half octet
        PDU_session_type = 0x90,
        SSC_Mode = 0xA0,
        Always_on_PDU_session_requested = 0xB0,
        // Others ...
        _5GSM_capability = 0x28,
        Maximum_number_of_supported_packet_filter = 0x55,
        SM_PDU_DN_request_container = 0x39,
        Extended_protocol_configuration_option = 0x7B

    };
};
} // namespace _5GS