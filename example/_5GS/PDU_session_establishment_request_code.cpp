#include <cassert>

#include <nas_helpers.h>
#include <_5GS/PDU_session_establishment_request.h>

using namespace _5GS;

int main()
{
    std::vector<uint8_t> data;

    PDU_session_establishment_request pdu(
        IE::PDU_session_identity(IE::PDU_session_identity::Value::PDU_session_identity_value_3),
        IE::Procedure_transaction_identity(31),
        IE::Integrity_protection_maximum_data_rate(
            IE::Integrity_protection_maximum_data_rate::Value(
                IE::Maximum_data_rate_per_UE_for_user_plane(IE::Maximum_data_rate_per_UE_for_user_plane::Value::_64_kbps),
                IE::Maximum_data_rate_per_UE_for_user_plane(IE::Maximum_data_rate_per_UE_for_user_plane::Value::Full_data_rate))),
        // optional - can be omitted
        IE::PDU_session_type(IE::PDU_session_type::Value::IPv4v6),
        IE::SSC_mode(IE::SSC_mode::Value::SSC_mode_2));

    int size = pdu.code(data);

    // print info to terminal to stderr
    std::cerr << dump_wireshark(data);
    std::cerr << "size = " << size << " | size of buffer = " << data.size() << "\n";
    std::cerr << pdu.to_string() << "\n";

    // dump to stdout in order to redirect to a file and inspect with wireshark
    std::cout << dump_wireshark_with_ngap_encapsulation(data);

    const std::vector<uint8_t> result = {0x2e, 0x03, 0x1f, 0xc1, 0x00, 0xff, 0x93, 0xa2};
    assert(data == result);

    return 0;
}