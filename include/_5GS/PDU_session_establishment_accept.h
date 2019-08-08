#pragma once

#include <_5GS/pdu_5gs_sm.h>
#include <_5GS/ie/Selected_PDU_session_type.h>

namespace _5GS
{
class PDU_session_establishment_accept : public Pdu5gsSm
{

public:
    // Mandatory
    IE::Selected_PDU_session_type selected_pdu_session_type;
    // IE::Selected_SSC_mode selected_ssc_mode;
    // 

    PDU_session_establishment_accept();
    // TODO doc
    PDU_session_establishment_accept(
        IE::PDU_session_identity psi,
        IE::Procedure_transaction_identity pti,
        IE::Selected_PDU_session_type spst
        //        IE::Selected_SSC_mode selected_ssc_mode,
        //        IE::Authorized_QoS_rules authorized
    );

    virtual int code(std::vector<uint8_t> &data) const;
    virtual int decode(const std::vector<uint8_t> &data);

    std::string to_string() const;

private:
    /** @enum Iei information identifier table for PDU session request accept */
    enum Iei
    {
        // iei > 0x80 are half octet values
        Always_on_PDU_session_requested = 0x80,
        // Others ...
        _5GSM_cause = 0x59,
        PDU_address = 0x29,
        RQ_timer_value = 0x56,
        Mapped_EPS_bearer_contexts = 0x75,
        EAP_message = 0x78,
        Authorized_QoS_flow_descriptions = 0x79,
        Extended_protocol_configuration_option = 0x7B,
        DNN = 0x25
    };
};
} // namespace _5GS