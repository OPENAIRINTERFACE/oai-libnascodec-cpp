#pragma once

#include <iostream>
#include <vector>
#include <information_element.h>

namespace _5GS
{

namespace IE
{

class Message_type : public InformationElement
{

public:

    // TS 24.501- 9.7
    enum class Value : uint8_t
    {
        // MOBILITY MESSAGES
        // Registration
        Registration_request = 0b01000001,
        Registration_accept,
        Registration_complete,
        Registration_reject,
        // Deregistration
        Deregistration_request__UE_originating_,
        Deregistration_accept__UE_originating_,
        Deregistration_request__UE_terminated_,
        Deregistration_accept__UE_terminated_,
        // Service
        Service_request = 0b01001100,
        Service_reject,
        Service_accept,
        // Authentication & security
        Configuration_update_command = 0b01010100,
        Configuration_update_complete,
        Authentication_request,
        Authentication_response,
        Authentication_failure,
        Authentication_result,
        Identity_request,
        Identity_response,
        Security_mode_command,
        Security_mode_complete,
        Security_mode_reject,
        // Notification & transport
        _5GMM_status = 0b1100100,
        Notification,
        Notification_response,
        UL_NAS_transport,
        DL_NAS_transport,
        // SESSION MESSAGES
        // Establishment
        PDU_session_establishment_request = 0b11000001,
        PDU_session_establishment_accept,
        PDU_session_establishment_reject,
        // Authentication
        PDU_session_authentication_command = 0b11000101,
        PDU_session_authentication_complete,
        PDU_session_authentication_result,
        // Modification
        PDU_session_modification_request = 0b11001001,
        PDU_session_modification_reject,
        PDU_session_modification_command,
        PDU_session_modification_complete,
        PDU_session_modification_command_reject,
        // Status
        _5GSM_status = 0b11010110
    };

    Message_type() = default;
    explicit Message_type(const Value value);

    virtual void set(const Value id);
    virtual Value get() const;

    virtual std::string getName() const;
    virtual std::string valueToString() const;

    static std::string value_to_string(const Value value);

protected:
    int code_V(std::vector<uint8_t> &data) const;
    int decode_V(const std::vector<uint8_t> &data);

private:
    Value m_value;
    Value uint8_t_to_Value(const uint8_t byte);
};

} // namespace IE

} // namespace _5GS
