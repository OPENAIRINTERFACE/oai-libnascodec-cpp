#include <nas.h>
#include <helpers.h>

int Nas::codeProtocolDiscriminator(std::vector<uint8_t> & data,const Nas::ProtocolDiscriminator protocol)
{
    data.push_back(static_cast<uint8_t>(protocol));
    return 1;
}

int Nas::codeSecurityHeaderType(std::vector<uint8_t> & data,const Nas::SecurityHeaderType security) {
    data.push_back(static_cast<uint8_t>(security));
    return 1;
    
}