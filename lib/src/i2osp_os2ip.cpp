/**
 * INSERT LICENCE INFORMATION HERE 
 */ 

/**
 * @author Corentin MARCIAU	<corentin@marciau.fr>
 */

/**
 * @file i2osp_os2ip.cpp
 */

#include "rsa/i2osp_os2ip.hpp"
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <sstream>

basics::I2osp_os2ip::I2osp_os2ip() 
    : Data_prim()
{
}

basics::I2osp_os2ip::~I2osp_os2ip() 
{
    return;
}

basics::int_type 
basics::I2osp_os2ip::os2ip(const basics::Rsa_pub_key& pubkey, const std::string& message_part)
{
    if (message_part.size() > pubkey.getMaxMessageLength()) {
        std::stringstream err;
        err << "message part too large max_size=" << pubkey.getMaxMessageLength() << 
            " size=" << message_part.size() << " str=\"" << message_part << "\"";
        throw std::runtime_error(err.str());
    }
    
    basics::int_type message_part_int = 0;
    
    for (unsigned i=0; i<message_part.size(); i++) {
        message_part_int += (basics::int_type) (message_part[i] * std::pow(256, message_part.size() -i - 1));
    }
    
    return message_part_int;
}

std::string 
basics::I2osp_os2ip::i2osp(const basics::Rsa_priv_key& privkey, const basics::int_type& message_part) 
{
    unsigned key_length = privkey.getRsaKeyLength();
    
    if (message_part >> key_length > 0) {
        std::stringstream err;
        err << "integer too large (CMB)";
        throw std::runtime_error(err.str());
    }
    
    std::string message_part_str = "";
    basics::int_type current_order(message_part);
    basics::int_type current_char = 0;
    
    for (unsigned i=0; i<key_length; i++) {
        if (current_order == 0) break;
        current_char = current_order % 256;
        message_part_str = char(current_char.convert_to<int>()) + message_part_str;
        current_order >>= 8;
    }
    
    return message_part_str;
}

