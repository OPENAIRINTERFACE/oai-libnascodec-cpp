#include <_5GS/ie/Message_type.h>

using namespace _5GS::IE;

#include <test_template.h>

int main()
{
    code_V<Message_type, Message_type::Value>(
        Message_type::Value::PDU_session_authentication_command,
        std::vector<uint8_t>({0b11000101})
    );

    decode_V<Message_type, Message_type::Value>(
        std::vector<uint8_t>({0b11000001}),
        Message_type::Value::PDU_session_establishment_request
    );

    decode_invalid_value_V<Message_type, Message_type::Value>(
        std::vector<uint8_t>({0x08})
    );
  
    return 0;
}