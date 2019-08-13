#include <nas.h>
#include <_5GS/decode.h>
#include <_5GS/ie/Message_type.h>
#include <nas_helpers.h>

using namespace _5GS;

int Decode::decode(const std::vector<uint8_t> &data)
{
    IE::Message_type::Value message_type = Decode::identify_5GS_message_type(data);
    std::vector<uint8_t> tmp;
    int size = 0;

    switch (message_type)
    {
    case IE::Message_type::Value::PDU_session_establishment_request:
    {
        PDU_session_establishment_request pdu;
        size = pdu.decode(data);
        onPduSessionEstablishmentRequest(pdu);
        break;
    }
    default:
        throw NasCodecException(std::string("Not implemented: ") + IE::Message_type::value_to_string(message_type));
    }
    return size;
}

IE::Message_type::Value Decode::identify(const std::vector<uint8_t> &data)
{
    IE::Message_type::Value message_type = Decode::identify_5GS_message_type(data);

    switch (message_type)
    {
    case IE::Message_type::Value::Registration_request:
    {
        onRegistrationRequest(data);
        break;
    }
    case IE::Message_type::Value::Registration_accept:
    {
        onRegistrationAccept(data);
        break;
    }
    case IE::Message_type::Value::Registration_complete:
    {
        onRegistrationComplete(data);
        break;
    }
    case IE::Message_type::Value::Deregistration_request__UE_originating_:
    {
        onDeregistrationRequestUEOriginating(data);
        break;
    }
    case IE::Message_type::Value::Deregistration_accept__UE_originating_:
    {
        onDeregistrationAcceptUEOriginating(data);
        break;
    }
    case IE::Message_type::Value::Deregistration_request__UE_terminated_:
    {
        onDeregistrationRequestUETerminated(data);
        break;
    }
    case IE::Message_type::Value::Deregistration_accept__UE_terminated_:
    {
        onDeregistrationAcceptUETerminated(data);
        break;
    }
    case IE::Message_type::Value::Service_request:
    {
        onServiceRequest(data);
        break;
    }
    case IE::Message_type::Value::Service_reject:
    {
        onServiceReject(data);
        break;
    }
    case IE::Message_type::Value::Service_accept:
    {
        onServiceAccept(data);
        break;
    }
    case IE::Message_type::Value::Configuration_update_command:
    {
        onConfigurationUpdateCommand(data);
        break;
    }
    case IE::Message_type::Value::Configuration_update_complete:
    {
        onConfigurationUpdateComplete(data);
        break;
    }
    case IE::Message_type::Value::Authentication_request:
    {
        onAuthenticationRequest(data);
        break;
    }
    case IE::Message_type::Value::Authentication_response:
    {
        onAuthenticationResponse(data);
        break;
    }
    case IE::Message_type::Value::Authentication_failure:
    {
        onAuthenticationFailure(data);
        break;
    }
    case IE::Message_type::Value::Authentication_result:
    {
        onAuthenticationResult(data);
        break;
    }
    case IE::Message_type::Value::Identity_request:
    {
        onIdentityRequest(data);
        break;
    }
    case IE::Message_type::Value::Identity_response:
    {
        onIdentityResponse(data);
        break;
    }
    case IE::Message_type::Value::Security_mode_command:
    {
        onSecurityModeCommand(data);
        break;
    }
    case IE::Message_type::Value::Security_mode_complete:
    {
        onSecurityModeComplete(data);
        break;
    }
    case IE::Message_type::Value::Security_mode_reject:
    {
        onSecurityModeReject(data);
        break;
    }
    case IE::Message_type::Value::_5GMM_status:
    {
        on5GMMStatus(data);
        break;
    }
    case IE::Message_type::Value::Notification:
    {
        onNotificationResponse(data);
        break;
    }
    case IE::Message_type::Value::UL_NAS_transport:
    {
        onULNASTransport(data);
        break;
    }
    case IE::Message_type::Value::DL_NAS_transport:
    {
        onDLNASTransport(data);
        break;
    }
    case IE::Message_type::Value::PDU_session_establishment_request:
    {
        onPduSessionEstablishmentRequest(data);
        break;
    }
    case IE::Message_type::Value::PDU_session_establishment_accept:
    {
        onPduSessionEstablishmentAccept(data);
        break;
    }
    case IE::Message_type::Value::PDU_session_establishment_reject:
    {
        onPduSessionEstablishmentReject(data);
        break;
    }
    case IE::Message_type::Value::PDU_session_authentication_command:
    {
        onPduSessionAuthenticationCommand(data);
        break;
    }
    case IE::Message_type::Value::PDU_session_authentication_complete:
    {
        onPduSessionAuthenticationComplete(data);
        break;
    }
    case IE::Message_type::Value::PDU_session_authentication_result:
    {
        onPduSessionAuthenticationResult(data);
        break;
    }
    case IE::Message_type::Value::PDU_session_modification_request:
    {
        onPduSessionModificationRequest(data);
        break;
    }
    case IE::Message_type::Value::PDU_session_modification_reject:
    {
        onPduSessionModificationReject(data);
        break;
    }
    case IE::Message_type::Value::PDU_session_modification_command:
    {
        onPduSessionModificationCommand(data);
        break;
    }
    case IE::Message_type::Value::PDU_session_modification_complete:
    {
        onPduSessionModificationComplete(data);
        break;
    }
    case IE::Message_type::Value::PDU_session_modification_command_reject:
    {
        onPduSessionModificationCommandReject(data);
        break;
    }
    case IE::Message_type::Value::_5GSM_status:
    {
        on5GSMStatus(data);
        break;
    }
    default:
        throw NasCodecException(std::string("Not implemented: ") + IE::Message_type::value_to_string(message_type));
    }
    return message_type;
}

