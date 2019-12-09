#include <_5GS/ie/PDU_address.h>

using namespace _5GS::IE;

#include <test_template.h>

int main()
{

    // IPv4
    code_TLV<PDU_address, PDU_address::Value>(
        0x90,
        PDU_address::Value(0xc0a80001),
        std::vector<uint8_t>({0x90, 1, 0xc0, 0xa8, 0x00, 0x01}));

    // IPv6

    ASSERT_EXCEPTION((PDU_address::Value(std::string("1234567890"))), NasCodecException);

    code_TLV<PDU_address, PDU_address::Value>(
        0x90,
        PDU_address::Value(std::string("12345678")),
        std::vector<uint8_t>({0x90, 2, '1', '2', '3', '4', '5', '6', '7', '8'}));

    code_TLV<PDU_address, PDU_address::Value>(
        0x90,
        PDU_address::Value(std::string("1234")),
        std::vector<uint8_t>({0x90, 2, '1', '2', '3', '4', 0, 0, 0, 0}));

    // IPv4&v6
    code_TLV<PDU_address, PDU_address::Value>(
        0x90,
        PDU_address::Value(std::string("1234"), 0xc0a80001),
        std::vector<uint8_t>({0x90, 3, '1', '2', '3', '4', 0, 0, 0, 0, 0xc0, 0xa8, 0x00, 0x01}));

    // DECODE

    // IPv4
    decode_TLV<PDU_address, PDU_address::Value>(
        0x55,
        std::vector<uint8_t>({0x55, 1, 0xc0, 0xa8, 0x00, 0x01}),
        PDU_address::Value(0xc0a80001));

    // IPv6
    decode_TLV<PDU_address, PDU_address::Value>(
        0x90,
        std::vector<uint8_t>({0x90, 2, '1', '2', '3', '4', 0, 0, 0, 0}),
        PDU_address::Value(std::string("1234")));

    // IPv4&v6
    decode_TLV<PDU_address, PDU_address::Value>(
        0x90,
        std::vector<uint8_t>({0x90, 3, '1', '2', '3', '4', 0, 0, 0, 0, 0xc0, 0xa8, 0x00, 0x01}),
        PDU_address::Value(std::string("1234"), 0xc0a80001));

    // invalid type 0
    decode_invalid_TLV<PDU_address, PDU_address::Value>(
        0x90,
        std::vector<uint8_t>({0x90, 0, '1', '2', '3', '4', 0, 0, 0, 0, 0x12, 0x34, 0x56, 0x78}));

    // invalid type 4
    decode_invalid_TLV<PDU_address, PDU_address::Value>(
        0x90,
        std::vector<uint8_t>({0x90, 4, '1', '2', '3', '4', 0, 0, 0, 0, 0x12, 0x34, 0x56, 0x78}));

    return 0;
}
