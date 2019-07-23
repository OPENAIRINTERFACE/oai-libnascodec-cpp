#pragma once

#include <iostream>

std::istream &operator>>(std::istream &input, std::vector<uint8_t> &data);
std::ostream &operator<<(std::ostream &output, std::vector<uint8_t> &data);
