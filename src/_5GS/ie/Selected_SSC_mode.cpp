#include <_5GS/ie/Selected_SSC_mode.h>
#include <buffers.h>

namespace _5GS
{
namespace IE
{

std::string Selected_SSC_mode::getName() const
{
    return "Selected SSC mode";
}

Selected_SSC_mode::Selected_SSC_mode(Value value) : SSC_mode(value)
{
}

} // namespace IE
} // namespace _5GS
