#pragma once

#include <vector>
#include <cstdint>
#include <string>

#include <errors.h>

/** @brief information element as defined in TS 24.007 chapter 11
 *
 * <b>Description from 3gpp:</b>
 *
 * Every standard IE has an information element type which determines the values
 * possible for the value part of the IE, and the basic meaning of the information.
 * The information element type describes only the value part. Standard IEs of
 * the same information element type may appear with different formats.
 * The format used for a given standard IE in a given message is specified within
 * the description of the message.
 *
 * The value part of a standard IE either consists of a half octet or one or more octets;
 * the value part of a standard IE with format LV or TLV consists of an integral
 * number of octets, between 0 and 255 inclusive; it then may be empty, i.e., consist
 * of zero octets; if it consists of a half octet and has format TV, its IEI consists
 * of a half octet, too.
 *
 * For LV-E and TLV-E, the value part of a standard IE consists of an integral number
 * of octets, between 0 and 65535 inclusive. The value part of a standard IE may be
 * further structured into parts, called fields.
 *
 * @attention Information Element Identifier(IEI), the T in the Format enumeration
 * is local to a PDU messages. I.E. a same information element identifier
 * may have different value, according to PDU message. @n
 *
*/
class InformationElement
{

public:
    /** @enum Format
     *
     * defines format as defined in TS 24.007 11.2.1.1
     *
     * IEI is Information Element Identifier @n
     * LI is Length Indicator
     *
     * if IEI, LI or value is omitted, it is not present
     *
     * @var T
     * @brief Type only @n
     * IEI present @n
     * also referred as type 1
     *
     * @var V
     * @brief Value only @n
     * value present : 1/2 octet @n
     * also referred as type 2
     *
     * @var TV
     * @brief Type and Value @n
     * IEI present, value present @n
     * also referred as type 3
     *
     * @var LV
     * @brief Length and Value @n
     * LI present, value present @n
     * also referred as type 4
     *
     * @var TLV
     * @brief Type and Value @n
     * IEI present, LI present, value present @n
     * also referred as type 4
     *
     * @var LV_E
     * @brief Type and Value @n
     * LI present (2 bytes), value present @n
     * also referred as type 6
     *
     * @var TLV_E
     * @brief Type and Value @n
     * IEI present, LI present (2 bytes), value present @n
     * also referred as type 6
     *
     */
    enum class Format
    {
        T,
        V,
        TV,
        LV,
        TLV,
        LV_E,
        TLV_E
    };

    /** @brief returns if the information element is set and have a value
     *
     * @return
     *  @b true    the information element is present @n
     *  @b false   the information element is empty or not set
     */
    virtual bool isSet() const;

    /** @brief add information element to @p data buffer, according to the
     * @p format given
     *
     * @param[out]  data    byte buffer to add information element
     * @param[in]   format  how to encode the information element
     * @param[in]   iei     optional, default to 0 - information element identifier if needed by the @p format
     *
     * @throw   NasCodecException      if the element can't be coded according to the format or not set
     */
    virtual int code(std::vector<uint8_t> &data, const InformationElement::Format format, const uint8_t iei = 0) const;

    /** @brief code information element on half byte
     *
     * @return value of the IE coded on the 4 least significant bits of an octet.
     * The other half is guaranted to be 0000
     *
     * @throw   NasCodecException      if the element can't be coded according to the format or not set
     */
    virtual uint8_t code_half_V() const;

    /** @brief decode information according to @p format
     *
     * @param[in]   data    buffer to decode
     * @param[in]   format  format of the IE in the buffer
     *
     * @return number of byte read and decoded
     *
     * @throw   NasCodecException      if the element can't be decoded according to the format
     */
    virtual int decode(const std::vector<uint8_t> &data, const InformationElement::Format format, const uint8_t iei = 0);

    /** @brief convert ie to readable string
     *
     * This function return a string formatted as "ie name = value" @n
     * When value have several fields, they are separated by & @n
     * For example : @n
     * Integrity protection maximum data rate=uplink(64 kbps)&downlink(Full data rate)
     *
     * @return string formatted
     */

    virtual std::string to_string() const;

    /** @brief return information element name
     *
     * @return the ie name (left part of the to_string() format)
     */
    virtual std::string getName() const;

    /** @brief return information element value
     *
     * @return the ie name (right part of the to_string() format)
     */
    virtual std::string valueToString() const;

protected:
    // FIXME use std::optional (only in c++17) ?
    bool m_present = false; /**< set if ie is optional and found in a PDU */
    /** @brief raise an exception if the information element is not present/set
     *
     * @param[in] name string defining the name of the information element
     *
     * @throw std::invalid_argument
    */
    void raise_exception_if_not_present(const std::string &name) const;
    void raise_exception_for_format_with_T(const Format format) const;

    virtual int code_T(std::vector<uint8_t> &data, const uint8_t iei) const;
    virtual int code_V(std::vector<uint8_t> &data) const;
    virtual int code_TV(std::vector<uint8_t> &data, const uint8_t iei) const;
    virtual int code_LV(std::vector<uint8_t> &data) const;
    virtual int code_TLV(std::vector<uint8_t> &data, const uint8_t iei) const;
    virtual int code_LV_E(std::vector<uint8_t> &data) const;
    virtual int code_TLV_E(std::vector<uint8_t> &data, const uint8_t iei) const;

    virtual int decode_T(const std::vector<uint8_t> &data, const uint8_t iei);
    virtual int decode_V(const std::vector<uint8_t> &data);
    virtual int decode_TV(const std::vector<uint8_t> &data, const uint8_t iei);
    virtual int decode_LV(const std::vector<uint8_t> &data);
    virtual int decode_TLV(const std::vector<uint8_t> &data, const uint8_t iei);
    virtual int decode_LV_E(const std::vector<uint8_t> &data);
    virtual int decode_TLV_E(const std::vector<uint8_t> &data, const uint8_t iei);
};
