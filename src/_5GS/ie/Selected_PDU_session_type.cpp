#include <_5GS/ie/Selected_PDU_session_type.h>
#include <buffers.h>

namespace _5GS
{
namespace IE
{

std::string Selected_PDU_session_type::getName() const
{
    return "Selected PDU session type";
}

Selected_PDU_session_type::Selected_PDU_session_type(Value value) : PDU_session_type(value)
{
}

} // namespace IE
} // namespace _5GS
