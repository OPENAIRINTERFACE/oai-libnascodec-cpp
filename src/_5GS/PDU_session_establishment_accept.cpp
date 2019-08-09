#include <nas.h>
#include <_5GS/PDU_session_establishment_accept.h>
#include <helpers.h>

namespace _5GS
{

PDU_session_establishment_accept::PDU_session_establishment_accept()
{
    message_type.set(IE::Message_type::Value::PDU_session_establishment_accept);
}

PDU_session_establishment_accept::PDU_session_establishment_accept(
    IE::PDU_session_identity psi,
    IE::Procedure_transaction_identity pti,
    // Mandatory
    IE::Selected_PDU_session_type spst,
    IE::Selected_SSC_mode sm,
    // IE::Authorized_QoS_rules aqr,
    // IE::Session_AMBR sa,
    // Optionals,
    // IE::_5GSM_cause cause = ,
    // IE::PDU_address pdu_address = ,
    // IE::RQ_timer_value rq_timer_value =,
    // IE::S_NSSAI s_nssai =
    // IE::Always_on_PDU_session_indication always_on = ,
    // IE::Mapped_EPS_bearer_contexts mapped_bearers = ,
    // IE::EAP_message eap = ,
    // IE::Authorized_QoS_flow_descriptions auth_qos = ,
    // IE::Extended_protocol_configuration_option = ,
    // IE::DNN dnn =,
    int placeholder // remove me when the last optional ie is implemented
    )
    : Pdu5gsSm::Pdu5gsSm(psi, pti)

{
    // FIXME
    message_type.set(IE::Message_type::Value::PDU_session_establishment_accept);
    m_selected_pdu_session_type = spst;
    m_selected_ssc_mode = sm;
}

int PDU_session_establishment_accept::code(std::vector<uint8_t> &data) const
{
    int size = 0;
    try
    {
        size += Nas::codeProtocolDiscriminator(data, Nas::ProtocolDiscriminator::_5GS_session_management_messages);

        // mandatory parameters
        size += codeSMHeader(data);

        uint8_t left, right;
        left = m_selected_ssc_mode.code_half_V();
        right = m_selected_pdu_session_type.code_half_V();

        data.push_back((left << 4) | right);
        size += 1;

        // FIXME add optional parameters
    }
    catch (const std::exception &exception)
    {
        std::string test = std::string("Error coding ") + className(this);
        throw NasCodecException(
            stack_and_format_exception(
                exception.what(),
                std::string("Error coding ") + className(this)));
    }
    return size;
}

int PDU_session_establishment_accept::decode(const std::vector<uint8_t> &data)
{
    unsigned int offset = 0;
    offset = Pdu5gsSm::decode(data);

    // Decode mandatory parameters
    offset += m_selected_pdu_session_type.decode(data, InformationElement::Format::V);
    offset += m_selected_ssc_mode.decode(
        std::vector<uint8_t>(data.begin() + offset, data.end()), InformationElement::Format::V);

    // Decode optional parameters
    while (offset < data.size())
    {
        const std::vector<uint8_t> iei_data(data.cbegin() + offset, data.cend());
        uint8_t iei = iei_data[0];
        if (iei > 0x80)
        {
            iei = iei & 0xf0;
        }
        switch (iei)
        {
        case PDU_session_establishment_accept::Iei::Always_on_PDU_session_requested:
        //    offset += always_on_PDU_session_requested.decode(iei_data, InformationElement::Format::TV, iei);
        default:
            break;
        }
    }
    return offset;
}

std::string PDU_session_establishment_accept::to_string() const
{
    std::string str;
    str = "PDU_session_establishment_accept";
    str += "(";
    // Header
    str += header_to_string();
    // Mandatory parameters
    str += ", " + m_selected_pdu_session_type.to_string();
    str += ", " + m_selected_ssc_mode.to_string();
    // Optional parameters
    /*
    if (pdu_session_type.isSet())
    {
        str += ", " +
               pdu_session_type.name +
               "=" +
               pdu_session_type.to_string();
    }
    str += ")";
     */
    return str;
}

}; // namespace _5GS