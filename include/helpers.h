#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cxxabi.h>

std::istream &operator>>(std::istream &input, std::vector<uint8_t> &data);
std::ostream &operator<<(std::ostream &output, std::vector<uint8_t> &data);

std::string stack_and_format_exception(const std::string &raised,const std::string &thrown);

template <class Type>
std::string className(const Type &object) {
    int status;
    char * name = abi::__cxa_demangle(typeid(object).name(),0, 0, &status);
    return std::string(name);
}

std::string dump_wireshark(const std::vector<uint8_t> &data);