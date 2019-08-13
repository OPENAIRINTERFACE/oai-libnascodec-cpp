#include <_5GS/ie/PDU_session_type.h>

using namespace _5GS::IE;

#include <test_template.h>

int main()
{
    code_V<PDU_session_type, PDU_session_type::Value>(
        PDU_session_type::Value::IPv4,
        std::vector<uint8_t>({0x01})
    );

    decode_V<PDU_session_type, PDU_session_type::Value>(
        std::vector<uint8_t>({0x03}),
        PDU_session_type::Value::IPv4v6
    );

    decode_invalid_value_V<PDU_session_type, PDU_session_type::Value>(
        std::vector<uint8_t>({0x08})
    );

    code_TV<PDU_session_type, PDU_session_type::Value>(
        0x90,
        PDU_session_type::Value::IPv6,
        std::vector<uint8_t>({0x92})
    );

    decode_TV<PDU_session_type, PDU_session_type::Value>(
        0x80,
        std::vector<uint8_t>({0x85}),
        PDU_session_type::Value::Ethernet
    );    

    decode_TV_with_invalid_iei<PDU_session_type, PDU_session_type::Value>(
        0x90,
        std::vector<uint8_t>({0x85}),
        PDU_session_type::Value::Ethernet
    );    
    
    return 0;
}