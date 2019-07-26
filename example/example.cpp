#include <stdio.h>
#include <vector>

#include <helpers.h>
#include <_5GS/PDU_session_establishment_request.h>

using namespace _5GS;

PDU_session_establishment_request makePduExample()
{
    PDU_session_establishment_request pdu;
    // for header (mandatory)
    pdu.pdu_session_identity.set(IE::PDU_session_identity::Value::PDU_session_identity_value_3);
    pdu.procedure_transaction_identity.set(31);
    // mandatory 
    pdu.integrity_protection_maximum_data_rate.setDownlink(IE::Integrity_protection_maximum_data_rate::Value::_64_kbps);
    pdu.integrity_protection_maximum_data_rate.setUplink(IE::Integrity_protection_maximum_data_rate::Value::Full_data_rate);
    // optionals
    pdu.pdu_session_type.set(IE::PDU_session_type::Value::IPv6);
    return pdu;
}

int example_with_PDU()
{
    //Pdu5gs pdu = makePduExample(); // TODO learn c++ :)
    PDU_session_establishment_request pdu = makePduExample();
    std::vector<uint8_t> data;

    int size = pdu.code_ex(data);
    if (size < 0)
    {
        std::cerr << "Error coding PDU session establishment request\n";
        return -1;
    }
    std::cout << data;
    std::cerr << "size = " << size << "\n";
    return 0;
}

int example_with_ie()
{
    // IE examples

    IE::PDU_session_identity session_id;
    std::vector<uint8_t> data1;

    session_id.set(IE::PDU_session_identity::Value::PDU_session_identity_value_3);

    if (session_id.code(data1, InformationElement::Format::V) < 0)
    {
        std::cerr << "Error coding IE PDU session identity\n";
        return -1;
    }

    IE::PDU_session_type session_type;
    std::vector<uint8_t> data2;

    session_type.set(IE::PDU_session_type::Value::IPv6);

    if (session_type.code(data2, InformationElement::Format::TV) < 0)
    {
        std::cerr << "Error coding IE PDU session type\n";
        return -1;
    }

    std::cout << data1 << data2;
    return 0;
}

int main()
{
    //return example_with_ie();
    return example_with_PDU();
}