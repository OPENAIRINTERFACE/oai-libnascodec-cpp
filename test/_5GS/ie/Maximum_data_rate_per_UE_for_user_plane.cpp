#include <_5GS/ie/Maximum_data_rate_per_UE_for_user_plane.h>

using namespace _5GS::IE;

#include <test_template.h>

int main()
{
    code_V<Maximum_data_rate_per_UE_for_user_plane, Maximum_data_rate_per_UE_for_user_plane::Value>(
        Maximum_data_rate_per_UE_for_user_plane::Value::_64_kbps,
        std::vector<uint8_t>({0x00})
    );

    code_V<Maximum_data_rate_per_UE_for_user_plane, Maximum_data_rate_per_UE_for_user_plane::Value>(
        Maximum_data_rate_per_UE_for_user_plane::Value::Full_data_rate,
        std::vector<uint8_t>({0xff})
    );

    decode_V<Maximum_data_rate_per_UE_for_user_plane, Maximum_data_rate_per_UE_for_user_plane::Value>(
        std::vector<uint8_t>({255}),
        Maximum_data_rate_per_UE_for_user_plane::Value::Full_data_rate
    );

    // The receiving entity shall treat a spare value as "64 kbps".
    decode_V<Maximum_data_rate_per_UE_for_user_plane, Maximum_data_rate_per_UE_for_user_plane::Value>(
        std::vector<uint8_t>({200}),
        Maximum_data_rate_per_UE_for_user_plane::Value::_64_kbps
    );

    return 0;
}