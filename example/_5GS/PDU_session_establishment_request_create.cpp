#include <_5GS/PDU_session_establishment_request.h>

using namespace _5GS;

int main()
{
    // Create pdu using constructor

    PDU_session_establishment_request pdu_constructor(
        IE::PDU_session_identity(IE::PDU_session_identity::Value::PDU_session_identity_value_3),
        IE::Procedure_transaction_identity(31),
        IE::Integrity_protection_maximum_data_rate(
            IE::Integrity_protection_maximum_data_rate::Value(
                IE::Maximum_data_rate_per_UE_for_user_plane(IE::Maximum_data_rate_per_UE_for_user_plane::Value::_64_kbps),
                IE::Maximum_data_rate_per_UE_for_user_plane(IE::Maximum_data_rate_per_UE_for_user_plane::Value::Full_data_rate))),
        // optional - can be omitted
        IE::PDU_session_type(IE::PDU_session_type::Value::IPv4v6));

    std::cout << pdu_constructor.to_string() << std::endl;

    // create another pdu using getter and setters

    PDU_session_establishment_request pdu_setters;

    // for header (mandatory)
    pdu_setters.m_pdu_session_identity.set(IE::PDU_session_identity::Value::PDU_session_identity_value_5);
    pdu_setters.m_procedure_transaction_identity.set(250);
    // mandatory
    pdu_setters.m_integrity_protection_maximum_data_rate.m_fields.m_downlink.set(IE::Maximum_data_rate_per_UE_for_user_plane::Value::Full_data_rate);
    pdu_setters.m_integrity_protection_maximum_data_rate.m_fields.m_uplink.set(IE::Maximum_data_rate_per_UE_for_user_plane::Value::_64_kbps);
    // optionals
    pdu_setters.m_pdu_session_type.set(IE::PDU_session_type::Value::IPv4);

    std::cout << pdu_setters.to_string() << std::endl;

    return 0;
}