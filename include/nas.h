#pragma once

#include <iostream>
#include <vector>
#include <cstdint>

class Nas
{

public:
    static int decode(std::vector<uint8_t> & data);

    enum class ProtocolDiscriminator : uint8_t
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
        used_by_tests_procdures_described_in_3GPP_TS_44_014__5a__3GPP_TS_34_109__17a___3GPP_TS_36_509__26__and_3GPP_TS_38_509__29__ = 0X0f,
        // Here are extended protocols 0bxxxx1110
        _5GS_session_management_messages = 0b00101110,
        _5GS_mobility_management_messages = 0b01111110,
        reserved = 254
    };

    enum class SecurityHeaderType : uint8_t {
        Plain_5GS_NAS_message__not_security_protected,
        Integrity_protected,
        Integrity_protected_and_cyphered,
        Integrity_protected_with_new_5G_NAS_security_context,
        Integrity_protected_and_cyphered_with_new_5G_NAS_security_context
    };

    static int codeProtocolDiscriminator(std::vector<uint8_t> & data,const ProtocolDiscriminator protocol);
    static int codeSecurityHeaderType(std::vector<uint8_t> & data,const SecurityHeaderType security);
    static ProtocolDiscriminator decodeProtocolDiscriminator(std::vector<uint8_t> &data);
    static Nas::ProtocolDiscriminator uint8_t_to_ProtocolDiscriminator(uint8_t byte);
};
