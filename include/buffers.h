#pragma once

#include <iostream>
#include <string>
#include <vector>

/** @brief convert byte buffer to string
 *
 * Usually byte buffers are defined with uint8_t type.
 *
 * But sometimes, we need to convert it to string for libraries like amqp-cpp
 * which uses string as buffer
 *
 * @param[in] buffer byte buffer
 *
 * @return byte buffer converted to string
 */
const std::string convert_to_string(const std::vector<uint8_t> &buffer);

std::istream &operator>>(std::istream &input, std::vector<uint8_t> &data);
std::ostream &operator<<(std::ostream &output, std::vector<uint8_t> &data);

std::string dump_wireshark(const std::vector<uint8_t> &data);
std::string dump_wireshark_with_ngap_encapsulation(const std::vector<uint8_t> &data);