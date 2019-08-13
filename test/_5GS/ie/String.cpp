#include <_5GS/ie/String.h>

using namespace _5GS::IE;

#include <test_template.h>

int main()
{
    code_TLV<String, std::string>(
        0x40,
        "1234",
        std::vector<uint8_t>({0x40, 0x04, 0x31, 0x32, 0x33, 0x34}));

    decode_TLV<String, std::string>(
        0x35,
        std::vector<uint8_t>({0x35, 0x03, 0x36, 0x35, 0x34}),
        "654");

    decode_TLV_with_invalid_iei<String, std::string>(
        0x35,
        std::vector<uint8_t>({0x34, 0x03, 0x36, 0x35, 0x34}),
        "654");

    return 0;
}