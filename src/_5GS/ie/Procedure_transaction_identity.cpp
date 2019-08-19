#include <_5GS/ie/Procedure_transaction_identity.h>
#include <buffers.h>

namespace _5GS
{
namespace IE
{

Procedure_transaction_identity::Procedure_transaction_identity(Procedure_transaction_identity::Value value)
{
    set(static_cast<uint8_t>(value));
}

Procedure_transaction_identity::Procedure_transaction_identity(uint8_t value)
{
    set(value);
}

void Procedure_transaction_identity::set(uint8_t value)
{
    m_present = true;
    m_value = value;
}

uint8_t Procedure_transaction_identity::get() const
{
    raise_exception_if_not_present(className(this));
    return m_value;
}

int Procedure_transaction_identity::code_V(std::vector<uint8_t> &data) const
{
    raise_exception_if_not_present(className(this));
    data.push_back(m_value);
    return 1;
}

int Procedure_transaction_identity::decode_V(const std::vector<uint8_t> &data)
{
    return Procedure_transaction_identity::decode_V(data[0]);
}

int Procedure_transaction_identity::decode_V(const uint8_t &byte)
{
    m_value = byte;
    m_present = true;
    return 1;
}

std::string Procedure_transaction_identity::value_to_string(const uint8_t value)
{
    switch (value)
    {
    case static_cast<uint8_t>(Procedure_transaction_identity::Value::No_procedure_transaction_identity_assigned):
        return std::string("No procedure transaction identity assigned");
    case static_cast<uint8_t>(Procedure_transaction_identity::Value::Reserved):
        return std::string("Reserved");
    }
    return std::to_string(value);
}

std::string Procedure_transaction_identity::getName() const
{
    return "Procedure transaction identity";
}

std::string Procedure_transaction_identity::valueToString() const
{
    if (not isSet())
    {
        return std::string("-");
    }
    return Procedure_transaction_identity::value_to_string(m_value);
}

}; // namespace IE
}; // namespace _5GS
