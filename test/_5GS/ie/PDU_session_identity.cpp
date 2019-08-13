#include <_5GS/ie/PDU_session_identity.h>

using namespace _5GS::IE;

#include <test_template.h>

int main()
{
    code_V<PDU_session_identity, PDU_session_identity::Value>(
        PDU_session_identity::Value::PDU_session_identity_value_5,
        std::vector<uint8_t>({5})
    );

    decode_V<PDU_session_identity, PDU_session_identity::Value>(
        std::vector<uint8_t>({12}),
        PDU_session_identity::Value::PDU_session_identity_value_12
    );

    decode_V<PDU_session_identity, PDU_session_identity::Value>(
        std::vector<uint8_t>({17}),
        PDU_session_identity::Value::reserved
    );

    return 0;
}