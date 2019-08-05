#pragma once

#include <vector>
#include <_5GS/pdu_5gs.h>
#include <_5GS/PDU_session_establishment_request.h>

namespace _5GS
{

class Decode
{

public:
    virtual void decode(const std::vector<uint8_t> &data);

    virtual void onPduSessionEstablishmentRequest(const PDU_session_establishment_request &pdu);
};

} // namespace _5GS
