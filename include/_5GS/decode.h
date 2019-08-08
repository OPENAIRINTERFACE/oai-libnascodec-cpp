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

     * Example:
     * @include _5GS/PDU_session_establishment_request_identify.cpp
     */
    virtual void onPduSessionEstablishmentRequest(const std::vector<uint8_t> &data);

private:
    static IE::Message_type::Value identify_5GS_message_type(const std::vector<uint8_t> &data);
};

} // namespace _5GS
