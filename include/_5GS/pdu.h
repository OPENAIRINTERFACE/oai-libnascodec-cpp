#pragma once

#include <vector>
#include <cstdint>

namespace _5GS
{
class Pdu
{

public:
    enum class Type
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
        PDU_session_establishment_request = 0b11000001,
        PDU_session_establishment_accept,
        PDU_session_establishment_reject
    };

    virtual int code(std::vector<uint8_t> & data) const;
    virtual int decode(std::vector<uint8_t> & data);

};
} // namespace _5GS