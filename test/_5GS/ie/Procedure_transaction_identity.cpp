#include <_5GS/ie/Procedure_transaction_identity.h>

using namespace _5GS::IE;

#include <test_template.h>

int main()
{
    code_V<Procedure_transaction_identity, Procedure_transaction_identity::Value>(
        Procedure_transaction_identity::Value::No_procedure_transaction_identity_assigned,
        std::vector<uint8_t>({0})
    );

    code_V<Procedure_transaction_identity, Procedure_transaction_identity::Value>(
        Procedure_transaction_identity::Value::Reserved,
        std::vector<uint8_t>({255})
    );

    decode_V<Procedure_transaction_identity, uint8_t>(
        std::vector<uint8_t>({17}),
        17
    );

    return 0;
}