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
        IE::PDU_session_type(IE::PDU_session_type::Value::IPv4v6),
        IE::SSC_mode(IE::SSC_mode::Value::SSC_mode_2),
        IE::SM_PDU_DN_request_container("abcdef@ghijk.lm"));

    std::cout << pdu_constructor.to_string() << std::endl;

    return 0;
}