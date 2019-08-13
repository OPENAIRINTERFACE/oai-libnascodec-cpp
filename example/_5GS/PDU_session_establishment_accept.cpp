#include <cassert>

#include <nas_helpers.h>
#include <_5GS/PDU_session_establishment_accept.h>

using namespace _5GS;

int main()
{

    std::vector<uint8_t> data;
    PDU_session_establishment_accept pdu(
        IE::PDU_session_identity(IE::PDU_session_identity::Value::PDU_session_identity_value_3),
        IE::Procedure_transaction_identity(31),
        IE::Selected_PDU_session_type(IE::PDU_session_type::Value::IPv4),
        IE::Selected_SSC_mode(IE::Selected_SSC_mode::Value::SSC_mode_2),
        // optional - can be omitted
        IE::DNN("abc.def@ghi")
    );

    int size = pdu.code(data);

    // print info to terminal to stderr
    std::cerr << dump_wireshark(data);
    std::cerr << "size = " << size << " | size of buffer = " << data.size() << "\n";
    std::cerr << pdu.to_string() << "\n";

    // dump to stdout in order to redirect to a file and inspect with wireshark
    std::cout << dump_wireshark_with_ngap_encapsulation(data) << std::endl;

    // FIXME reintegrate when mandatory iei are done
    //const std::vector<uint8_t> result = {0x2e, 0x03, 0x1f, 0xc1, 0x00, 0xff, 0x93};
    //assert(data == result);
    return 0;
}