#include <cassert>

#include <_5GS/ie/Message_type.h>

using namespace _5GS::IE;

int main()
{
    Message_type ie;
    std::vector<uint8_t> buffer = {0b11000001};

    int size = ie.decode(buffer, InformationElement::Format::V);
    std::cerr << "read " << size << " byte(s)." << std::endl;
    std::cerr << ie.to_string() << std::endl;

    assert(size == 1);
    assert(Message_type::Value::PDU_session_establishment_request == ie.get());

    buffer.clear();
    ie.set(Message_type::Value::PDU_session_authentication_command);
    size = ie.code(buffer, InformationElement::Format::V);
    std::cerr << "wrote " << size << " byte(s)." << std::endl;
    std::cerr << "0x" << std::hex << static_cast<int>(buffer[0]) << std::endl;

    assert(size == 1);
    assert(0b11000101 == buffer[0]);

    return 0;
}