#include <_5GS/ie/Integrity_protection_maximum_data_rate.h>
#include <cassert>
#include <helpers.h>

using namespace _5GS::IE;

// FIXME rework IE to have only one value in interface

int main()
{
    Integrity_protection_maximum_data_rate ie;
    std::vector<uint8_t> buffer = {0, 0xff};

    // decode

    int size = ie.decode(buffer, InformationElement::Format::V);
    std::cerr << "read " << size << " byte(s)." << std::endl;
    std::cerr << ie.to_string() << std::endl;

    assert(size == 2);
    assert(Integrity_protection_maximum_data_rate::Value::_64_kbps == ie.getUplink());
    assert(Integrity_protection_maximum_data_rate::Value::Full_data_rate == ie.getDownlink());

    // code

    buffer.clear();
    ie = Integrity_protection_maximum_data_rate(
        Integrity_protection_maximum_data_rate::Value::Full_data_rate,
        Integrity_protection_maximum_data_rate::Value::_64_kbps);
    size = ie.code(buffer, InformationElement::Format::V);
    std::cerr << "wrote " << size << " byte(s)." << std::endl;
    std::cerr << dump_wireshark(buffer) << std::endl;

    assert(size == 2);
    const std::vector<uint8_t> result{0xff, 0x00};
    assert(result == buffer);

    return 0;
}