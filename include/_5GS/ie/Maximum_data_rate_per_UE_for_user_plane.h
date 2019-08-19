#include <information_element.h>

namespace _5GS
{

namespace IE
{

class Maximum_data_rate_per_UE_for_user_plane : public InformationElement
{
public:
    // TS 24.501 - 9.11.4.7.2

    enum class Value : uint8_t
    {
        _64_kbps,
        Full_data_rate = 255
    };

    explicit Maximum_data_rate_per_UE_for_user_plane() = default;
    explicit Maximum_data_rate_per_UE_for_user_plane(const Value &value);

    void set(const Value);
    Value get() const;

    int code_V(std::vector<uint8_t> &data) const;
    int decode_V(const std::vector<uint8_t> &data);

    static std::string value_to_string(const Value value);
    virtual std::string valueToString() const;
    virtual std::string getName() const;

    static Value uint8_t_to_Value(const uint8_t &byte);

    friend bool operator==(const Maximum_data_rate_per_UE_for_user_plane &a,
                           const Maximum_data_rate_per_UE_for_user_plane &b);

private:
    Value m_value;
};

} // namespace IE

} // namespace _5GS