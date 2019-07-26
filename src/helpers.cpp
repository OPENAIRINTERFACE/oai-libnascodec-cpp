#include <vector>
#include <iostream>
#include <helpers.h>

std::ostream &operator<<(std::ostream &output, std::vector<uint8_t> &data)
{
    for (const auto &el : data)
    {
        output << el;
    }
    return output;
}

std::string stack_and_format_exception(const std::string &raised, const std::string &thrown)
{
    return raised + "\n" + thrown;
}
