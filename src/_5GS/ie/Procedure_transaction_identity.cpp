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
    this->present = true;
    this->value = value;
}

uint8_t Procedure_transaction_identity::get() const
{
    this->raise_exception_if_not_present(className(this));
    return this->value;
}

int Procedure_transaction_identity::code_V_ex(std::vector<uint8_t> &data) const
{
    this->raise_exception_if_not_present(className(this));
    data.push_back(this->value);
    return 1;
}

int Procedure_transaction_identity::decode_V_ex(const std::vector<uint8_t> &data)
{
    return Procedure_transaction_identity::decode_V_ex(data[0]);
}

int Procedure_transaction_identity::decode_V_ex(const uint8_t &byte)
{
    this->value = byte;
    this->present = true;
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
    return Procedure_transaction_identity::value_to_string(this->value);
}

}; // namespace IE
}; // namespace _5GS
