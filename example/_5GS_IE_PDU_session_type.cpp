#include <cassert>

#include <_5GS/ie/PDU_session_type.h>

using namespace _5GS::IE;

int main()
{
    PDU_session_type ie;
    std::vector<uint8_t> buffer = {0x93};
    const uint8_t iei = 0x90;

    int size = ie.decode(buffer, InformationElement::Format::TV, iei);
    std::cerr << "read " << size << " byte(s)." << std::endl;
    std::cerr << ie.to_string() << std::endl;

    assert(size == 1);
    assert(PDU_session_type::Value::IPv4v6 == ie.get());

    buffer.clear();
    ie = PDU_session_type(PDU_session_type::Value::Ethernet);
    size = ie.code(buffer, InformationElement::Format::TV, iei);
    std::cerr << "wrote " << size << " byte(s)." << std::endl;
    std::cerr << "0x" << std::hex << static_cast<int>(buffer[0]) << std::endl;

    assert(size == 1);
    assert(0x95 == buffer[0]);

    return 0;
}