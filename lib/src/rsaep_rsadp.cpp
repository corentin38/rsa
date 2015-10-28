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
 * @file rsaep_rsadp.cpp
 */

#include "rsa/rsaep_rsadp.hpp"
#include "math_extra/math_extra.hpp"

#include <stdexcept>
#include <sstream>

basics::Rsaep_rsadp::Rsaep_rsadp()
    : Crypt_prim()
{
}

basics::Rsaep_rsadp::~Rsaep_rsadp()
{
    return;
}

basics::int_type 
basics::Rsaep_rsadp::rsaep(const basics::Rsa_pub_key& pubkey, 
                           const basics::int_type& message) 
{
    if (message < 0 || message >= pubkey.getModulus()) {
        std::stringstream err;
        err << "message representative out of range";
        throw std::runtime_error(err.str());
    }    
    
    // RSA : c = m^e mod n
    basics::int_type c = basics::powModulus(message, pubkey.getExponent(), pubkey.getModulus());
    
    return c;
}

basics::int_type 
basics::Rsaep_rsadp::rsadp(const basics::Rsa_priv_key& privkey, 
                           const basics::int_type& cipher_text) 
{
    if (cipher_text < 0 || cipher_text >= privkey.getModulus()) {
        std::stringstream err;
        err << "ciphertext representative out of range";
        throw std::runtime_error(err.str());
    }
    
    // RSA : m = c^d mod n
    basics::int_type m = basics::powModulus(cipher_text, privkey.getExponent(), privkey.getModulus());
    
    return m;
}
