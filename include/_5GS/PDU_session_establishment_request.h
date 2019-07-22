#pragma once

#include <_5GS/pdu_sm.h>
#include <_5GS/ie/PDU_session_type.h>

namespace _5GS
{
class PDU_session_establishment_request : public PduSm
{
private:
    int type = 0b11000001;


    _5GS::IE::PDU_session_type &pdu_session_type;

public:
    std::istream &operator>>(std::istream &input);
    std::ostream &operator<<(std::ostream &output);
};
} // namespace _5GS