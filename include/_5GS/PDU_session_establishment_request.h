#pragma once

#include <_5GS/pdu_5gs_sm.h>
#include <_5GS/ie/PDU_session_type.h>
#include <_5GS/ie/Integrity_protection_maximum_data_rate.h>

namespace _5GS
{
class PDU_session_establishment_request : public Pdu5gsSm
{

public:
    // Mandatory
    IE::Integrity_protection_maximum_data_rate integrity_protection_maximum_data_rate;
    IE::PDU_session_type pdu_session_type;

    PDU_session_establishment_request();

    virtual int code_ex(std::vector<uint8_t> &data) const;
};
} // namespace _5GS