#pragma once

#include <_5GS/pdu_5gs_sm.h>
#include <_5GS/ie/PDU_session_type.h>
#include <_5GS/ie/Integrity_protection_maximum_data_rate.h>
#include <_5GS/ie/SSC_mode.h>
#include <_5GS/ie/SM_PDU_DN_request_container.h>

namespace _5GS
{
class PDU_session_establishment_request : public Pdu5gsSm
{

public:
    // Mandatory
    IE::Integrity_protection_maximum_data_rate m_integrity_protection_maximum_data_rate;
    IE::PDU_session_type m_pdu_session_type;
    IE::SSC_mode m_ssc_mode;
    IE::SM_PDU_DN_request_container m_sm_pdu_dn_request_container;

    PDU_session_establishment_request();
    // TODO doc
    PDU_session_establishment_request(
        IE::PDU_session_identity psi,
        IE::Procedure_transaction_identity pti,
        // Mandatory
        IE::Integrity_protection_maximum_data_rate ipmdr,
        // Optional
        IE::PDU_session_type pst = IE::PDU_session_type(),
        IE::SSC_mode sm = IE::SSC_mode(),
        //IE::_5GSM_capability = IE::_5GSM_capability(),
        //IE::Maximum_number_of_supported_packet_filters = IE::Maximum_number_of_supported_packet_filters(),
        //IE::Always_on_PDU_session_requested always_on = IE::Always_on_PDU_session_requested(),
        IE::SM_PDU_DN_request_container spdnc = IE::SM_PDU_DN_request_container(),
        //IE::Extended_protocol_configuration_option = IE::Extended_protocol_configuration_option(),
        int placeholder = 1 // remove me when the last optional ie is implemented
    );

    virtual int code(std::vector<uint8_t> &data) const;
    virtual int decode(const std::vector<uint8_t> &data);

    std::string to_string() const;

private:
    // Warning: Iei are local to message type !
    // ie. iei 0x9- is used for :
    // - Network slice indication for Registration Request PDU
    // - PDU session type for PDU Session Establishment Request
    // Thus we can't have a global list of Iei
    enum Iei {
        // iei > 0x90 are half octet values
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
