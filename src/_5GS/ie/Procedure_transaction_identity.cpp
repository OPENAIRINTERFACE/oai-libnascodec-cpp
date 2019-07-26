#include <_5GS/ie/Procedure_transaction_identity.h>
#include <helpers.h>

namespace _5GS
{
namespace IE
{

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
    // TODO
    throw std::runtime_error(std::string("Not implemented: ") + std::string(__PRETTY_FUNCTION__));
    return -1;
}

}; // namespace IE
}; // namespace _5GS
