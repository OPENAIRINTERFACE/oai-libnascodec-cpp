#pragma once

#include <stdexcept>
#include <string>
#include <cxxabi.h>

class NasCodecException : public std::exception
{
public:
    NasCodecException(const std::string & message) : m_message(message)
    {

    }

    virtual const char * what() const noexcept override
    {
       return m_message.c_str() ;
    }

private:
    std::string m_message ;
} ;

std::string stack_and_format_exception(const std::string &raised, const std::string &thrown);

template <class Type>
std::string className(const Type &object)
{
    int status;
    char *name = abi::__cxa_demangle(typeid(object).name(), 0, 0, &status);
    return std::string(name);
}
