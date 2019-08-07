#include <_5GS/ie/Message_type.h>
#include <helpers.h>

namespace _5GS
{
namespace IE
{

void Message_type::set(Message_type::Value value)
{
    this->m_present = true;
    this->m_value = value;
}

Message_type::Value Message_type::get() const
{
    this->raise_exception_if_not_present(className(this));
    return this->m_value;
}

int Message_type::code_V(std::vector<uint8_t> &data) const
{
    this->raise_exception_if_not_present(className(this));
    data.push_back(static_cast<uint8_t>(this->m_value));
    return 1;
}

int Message_type::decode_V(const std::vector<uint8_t> &data)
{
    this->m_value = Message_type::uint8_t_to_Value(data[0]);
    this->m_present = true;
    return 1;
}

Message_type::Value Message_type::uint8_t_to_Value(const uint8_t byte)
{
    switch (byte)
    {
    // MOBILITY MESSAGES
    // Registration
    case static_cast<uint8_t>(Message_type::Value::Registration_request):
        return Message_type::Value::Registration_request;
    case static_cast<uint8_t>(Message_type::Value::Registration_accept):
        return Message_type::Value::Registration_accept;
    case static_cast<uint8_t>(Message_type::Value::Registration_complete):
        return Message_type::Value::Registration_complete;
    case static_cast<uint8_t>(Message_type::Value::Registration_reject):
        return Message_type::Value::Registration_reject;
    // Deregistration
    case static_cast<uint8_t>(Message_type::Value::Deregistration_request__UE_originating_):
        return Message_type::Value::Deregistration_request__UE_originating_;
    case static_cast<uint8_t>(Message_type::Value::Deregistration_accept__UE_originating_):
        return Message_type::Value::Deregistration_accept__UE_originating_;
    case static_cast<uint8_t>(Message_type::Value::Deregistration_request__UE_terminated):
        return Message_type::Value::Deregistration_request__UE_terminated;
    case static_cast<uint8_t>(Message_type::Value::Deregistration_accept_UE_terminated):
        return Message_type::Value::Deregistration_accept_UE_terminated;
    // Service
    case static_cast<uint8_t>(Message_type::Value::Service_request):
        return Message_type::Value::Service_request;
    case static_cast<uint8_t>(Message_type::Value::Service_reject):
        return Message_type::Value::Service_reject;
    case static_cast<uint8_t>(Message_type::Value::Service_accept):
        return Message_type::Value::Service_accept;
    // Authentication & security
    case static_cast<uint8_t>(Message_type::Value::Configuration_update_command):
        return Message_type::Value::Configuration_update_command;
    case static_cast<uint8_t>(Message_type::Value::Configuration_update_complete):
        return Message_type::Value::Configuration_update_complete;
    case static_cast<uint8_t>(Message_type::Value::Authentication_request):
        return Message_type::Value::Authentication_request;
    case static_cast<uint8_t>(Message_type::Value::Authentication_response):
        return Message_type::Value::Authentication_response;
    case static_cast<uint8_t>(Message_type::Value::Authentication_failure):
        return Message_type::Value::Authentication_failure;
    case static_cast<uint8_t>(Message_type::Value::Authentication_result):
        return Message_type::Value::Authentication_result;
    case static_cast<uint8_t>(Message_type::Value::Identity_request):
        return Message_type::Value::Identity_request;
    case static_cast<uint8_t>(Message_type::Value::Identity_response):
        return Message_type::Value::Identity_response;
    case static_cast<uint8_t>(Message_type::Value::Security_mode_command):
        return Message_type::Value::Security_mode_command;
    case static_cast<uint8_t>(Message_type::Value::Security_mode_complete):
        return Message_type::Value::Security_mode_complete;
    case static_cast<uint8_t>(Message_type::Value::Security_mode_reject):
        return Message_type::Value::Security_mode_reject;
    // Notification & transport
    case static_cast<uint8_t>(Message_type::Value::_5GMM_status):
        return Message_type::Value::_5GMM_status;
    case static_cast<uint8_t>(Message_type::Value::Notification):
        return Message_type::Value::Notification;
    case static_cast<uint8_t>(Message_type::Value::Notification_response):
        return Message_type::Value::Notification_response;
    case static_cast<uint8_t>(Message_type::Value::UL_NAS_transport):
        return Message_type::Value::UL_NAS_transport;
    case static_cast<uint8_t>(Message_type::Value::DL_NAS_transport):
        return Message_type::Value::DL_NAS_transport;
    // SESSION MESSAGES
    // Establishment
    case static_cast<uint8_t>(Message_type::Value::PDU_session_establishment_request):
        return Message_type::Value::PDU_session_establishment_request;
    case static_cast<uint8_t>(Message_type::Value::PDU_session_establishment_accept):
        return Message_type::Value::PDU_session_establishment_accept;
    case static_cast<uint8_t>(Message_type::Value::PDU_session_establishment_reject):
        return Message_type::Value::PDU_session_establishment_reject;
    // Authentication
    case static_cast<uint8_t>(Message_type::Value::PDU_session_authentication_command):
        return Message_type::Value::PDU_session_authentication_command;
    case static_cast<uint8_t>(Message_type::Value::PDU_session_authentication_complete):
        return Message_type::Value::PDU_session_authentication_complete;
    case static_cast<uint8_t>(Message_type::Value::PDU_session_authentication_result):
        return Message_type::Value::PDU_session_authentication_result;
    // Modification
    case static_cast<uint8_t>(Message_type::Value::PDU_session_modification_request):
        return Message_type::Value::PDU_session_modification_request;
    case static_cast<uint8_t>(Message_type::Value::PDU_session_modification_reject):
        return Message_type::Value::PDU_session_modification_reject;
    case static_cast<uint8_t>(Message_type::Value::PDU_session_modification_command):
        return Message_type::Value::PDU_session_modification_command;
    case static_cast<uint8_t>(Message_type::Value::PDU_session_modification_complete):
        return Message_type::Value::PDU_session_modification_complete;
    case static_cast<uint8_t>(Message_type::Value::PDU_session_modification_command_reject):
        return Message_type::Value::PDU_session_modification_command_reject;
    // Status
    case static_cast<uint8_t>(Message_type::Value::_5GSM_status):
        return Message_type::Value::_5GSM_status;
    }
    throw std::invalid_argument("Can't decode Message Type IE");
}

std::string Message_type::to_string() const
{
    if (not this->isSet())
    {
        return "-";
    }
    return Message_type::value_to_string(this->m_value);
}

std::string Message_type::value_to_string(const Value value)
{
    switch (value)
    {
    // MOBILITY MESSAGES
    // Registration
    case Message_type::Value::Registration_request:
        return "Registration_request";
    case Message_type::Value::Registration_accept:
        return "Registration_accept";
    case Message_type::Value::Registration_complete:
        return "Registration_complete";
    case Message_type::Value::Registration_reject:
        return "Registration_reject";
    // Deregistration
    case Message_type::Value::Deregistration_request__UE_originating_:
        return "Deregistration_request__UE_originating_";
    case Message_type::Value::Deregistration_accept__UE_originating_:
        return "Deregistration_accept__UE_originating_";
    case Message_type::Value::Deregistration_request__UE_terminated:
        return "Deregistration_request__UE_terminated";
    case Message_type::Value::Deregistration_accept_UE_terminated:
        return "Deregistration_accept_UE_terminated";
    // Service
    case Message_type::Value::Service_request:
        return "Service_request";
    case Message_type::Value::Service_reject:
        return "Service_reject";
    case Message_type::Value::Service_accept:
        return "Service_accept";
    // Authentication & security
    case Message_type::Value::Configuration_update_command:
        return "Configuration_update_command";
    case Message_type::Value::Configuration_update_complete:
        return "Configuration_update_complete";
    case Message_type::Value::Authentication_request:
        return "Authentication_request";
    case Message_type::Value::Authentication_response:
        return "Authentication_response";
    case Message_type::Value::Authentication_failure:
        return "Authentication_failure";
    case Message_type::Value::Authentication_result:
        return "Authentication_result";
    case Message_type::Value::Identity_request:
        return "Identity_request";
    case Message_type::Value::Identity_response:
        return "Identity_response";
    case Message_type::Value::Security_mode_command:
        return "Security_mode_command";
    case Message_type::Value::Security_mode_complete:
        return "Security_mode_complete";
    case Message_type::Value::Security_mode_reject:
        return "Security_mode_reject";
    // Notification & transport
    case Message_type::Value::_5GMM_status:
        return "_5GMM_status";
    case Message_type::Value::Notification:
        return "Notification";
    case Message_type::Value::Notification_response:
        return "Notification_response";
    case Message_type::Value::UL_NAS_transport:
        return "UL_NAS_transport";
    case Message_type::Value::DL_NAS_transport:
        return "DL_NAS_transport";
    // SESSION MESSAGES
    // Establishment
    case Message_type::Value::PDU_session_establishment_request:
        return "PDU_session_establishment_request";
    case Message_type::Value::PDU_session_establishment_accept:
        return "PDU_session_establishment_accept";
    case Message_type::Value::PDU_session_establishment_reject:
        return "PDU_session_establishment_reject";
    // Authentication
    case Message_type::Value::PDU_session_authentication_command:
        return "PDU_session_authentication_command";
    case Message_type::Value::PDU_session_authentication_complete:
        return "PDU_session_authentication_complete";
    case Message_type::Value::PDU_session_authentication_result:
        return "PDU_session_authentication_result";
    // Modification
    case Message_type::Value::PDU_session_modification_request:
        return "PDU_session_modification_request";
    case Message_type::Value::PDU_session_modification_reject:
        return "PDU_session_modification_reject";
    case Message_type::Value::PDU_session_modification_command:
        return "PDU_session_modification_command";
    case Message_type::Value::PDU_session_modification_complete:
        return "PDU_session_modification_complete";
    case Message_type::Value::PDU_session_modification_command_reject:
        return "PDU_session_modification_command_reject";
    // Status
    case Message_type::Value::_5GSM_status:
        return "_5GSM_status";
    }
    throw std::invalid_argument("Not a Message Type Value !");
}

}; // namespace IE
}; // namespace _5GS
