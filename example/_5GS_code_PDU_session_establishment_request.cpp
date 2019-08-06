#include <helpers.h>
#include <_5GS/PDU_session_establishment_request.h>

using namespace _5GS;

int main()
{
    std::vector<uint8_t> data;

    PDU_session_establishment_request pdu(
        IE::PDU_session_identity(IE::PDU_session_identity::Value::PDU_session_identity_value_3),
        IE::Procedure_transaction_identity(31),
        IE::Integrity_protection_maximum_data_rate(
            IE::Integrity_protection_maximum_data_rate::Value::_64_kbps,
            IE::Integrity_protection_maximum_data_rate::Value::Full_data_rate),
        // optional - can be omitted
        IE::PDU_session_type(IE::PDU_session_type::Value::IPv4v6));

    int size = pdu.code_ex(data);

    // print info to terminal to stderr
    std::cerr << dump_wireshark(data);
    std::cerr << "size = " << size << " | size of buffer = " << data.size() << "\n";
    std::cerr << pdu.to_string() << "\n";

    // dump to stdout in order to redirect to a file and inspect with wireshark
    std::cout << dump_wireshark_with_ngap_encapsulation(data);

    return 0;
}