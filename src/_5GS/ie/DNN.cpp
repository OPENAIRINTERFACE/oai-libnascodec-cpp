#include <_5GS/ie/DNN.h>
#include <nas_helpers.h>

namespace _5GS
{
namespace IE
{

std::string DNN::getName() const
{
    return "DNN";
}

DNN::DNN() : String()
{
}

DNN::DNN(const std::string &value) : String(value)
{
    // TODO check value conformity
}

} // namespace IE
} // namespace _5GS
