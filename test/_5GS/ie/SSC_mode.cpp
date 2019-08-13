#include <_5GS/ie/SSC_mode.h>

using namespace _5GS::IE;

#include <test_template.h>

int main()
{
    code_V<SSC_mode, SSC_mode::Value>(
        SSC_mode::Value::SSC_mode_1,
        std::vector<uint8_t>({0x01}));

    decode_V<SSC_mode, SSC_mode::Value>(
        std::vector<uint8_t>({0x03}),
        SSC_mode::Value::SSC_mode_3);

    decode_invalid_value_V<SSC_mode, SSC_mode::Value>(
        std::vector<uint8_t>({0x08}));

    code_TV<SSC_mode, SSC_mode::Value>(
        0x90,
        SSC_mode::Value::SSC_mode_2,
        std::vector<uint8_t>({0x92}));

    decode_TV<SSC_mode, SSC_mode::Value>(
        0x80,
        std::vector<uint8_t>({0x85}),
        SSC_mode::Value::unused_2);

    decode_TV_with_invalid_iei<SSC_mode, SSC_mode::Value>(
        0x80,
        std::vector<uint8_t>({0x95}),
        SSC_mode::Value::unused_2);


    return 0;
}