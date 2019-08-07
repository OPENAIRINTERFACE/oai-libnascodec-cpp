#include <cassert>

#include <_5GS/ie/PDU_session_identity.h>

using namespace _5GS::IE;

int main()
{
    PDU_session_identity ie;
    std::vector<uint8_t> buffer = {5};

    int size = ie.decode(buffer, InformationElement::Format::V);
    std::cerr << "read " << size << " byte(s)." << std::endl;
    std::cerr << ie.to_string() << std::endl;

    assert(size == 1);
    assert(PDU_session_identity::Value::PDU_session_identity_value_5 == ie.get());

    buffer.clear();
    ie = PDU_session_identity(PDU_session_identity::Value::PDU_session_identity_value_3);
    size = ie.code(buffer, InformationElement::Format::V);
    std::cerr << "wrote " << size << " byte(s)." << std::endl;
    std::cerr << "0x" << std::hex << static_cast<int>(buffer[0]) << std::endl;

    assert(size == 1);
    assert(3 == buffer[0]);

    return 0;
}