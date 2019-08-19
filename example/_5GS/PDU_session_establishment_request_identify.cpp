#include <_5GS/decode.h>
#include <buffers.h>

using namespace _5GS;

class DecodeExample : public _5GS::Decode
{
    void onPduSessionEstablishmentRequest(const std::vector<uint8_t> &data)
    {
        std::cout << dump_wireshark_with_ngap_encapsulation(data) ;
        std::cout << std::endl;
    }
};

int main()
{
    IE::Message_type::Value message_type;
    const std::vector<uint8_t> data = { 0x2e, 0x03, 0x1f, 0xc1, 0x00, 0xff, 0x93 };

    DecodeExample decoder;
    message_type = decoder.identify(data);
    std::cout << IE::Message_type::value_to_string(message_type) << std::endl;
    return 0;
}