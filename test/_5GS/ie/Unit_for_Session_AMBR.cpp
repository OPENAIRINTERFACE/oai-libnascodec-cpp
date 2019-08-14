#include <_5GS/ie/Unit_for_Session_AMBR.h>

using namespace _5GS::IE;

#include <test_template.h>

int main()
{
    code_V<Unit_for_Session_AMBR, Unit_for_Session_AMBR::Value>(
        Unit_for_Session_AMBR::Value::value_is_not_used,
        std::vector<uint8_t>({0})
    );

    code_V<Unit_for_Session_AMBR, Unit_for_Session_AMBR::Value>(
        Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_16_Mbps,
        std::vector<uint8_t>({8})
    );

    decode_V<Unit_for_Session_AMBR, Unit_for_Session_AMBR::Value>(
        std::vector<uint8_t>({14}),
        Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_64_Gbps
    );

    // The receiving entity shall treat a spare value as "..._256_Pbps".
    decode_V<Unit_for_Session_AMBR, Unit_for_Session_AMBR::Value>(
        std::vector<uint8_t>({200}),
        Unit_for_Session_AMBR::Value::value_is_incremented_in_multiple_of_256_Pbps
    );

    return 0;
}