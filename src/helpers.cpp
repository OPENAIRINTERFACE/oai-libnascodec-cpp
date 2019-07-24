#include <vector>
#include <iostream>
#include <helpers.h>

std::ostream & operator<<(std::ostream & output, std::vector<uint8_t> & data)
{
    for (const auto & el : data)
    {
        output << el;
    }
    return output;
}