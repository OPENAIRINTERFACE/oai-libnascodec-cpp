#pragma once

#include <iostream>

#include <_5GS/ie/PDU_session_ID.h>

namespace _5GS
{
class Pdu
{

    enum _5GS_Message_type
    {
        // Mobility messages
        Registration_request,
        Registration_accept,
        Registration_complete,
        Registration_reject,
        Deregistration_request__UE_originating_,
        Deregistration_accept__UE_originating_,
        Deregistration_request__UE_terminated,
        Deregistration_accept_UE_terminated,
        Service_request,
        Service_reject,
        Service_accept,
        Configuration_update_command,
        Configuration_update_complete,
        // TODO lot more not defined here,
        // Session messages
        PDU_session_establishment_request,
        PDU_session_establishment_accept,
        PDU_session_establishment_reject
    } type;

public:
    
    std::ostream &operator<<(std::ostream &output);
    std::istream &operator>>(std::istream &input);

private:
    // for SM and MM messages
    _5GS::IE::PDU_session_ID &pdu_session_id;
};
} // namespace _5GS