/**
 * This file is part of myRSA.
 * 
 * myRSA is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * myRSA is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Foobar.  If not, see <http://www.gnu.org/licenses/>. 
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

