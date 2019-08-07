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

protected:
    /**
     * This method is called when an PDU session establishment request has been decoded from the decode method.
     *
     * Example:
     * @include _5GS_decode_PDU_session_establishment_request.cpp
     *
     * @param pdu packet decoded from buffer
     */
    virtual void onPduSessionEstablishmentRequest(const PDU_session_establishment_request &pdu);
};

} // namespace _5GS
