#pragma once

#include <_5GS/PDU_session_establishment_request.h>

namespace _5GS
{
// FIXME rename to identify NAS protocol
class Codec
{

public:
    void decode(std::istream & input);
    std::ostream encode(Pdu & pdu);

    virtual void onPduSessionEstablishmentRequest(PDU_session_establishment_request & pdu);
    //virtual void onPduRegisrationRequest(PDU_registration_request & pdu);
};
} // namespace _5GS