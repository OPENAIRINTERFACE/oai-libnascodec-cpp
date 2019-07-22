#include <stdio.h>
#include <vector>

#include <_5GS/PDU_session_establishment_request.h>
//#include <_5GS/ie/PDU_session_ID.h>
//#include <_5GS/ie/PDU_session_type.h>
//#include <nas.h>
//#include <information_element.h>

int main()
{
    // IE examples

    //_5GS::PDU_session_establishment_request pdu;
    _5GS::IE::PDU_session_ID session_id;
    session_id.set(_5GS::IE::PDU_session_ID::Value::PDU_session_identity_value_3);
    std::vector<uint8_t> data1 = session_id.code(InformationElement::Format::V);

    _5GS::IE::PDU_session_type session_type;
    session_type.set(_5GS::IE::PDU_session_type::Value::IPv6);
    std::vector<uint8_t> data2 = session_type.code(InformationElement::Format::TV);

    std::cout << data1 << data2;

    return 0;
}