#pragma once

#include <_5GS/pdu_5gs_sm.h>
#include <_5GS/ie/PDU_session_type.h>

namespace _5GS
{
class PDU_session_establishment_request : public Pdu5gsSm
{

public:
    IE::PDU_session_type pdu_session_type;

    int code_ex(std::vector<uint8_t> & data) const;

private:
    // Optional ies
};
} // namespace _5GS