#pragma once

#include <stdexcept>
#include <string>

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
