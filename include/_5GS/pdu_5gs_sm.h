#pragma once

#include <_5GS/pdu_5gs.h>

#include <_5GS/ie/PDU_session_identity.h>
#include <_5GS/ie/Procedure_transaction_identity.h>

namespace _5GS
{
class Pdu5gsSm : public Pdu5gs
{

public:
    // for SM messages
    // TODO private or protected IEs ?
    IE::PDU_session_identity m_pdu_session_identity;
    IE::Procedure_transaction_identity m_procedure_transaction_identity;

    Pdu5gsSm(const IE::PDU_session_identity psi = IE::PDU_session_identity(IE::PDU_session_identity::Value::No_PDU_session_identity_assigned),
             const IE::Procedure_transaction_identity pti = IE::Procedure_transaction_identity(IE::Procedure_transaction_identity::Value::No_procedure_transaction_identity_assigned));

    virtual int decode(const std::vector<uint8_t> &data);

    int codeSMHeader(std::vector<uint8_t> &data) const;

    virtual std::string header_to_string() const;
};
} // namespace _5GS
