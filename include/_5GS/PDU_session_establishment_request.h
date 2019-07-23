#pragma once

#include <_5GS/pdu_sm.h>
#include <_5GS/ie/PDU_session_type.h>

namespace _5GS
{
class PDU_session_establishment_request : public PduSm
{

public:
    std::istream & operator>>(std::istream & input);
    std::ostream & operator<<(std::ostream & output);

private:
    static const Type type = Type::PDU_session_establishment_request;
    IE::PDU_session_type pdu_session_type; // Optional
};
} // namespace _5GS