#include <_5GS/ie/SM_PDU_DN_request_container.h>
#include <buffers.h>

namespace _5GS
{
namespace IE
{

std::string SM_PDU_DN_request_container::getName() const
{
    return "SM PDU DN request container";
}

SM_PDU_DN_request_container::SM_PDU_DN_request_container(const std::string &value) : String(value)
{
    // TODO check value conformity
}

} // namespace IE
} // namespace _5GS
