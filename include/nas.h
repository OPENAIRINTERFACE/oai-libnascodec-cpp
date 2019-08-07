#pragma once

#include <iostream>
#include <vector>
#include <cstdint>

/** @brief manage nas headers */
class Nas
{

public:
    /** @enum ProtocolDiscriminator
     * @brief defines all known nas protocols
     * 
     * NAS messages is defined into numerous protocols and subprotocols.
     * This enums defines all known nas protocols.
     * 
     * The 3gpp TS 24.007 defines general aspect of all nas messages.
     * 
     * This enum gather Protocol Discriminator and Extended Protocol Discriminator because
     * these are code in the same byte.
     */
    enum class ProtocolDiscriminator : uint8_t
    {
        group_call_control, /**< TS 44.068 */
        broadcast_call_control, /**< TS 44.069 */
        EPS_session_management_messages, /**< TS 24.301 */
        call_control_call_related_SS_messages, /**< TS ???*/
        GPRS_Transparent_Transport_Protocol, /**< TS ??? */
        mobility_management_messages, /**< TS ???*/
        radio_resources_management_messages, /**< TS ??? */
        EPS_mobility_management_messages, /**< TS 24.301 */
        GPRS_mobility_management_messages, /**< TS 24.008*/
        SMS_messages, /**< TS 23.040 */
        GPRS_session_management_messages, /**< TS 24.008 */
        non_call_related_SS_messages, /**< TS 24.010 */
        Location_services_specified_in_3GPP_TS_44_072__8a_, /**< TS 44.072 */
        used_by_tests_procdures_described_in_3GPP_TS_44_014__5a__3GPP_TS_34_109__17a___3GPP_TS_36_509__26__and_3GPP_TS_38_509__29__ = 0X0f, /**< TS 44.014, TS 34.109, TS 36.509, TS 38.509*/
        // Here are extended protocols 0bxxxx1110
        _5GS_session_management_messages = 0b00101110, /**< TS 24.501 5GS session management messages */
        _5GS_mobility_management_messages = 0b01111110, /**< TS 24.501 5GS mobility management messages */
        // FIXME review this reserved addition
        reserved = 254 /**< This is not in 3gpp specification, but used as marker for this library */
    };

    /** @enum SecurityHeaderType */
    enum class SecurityHeaderType : uint8_t {
        Plain_5GS_NAS_message__not_security_protected, /**< message without security */
        Integrity_protected, /**< integrity protected */
        Integrity_protected_and_cyphered, /**< integrity protected and cyphered */
        Integrity_protected_with_new_5G_NAS_security_context /**< 5G integrity protected */,
        Integrity_protected_and_cyphered_with_new_5G_NAS_security_context /**< 5G integrity protected and cyphered */
    };

    /** @brief code Protocol Dicriminator or Extended Protocol Discriminator
     * 
     * This method code the PD or EPD on one byte and add it to the data buffer
     * 
     * @param[in] protocol  NAS protocol for the message
     * 
     * @param[out] data     buffer to add PD/EPD
     * 
     * @return number of bytes added to the data buffer
     */
    static int codeProtocolDiscriminator(std::vector<uint8_t> & data,const ProtocolDiscriminator protocol);
    /** @brief code the security header type
     * 
     * This method code the SHT and add it to the data buffer
     * 
     * @param[in] security  Security header type
     * 
     * @param[out] data     buffer to add SHT
     * 
     * @return number of bytes added to the data buffer
     */
    static int codeSecurityHeaderType(std::vector<uint8_t> & data,const SecurityHeaderType security);
    /** @brief decode Protocol Discriminator from byte buffer
     * 
     * @param[in] data     buffer containing PD/EDP byte
     * 
     * @return Protocol Discriminator value
     * 
     * @throw std::invalid_argument     if the PD/EPD can't be decoded
     */
    static ProtocolDiscriminator decodeProtocolDiscriminator(const std::vector<uint8_t> &data);
    /** @brief byte to (Extended) Protocol Discriminator
     * 
     * @param[in] byte     byte to convert
     * 
     * @return Protocol Discriminator value
     * 
     * @throw std::invalid_argument     if the PD/EPD can't be converted
     */
    static Nas::ProtocolDiscriminator uint8_t_to_ProtocolDiscriminator(const uint8_t byte);
};
