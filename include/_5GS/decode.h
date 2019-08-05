#pragma once

#include <vector>
#include <_5GS/pdu_5gs.h>
#include <_5GS/PDU_session_establishment_request.h>

namespace _5GS
{

class Decode
{

public:
    virtual void decode(std::vector<uint8_t> &data);
    int encode(std::vector<uint8_t> &data, Pdu5gs &pdu);

    virtual void onPduSessionEstablishmentRequest(PDU_session_establishment_request &pdu);
    //virtual void onPduRegisrationRequest(PDU_registration_request & pdu);
};

} // namespace _5GS