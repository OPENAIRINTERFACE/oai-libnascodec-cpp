#include <vector>

#include <_5GS/decode.h>
#include <_5GS/PDU_session_establishment_request.h>

using namespace _5GS;

class DecodeExample : public Decode
{
    void onPduSessionEstablishmentRequest(const PDU_session_establishment_request &pdu)
    {
        std::cout << pdu.to_string();
    }
};

int main()
{
    const std::vector<uint8_t> data = { 0x2e, 0x03, 0x1f, 0xc1, 0x00, 0xff, 0x93 };
    int size;

    DecodeExample decoder;
    size = decoder.decode(data);
    std::cout << "Decoded " << size << " bytes." << std::endl;
    return 0;
}