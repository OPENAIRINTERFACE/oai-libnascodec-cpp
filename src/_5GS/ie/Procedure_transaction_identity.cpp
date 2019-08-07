#include <_5GS/ie/Procedure_transaction_identity.h>
#include <helpers.h>

namespace _5GS
{
namespace IE
{

const std::string Procedure_transaction_identity::name = "Procedure transaction identity";

Procedure_transaction_identity::Procedure_transaction_identity()
{
}

Procedure_transaction_identity::Procedure_transaction_identity(Procedure_transaction_identity::Value value)
{
    this->set(static_cast<uint8_t>(value));
}

Procedure_transaction_identity::Procedure_transaction_identity(uint8_t value)
{
    this->set(value);
}

void Procedure_transaction_identity::set(uint8_t value)
{
    this->m_present = true;
    this->m_value = value;
}

uint8_t Procedure_transaction_identity::get() const
{
    this->raise_exception_if_not_present(className(this));
    return this->m_value;
}

int Procedure_transaction_identity::code_V(std::vector<uint8_t> &data) const
{
    this->raise_exception_if_not_present(className(this));
    data.push_back(this->m_value);
    return 1;
}

int Procedure_transaction_identity::decode_V(const std::vector<uint8_t> &data)
{
    return Procedure_transaction_identity::decode_V(data[0]);
}

int Procedure_transaction_identity::decode_V(const uint8_t &byte)
{
    this->m_value = byte;
    this->m_present = true;
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

std::string Procedure_transaction_identity::to_string() const
{
    if (not this->isSet())
    {
        return std::string("-");
    }
    return Procedure_transaction_identity::value_to_string(this->m_value);
}

}; // namespace IE
}; // namespace _5GS
