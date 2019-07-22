#pragma once

#include <_5GS/PDU_session_establishment_request.h>

namespace _5GS
{
class codec
{

public:
    void decode(std::istream &input);
    std::ostream encode(Pdu &pdu);

    virtual void onPduSessionEstablishmentRequest(_5GS::PDU_session_establishment_request &pdu);

};
} // namespace _5GS