#pragma once

#include <_5GS/pdu_5gs_sm.h>
#include <_5GS/ie/Selected_PDU_session_type.h>
#include <_5GS/ie/Selected_SSC_mode.h>
#include <_5GS/ie/Authorized_QoS_rules.h>
#include <_5GS/ie/DNN.h>
#include <_5GS/ie/Session_AMBR.h>

namespace _5GS
{
class PDU_session_establishment_accept : public Pdu5gsSm
{

public:
    // Mandatory
    IE::Selected_PDU_session_type m_selected_pdu_session_type;
    IE::Selected_SSC_mode m_selected_ssc_mode;
    IE::Authorized_QoS_rules m_authorized_qos_rules;
    IE::Session_AMBR m_session_ambr;
    // Optionals
    IE::DNN m_dnn;

    PDU_session_establishment_accept();
    // TODO doc
    PDU_session_establishment_accept(
        IE::PDU_session_identity psi,
        IE::Procedure_transaction_identity pti,
        // Mandatory
        IE::Selected_PDU_session_type spst,
        IE::Selected_SSC_mode sm,
        IE::Authorized_QoS_rules aqr,
        IE::Session_AMBR sa,
        // Optionals,
        // IE::_5GSM_cause cause = ,
        // IE::PDU_address pdu_address = ,
        // IE::RQ_timer_value rq_timer_value =,
        // IE::S_NSSAI s_nssai =
        // IE::Always_on_PDU_session_indication always_on = ,
        // IE::Mapped_EPS_bearer_contexts mapped_bearers = ,
        // IE::EAP_message eap = ,
        // IE::Authorized_QoS_flow_descriptions auth_qos = ,
        // IE::Extended_protocol_configuration_option = ,
        IE::DNN dnn = IE::DNN()
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