IE::Message_type::Value Decode::identify_5GS_message_type(const std::vector<uint8_t> &data)
{
    IE::Message_type message_type;
    std::vector<uint8_t> tmp;

    switch (Nas::decodeProtocolDiscriminator(data))
    {
    case Nas::ProtocolDiscriminator::_5GS_session_management_messages:
        tmp.push_back(data[3]);
        message_type.decode(tmp, InformationElement::Format::V);
    case Nas::ProtocolDiscriminator::_5GS_mobility_management_messages:
        tmp.push_back(data[2]);
        message_type.decode(tmp, InformationElement::Format::V);
        break;
    default:
        throw NasCodecException("This is not a 5GS nas message, dump follows:\n" + std::string(dump_wireshark(data)));
    }
    return message_type.get();
}

// PDU stubs

// MOBILITY MESSAGES

// Registration

void Decode::onRegistrationRequest(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

void Decode::onRegistrationAccept(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

void Decode::onRegistrationComplete(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

void Decode::onRegistrationReject(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

// Deregistration

void Decode::onDeregistrationRequestUEOriginating(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

void Decode::onDeregistrationAcceptUEOriginating(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

void Decode::onDeregistrationRequestUETerminated(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

void Decode::onDeregistrationAcceptUETerminated(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

// Service

void Decode::onServiceRequest(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

void Decode::onServiceReject(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

void Decode::onServiceAccept(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

// Authentication & security

void Decode::onConfigurationUpdateCommand(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

void Decode::onConfigurationUpdateComplete(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

void Decode::onAuthenticationRequest(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

void Decode::onAuthenticationResponse(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

void Decode::onAuthenticationFailure(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

void Decode::onAuthenticationResult(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

void Decode::onIdentityRequest(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

void Decode::onIdentityResponse(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

void Decode::onSecurityModeCommand(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

void Decode::onSecurityModeComplete(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

void Decode::onSecurityModeReject(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

// Notification & transport

void Decode::on5GMMStatus(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

void Decode::onNotification(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

void Decode::onNotificationResponse(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

void Decode::onULNASTransport(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

void Decode::onDLNASTransport(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

// SESSION MESSAGES

// Establishment

void Decode::onPduSessionEstablishmentRequest(const PDU_session_establishment_request &pdu)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

void Decode::onPduSessionEstablishmentRequest(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

void Decode::onPduSessionEstablishmentAccept(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

void Decode::onPduSessionEstablishmentReject(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

// Authentication

void Decode::onPduSessionAuthenticationCommand(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

void Decode::onPduSessionAuthenticationComplete(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

void Decode::onPduSessionAuthenticationResult(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

// Modification

void Decode::onPduSessionModificationRequest(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

void Decode::onPduSessionModificationReject(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

void Decode::onPduSessionModificationCommand(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

void Decode::onPduSessionModificationComplete(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

void Decode::onPduSessionModificationCommandReject(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}

// Status

void Decode::on5GSMStatus(const std::vector<uint8_t> &data)
{
    throw NasCodecException(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
}