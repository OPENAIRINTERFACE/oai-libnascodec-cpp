#include <buffers.h>
#include <cassert>

// V type IEs

template <class IEClass, typename IEValue>
void code_V(IEValue value, std::vector<uint8_t> result)
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl
              << std::endl;

    IEClass ie;
    std::vector<uint8_t> buffer;

    ie = IEClass(value);
    std::cerr << "coding " << ie.to_string() << std::endl;
    unsigned int size = ie.code(buffer, InformationElement::Format::V);
    std::cerr << "wrote " << size << " byte(s)." << std::endl;
    std::cerr << dump_wireshark(buffer) << std::endl;

    assert(size == result.size());
    assert(result == buffer);
}

template <class IEClass, typename IEValue>
void decode_V(std::vector<uint8_t> buffer, IEValue result)
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl
              << std::endl;

    IEClass ie;

    std::cerr << "decoding : " << dump_wireshark(buffer);
    unsigned int size = ie.decode(buffer, InformationElement::Format::V);
    std::cerr << "read " << size << " byte(s)." << std::endl;
    std::cerr << ie.to_string() << std::endl
              << std::endl;

    assert(size == buffer.size());
    assert(result == ie.get());
}

template <class IEClass, typename IEValue>
void decode_invalid_value_V(std::vector<uint8_t> buffer)
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl
              << std::endl;

    IEClass ie;

    std::cerr << "decoding : " << dump_wireshark(buffer);
    try
    {
        ie.decode(buffer, InformationElement::Format::V);
    }
    catch (const NasCodecException &except)
    {
        std::cerr << "decoding failed as intended : " << except.what() << std::endl
                  << std::endl;
        return;
    }

    throw std::runtime_error("Value should not be decoded");
}

// LV type IEs

template <class IEClass, typename IEValue>
void code_LV(IEValue value, std::vector<uint8_t> result)
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl
              << std::endl;

    IEClass ie;
    std::vector<uint8_t> buffer;

    ie = IEClass(value);
    std::cerr << "coding " << ie.to_string() << std::endl;
    unsigned int size = ie.code(buffer, InformationElement::Format::LV);
    std::cerr << "wrote " << size << " byte(s)." << std::endl;
    std::cerr << dump_wireshark(buffer) << std::endl;

    assert(size == result.size());
    assert(result == buffer);
}

template <class IEClass, typename IEValue>
void decode_LV(std::vector<uint8_t> buffer, IEValue result)
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl
              << std::endl;

    IEClass ie;

    std::cerr << "decoding : " << dump_wireshark(buffer);
    unsigned int size = ie.decode(buffer, InformationElement::Format::LV);
    std::cerr << "read " << size << " byte(s)." << std::endl;
    std::cerr << ie.to_string() << std::endl
              << std::endl;

    assert(size == buffer.size());
    assert(result == ie.get());
}

template <class IEClass, typename IEValue>
void decode_invalid_value_LV(std::vector<uint8_t> buffer)
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl
              << std::endl;

    IEClass ie;

    std::cerr << "decoding : " << dump_wireshark(buffer);
    try
    {
        ie.decode(buffer, InformationElement::Format::V);
    }
    catch (const NasCodecException &except)
    {
        std::cerr << "decoding failed as intended : " << except.what() << std::endl
                  << std::endl;
        return;
    }

    throw std::runtime_error("Value should not be decoded");
}

// TV type IEs

template <class IEClass, typename IEValue>
void code_TV(uint8_t iei, IEValue value, std::vector<uint8_t> result)
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl
              << std::endl;

    IEClass ie;
    std::vector<uint8_t> buffer;

    ie = IEClass(value);
    std::cerr << "coding " << ie.to_string() << " with ie " << std::hex << static_cast<int>(iei) << std::endl;
    unsigned int size = ie.code(buffer, InformationElement::Format::TV, iei);
    std::cerr << "wrote " << size << " byte(s)." << std::endl;
    std::cerr << "0x" << dump_wireshark(buffer) << std::endl;

    assert(size == result.size());
    assert(result == buffer);
}

template <class IEClass, typename IEValue>
void decode_TV(uint8_t iei, std::vector<uint8_t> buffer, IEValue result)
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl
              << std::endl;

    IEClass ie;

    std::cerr << "decoding "
              << " with ie " << std::hex << static_cast<int>(iei) << ": " << dump_wireshark(buffer);
    unsigned int size = ie.decode(buffer, InformationElement::Format::TV, iei);
    std::cerr << "read " << size << " byte(s)." << std::endl;
    std::cerr << ie.to_string() << std::endl
              << std::endl;

    assert(size == buffer.size());
    assert(result == ie.get());
}

template <class IEClass, typename IEValue>
void decode_TV_with_invalid_iei(uint8_t iei, std::vector<uint8_t> buffer, IEValue result)
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl
              << std::endl;

    IEClass ie;

    std::cerr << "decoding : " << dump_wireshark(buffer);
    try
    {
        ie.decode(buffer, InformationElement::Format::TV, iei);
    }
    catch (const NasCodecException &except)
    {
        std::cerr << "decoding failed as intended : " << except.what() << std::endl
                  << std::endl;
        return;
    }

    throw std::runtime_error("Wrong iei should not be decoded");
}

// TLV type IEs

template <class IEClass, typename IEValue>
void code_TLV(uint8_t iei, IEValue value, std::vector<uint8_t> result)
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl
              << std::endl;

    IEClass ie;
    std::vector<uint8_t> buffer;

    ie = IEClass(value);
    std::cerr << "coding " << ie.to_string() << " with ie " << std::hex << static_cast<int>(iei) << std::endl;
    unsigned int size = ie.code(buffer, InformationElement::Format::TLV, iei);
    std::cerr << "wrote " << size << " byte(s)." << std::endl;
    std::cerr << "0x" << dump_wireshark(buffer) << std::endl;

    assert(size == result.size());
    assert(result == buffer);
}

template <class IEClass, typename IEValue>
void decode_TLV(uint8_t iei, std::vector<uint8_t> buffer, IEValue result)
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl
              << std::endl;

    IEClass ie;

    std::cerr << "decoding "
              << " with ie " << std::hex << static_cast<int>(iei) << ": " << dump_wireshark(buffer);
    unsigned int size = ie.decode(buffer, InformationElement::Format::TLV, iei);
    std::cerr << "read " << size << " byte(s)." << std::endl;
    std::cerr << ie.to_string() << std::endl
              << std::endl;

    assert(size == buffer.size());
    assert(result == ie.get());
}

template <class IEClass, typename IEValue>
void decode_TLV_with_invalid_iei(uint8_t iei, std::vector<uint8_t> buffer, IEValue result)
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl
              << std::endl;

    IEClass ie;

    std::cerr << "decoding : " << dump_wireshark(buffer);
    try
    {
        ie.decode(buffer, InformationElement::Format::TLV, iei);
    }
    catch (const NasCodecException &except)
    {
        std::cerr << "decoding failed as intended : " << except.what() << std::endl
                  << std::endl;
        return;
    }

    throw std::runtime_error("Wrong iei should not be decoded");
}
