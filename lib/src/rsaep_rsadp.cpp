/**
 * INSERT LICENCE INFORMATION HERE 
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
{
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
