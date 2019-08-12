#include <_5GS/ie/Integrity_protection_maximum_data_rate.h>

using namespace _5GS::IE;

#include <test_template.h>

int main()
{
    code_V<Integrity_protection_maximum_data_rate, Integrity_protection_maximum_data_rate::Value>(
        Integrity_protection_maximum_data_rate::Value(
            Maximum_data_rate_per_UE_for_user_plane(Maximum_data_rate_per_UE_for_user_plane::Value::_64_kbps),
            Maximum_data_rate_per_UE_for_user_plane(Maximum_data_rate_per_UE_for_user_plane::Value::Full_data_rate)),
        std::vector<uint8_t>({0x00, 0xff}));

    code_V<Integrity_protection_maximum_data_rate, Integrity_protection_maximum_data_rate::Value>(
        Integrity_protection_maximum_data_rate::Value(
            Maximum_data_rate_per_UE_for_user_plane(Maximum_data_rate_per_UE_for_user_plane::Value::Full_data_rate),
            Maximum_data_rate_per_UE_for_user_plane(Maximum_data_rate_per_UE_for_user_plane::Value::_64_kbps)),
        std::vector<uint8_t>({0xff, 0x00}));

    decode_V<Integrity_protection_maximum_data_rate, Integrity_protection_maximum_data_rate::Value>(
        std::vector<uint8_t>({255, 0}),
        Integrity_protection_maximum_data_rate::Value(
            Maximum_data_rate_per_UE_for_user_plane(Maximum_data_rate_per_UE_for_user_plane::Value::Full_data_rate),
            Maximum_data_rate_per_UE_for_user_plane(Maximum_data_rate_per_UE_for_user_plane::Value::_64_kbps)));

    // The receiving entity shall treat a spare value as "64 kbps".
    decode_V<Integrity_protection_maximum_data_rate, Integrity_protection_maximum_data_rate::Value>(
        std::vector<uint8_t>({200, 255}),
        Integrity_protection_maximum_data_rate::Value(
            Maximum_data_rate_per_UE_for_user_plane(Maximum_data_rate_per_UE_for_user_plane::Value::_64_kbps),
            Maximum_data_rate_per_UE_for_user_plane(Maximum_data_rate_per_UE_for_user_plane::Value::Full_data_rate)));

    return 0;
}