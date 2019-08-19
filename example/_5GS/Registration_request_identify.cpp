#include <_5GS/decode.h>
#include <buffers.h>

using namespace _5GS;

class DecodeExample : public _5GS::Decode
{
    void onRegistrationRequest(const std::vector<uint8_t> &data)
    {
        std::cout << dump_wireshark_with_ngap_encapsulation(data) ;
        std::cout << std::endl;
    }
};

int main()
{
    IE::Message_type::Value message_type;
    // FIXME update with a full registration request message
    const std::vector<uint8_t> data = { 0x7e, 0x00, 0x41 };

    DecodeExample decoder;
    message_type = decoder.identify(data);
    std::cout << IE::Message_type::value_to_string(message_type) << std::endl;
    return 0;
}