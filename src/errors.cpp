#include <errors.h>

std::string stack_and_format_exception(const std::string &raised, const std::string &thrown)
{
    return raised + "\n" + thrown;
}
