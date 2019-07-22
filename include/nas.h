#include <iostream>

#pragma once

class Nas
{

public:
    enum class protocol
    {
        group_call_control,
        broadcast_call_control,
        EPS_session_management_messages,
        call_control_call_related_SS_messages,
        GPRS_Transparent_Transport_Protocol,
        mobility_management_messages,
        radio_resources_management_messages,
        EPS_mobility_management_messages,
        GPRS_mobility_management_messages,
        SMS_messages,
        GPRS_session_management_messages,
        non_call_related_SS_messages,
        Location_services_specified_in_3GPP_TS_44_072__8a_,
        used_by_tests_procdures_described_in_3GPP_TS_44_014__5a__3GPP_TS_34_109__17a___3GPP_TS_36_509__26__and_3GPP_TS_38_509__29__,
        // Here are extended protocols
        _5GS_session_management_messages,
        _5GS_mobility_management_messages
    };

    //void decode(std::istream &input);
    //std::ostream encode(Pdu &pdu);
};
