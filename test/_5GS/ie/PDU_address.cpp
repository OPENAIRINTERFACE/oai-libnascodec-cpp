#include <_5GS/ie/Session_AMBR.h>

using namespace _5GS::IE;

#include <test_template.h>

int main()
{
    code_LV<Session_AMBR, Session_AMBR_Fields>(
        Session_AMBR_Fields(
            Unit_for_Session_AMBR(Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_16_Kbps),
            512,
            Unit_for_Session_AMBR(Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_64_Kbps),
            768),
        std::vector<uint8_t>({6, 3, 2, 0, 4, 3, 0}));

    decode_LV<Session_AMBR, Session_AMBR_Fields>(
        std::vector<uint8_t>({6, 1, 4, 0, 2, 0, 85}),
        Session_AMBR_Fields(
            Unit_for_Session_AMBR(Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_1_Kbps),
            1024,
            Unit_for_Session_AMBR(Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_4_Kbps),
            85));
    // TODO
    decode_invalid_value_LV<Session_AMBR, Session_AMBR_Fields>(
        std::vector<uint8_t>({4, 6, 4, 0, 7, 0, 85}));

    return 0;
}