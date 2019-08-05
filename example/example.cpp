#include <stdio.h>
#include <vector>

#include <helpers.h>
#include <_5GS/decode.h>
#include <_5GS/PDU_session_establishment_request.h>

using namespace _5GS;

void makePduExample(PDU_session_establishment_request &pdu)
{
    PDU_session_establishment_request pdu_tmp(
        IE::PDU_session_identity(IE::PDU_session_identity::Value::PDU_session_identity_value_3),
        IE::Procedure_transaction_identity(31),
        IE::Integrity_protection_maximum_data_rate(
            IE::Integrity_protection_maximum_data_rate::Value::_64_kbps,
            IE::Integrity_protection_maximum_data_rate::Value::Full_data_rate),
        // optional
        IE::PDU_session_type(IE::PDU_session_type::Value::IPv4v6));

    pdu = pdu_tmp;
}

void makePduExample_using_setters(PDU_session_establishment_request &pdu)
{
    PDU_session_establishment_request pdu_tmp;
    // for header (mandatory)
    pdu_tmp.pdu_session_identity.set(IE::PDU_session_identity::Value::PDU_session_identity_value_5);
    pdu_tmp.procedure_transaction_identity.set(250);
    // mandatory
    pdu_tmp.integrity_protection_maximum_data_rate.setDownlink(IE::Integrity_protection_maximum_data_rate::Value::Full_data_rate);
    pdu_tmp.integrity_protection_maximum_data_rate.setUplink(IE::Integrity_protection_maximum_data_rate::Value::_64_kbps);
    // optionals
    pdu_tmp.pdu_session_type.set(IE::PDU_session_type::Value::IPv4);
    pdu = pdu_tmp;
}

int example_with_PDU()
{
    PDU_session_establishment_request pdu_sm;
    std::cout << pdu_sm.to_string() << "\n";
    makePduExample(pdu_sm);

    std::vector<uint8_t> data;

    int size = pdu_sm.code_ex(data);

    std::cout << data;
    std::cerr << "size = " << size << " | size of buffer = " << data.size() << "\n";
    std::cout << pdu_sm.to_string() << "\n";

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

class DecodeExample : public _5GS::Decode
{
    void onPduSessionEstablishmentRequest(PDU_session_establishment_request &pdu)
    {
        std::cout << pdu.to_string();
    }
};

int example_decoding_PDU()
{
    PDU_session_establishment_request pdu;
    makePduExample(pdu);
    std::vector<uint8_t> data;

    pdu.code_ex(data);

    DecodeExample decoder;
    decoder.decode(data);

    return 0;
}

int main()
{
    //return example_with_ie();
    //return example_with_PDU();
    return example_decoding_PDU();
}