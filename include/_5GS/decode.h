#pragma once

#include <vector>
#include <_5GS/pdu_5gs.h>
#include <_5GS/PDU_session_establishment_request.h>

namespace _5GS
{

/** @brief implements decoding of 5GS nas messages */
class Decode
{

public:
    /**
     * decode a 5GS nas message from a byte buffer.
     *
     * In case of failure exception is thrown.
     *
     * @param data buffer to decode
     *
     * @return number of bytes decoded
     */
    int decode(const std::vector<uint8_t> &data);
    /**
     * identify a 5GS nas message from a byte buffer.
     *
     * This method must be used when a nas message don't need to be fully decoded.
     * 
     * In case of failure exception is thrown.
     *
     * @param data buffer to identify.
     *
     * @return 5GS message type
     */
    IE::Message_type::Value identify(const std::vector<uint8_t> &data);

protected:
    /**
     * This method is called when an Registration request has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     * 
     * Example:
     * @include _5GS/Registration_request_identify.cpp
     */
    virtual void onRegistrationRequest(const std::vector<uint8_t> &data);

    /**
     * This method is called when an Registration accept has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     * 
     */
    virtual void onRegistrationAccept(const std::vector<uint8_t> &data);

    /**
     * This method is called when an Registration complete has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void onRegistrationComplete(const std::vector<uint8_t> &data);

    /**
     * This method is called when an Registration reject has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void onRegistrationReject(const std::vector<uint8_t> &data);

    /**
     * This method is called when an Deregistration request (UE originating) has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void onDeregistrationRequestUEOriginating(const std::vector<uint8_t> &data);

    /**
     * This method is called when an Deregistration accept (UE originating) has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void onDeregistrationAcceptUEOriginating(const std::vector<uint8_t> &data);

    /**
     * This method is called when an Deregistration request (UE terminated) has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void onDeregistrationRequestUETerminated(const std::vector<uint8_t> &data);

    /**
     * This method is called when an Deregistration accept (UE terminated) has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void onDeregistrationAcceptUETerminated(const std::vector<uint8_t> &data);

    /**
     * This method is called when a Service request has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void onServiceRequest(const std::vector<uint8_t> &data);

    /**
     * This method is called when a Service reject has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void onServiceReject(const std::vector<uint8_t> &data);

    /**
     * This method is called when a Service accept has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void onServiceAccept(const std::vector<uint8_t> &data);

    /**
     * This method is called when a configuration update command has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void onConfigurationUpdateCommand(const std::vector<uint8_t> &data);

    /**
     * This method is called when a configuration update complete has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void onConfigurationUpdateComplete(const std::vector<uint8_t> &data);

    /**
     * This method is called when a authentication request has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void onAuthenticationRequest(const std::vector<uint8_t> &data);

    /**
     * This method is called when a authentication response has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void onAuthenticationResponse(const std::vector<uint8_t> &data);

    /**
     * This method is called when a authentication failure has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void onAuthenticationFailure(const std::vector<uint8_t> &data);

    /**
     * This method is called when a authentication result has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void onAuthenticationResult(const std::vector<uint8_t> &data);

    /**
     * This method is called when a identity request has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void onIdentityRequest(const std::vector<uint8_t> &data);

    /**
     * This method is called when a identity response has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void onIdentityResponse(const std::vector<uint8_t> &data);

    /**
     * This method is called when a security mode command has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void onSecurityModeCommand(const std::vector<uint8_t> &data);

    /**
     * This method is called when a security mode complete has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void onSecurityModeComplete(const std::vector<uint8_t> &data);
    /**
     * This method is called when a security mode reject has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void onSecurityModeReject(const std::vector<uint8_t> &data);

    /**
     * This method is called when a 5GMM status PDU has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void on5GMMStatus(const std::vector<uint8_t> &data);

    /**
     * This method is called when a notification has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void onNotification(const std::vector<uint8_t> &data);

    /**
     * This method is called when a notification response has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void onNotificationResponse(const std::vector<uint8_t> &data);

    /**
     * This method is called when a UL NAS transport has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void onULNASTransport(const std::vector<uint8_t> &data);

    /**
     * This method is called when a DL NAS transport has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void onDLNASTransport(const std::vector<uint8_t> &data);

    /**
     * This method is called when an PDU session establishment request has been decoded from the decode method.
     *
     * @param pdu packet decoded from buffer
     *
     * Example:
     * @include _5GS/PDU_session_establishment_request_decode.cpp
     */
    virtual void onPduSessionEstablishmentRequest(const PDU_session_establishment_request &pdu);

    /**
     * This method is called when an PDU session establishment request has been identified by the @f identify method.
     *
     *
     * @param data  byte buffer identified
     * 
     * Example:
     * @include _5GS/PDU_session_establishment_request_identify.cpp
     */
    virtual void onPduSessionEstablishmentRequest(const std::vector<uint8_t> &data);

    /**
     * This method is called when an PDU session establishment accept has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void onPduSessionEstablishmentAccept(const std::vector<uint8_t> &data);

    /**
     * This method is called when an PDU session establishment reject has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void onPduSessionEstablishmentReject(const std::vector<uint8_t> &data);

    /**
     * This method is called when an PDU session authentication command has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void onPduSessionAuthenticationCommand(const std::vector<uint8_t> &data);

    /**
     * This method is called when an PDU session authentication complete has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void onPduSessionAuthenticationComplete(const std::vector<uint8_t> &data);

    /**
     * This method is called when an PDU session authentication result has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void onPduSessionAuthenticationResult(const std::vector<uint8_t> &data);

    /**
     * This method is called when an PDU session modification request has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void onPduSessionModificationRequest(const std::vector<uint8_t> &data);

    /**
     * This method is called when an PDU session modification reject has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void onPduSessionModificationReject(const std::vector<uint8_t> &data);

    /**
     * This method is called when an PDU session modification command has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void onPduSessionModificationCommand(const std::vector<uint8_t> &data);

    /**
     * This method is called when an PDU session modification complete has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void onPduSessionModificationComplete(const std::vector<uint8_t> &data);

    /**
     * This method is called when an PDU session modification command reject has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void onPduSessionModificationCommandReject(const std::vector<uint8_t> &data);

    /**
     * This method is called when a 5GSM status PDU has been identified by the @f identify method.
     *
     * @param data  byte buffer identified
     */
    virtual void on5GSMStatus(const std::vector<uint8_t> &data);

    /**
     * Deleting a derived class object using a pointer to a base class that has 
     * a non-virtual destructor results in undefined behavior.
     * To correct this situation, the base class should be defined with
     * a virtual destructor.
     */
    virtual ~Decode(){};

private:
    static IE::Message_type::Value identify_5GS_message_type(const std::vector<uint8_t> &data);
};

} // namespace _5GS
