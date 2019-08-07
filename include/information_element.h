#pragma once

#include <vector>
#include <cstdint>
#include <string>

/** @brief WIP information element as defined in TS 24.007 chapter 11
 *
 * @attention Information Element Identifier(IEI), the T in the Format enumeration
 * is locacl to a PDU messages. I.E. a same information element identifier
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
     * IEI present
     *
     * @var V
     * @brief Value only @n
     * value present
     *
     * @var TV
     * @brief Type and Value @n
     * IEI present, value present
     *
     * @var LV
     * @brief Length and Value @n
     * LI present, value present
     *
     * @var TLV
     * @brief Type and Value @n
     * IEI present, LI present, value present
     *
     * @var LV_E
     * @brief Type and Value @n
     * LI present (2 bytes), value present
     *
     * @var TLV_E
     * @brief Type and Value @n
     * IEI present, LI present (2 bytes), value present
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
     * @return true: the information element is present, false, the information element is empty.
     */
    bool isSet() const;

    /** @brief add information element to @p data buffer, according to the
     * @p format given
     *
     * @param[out]  data    byte buffer to add information element
     * @param[in]   format  how to encode the information element
     * @param[in]   iei     optional, default to 0 - information element identifier if needed by the @p format
     *
     * @throw   std::invalid_argument   if the element is not set
     * @throw   std::runtime_error      if the element can't be coded according to the format
     *
     */
    virtual int code(std::vector<uint8_t> &data, const InformationElement::Format format, const uint8_t iei = 0) const;
    virtual int decode(const std::vector<uint8_t> &data, const InformationElement::Format format, const uint8_t iei = 0);

protected:
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
