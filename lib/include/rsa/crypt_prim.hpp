/**
 * INSERT LICENCE INFORMATION HERE 
 */ 

/**
 * @author Corentin MARCIAU	<corentin@marciau.fr>
 */

/** 
 * @file crypt_prim.hpp
 */

#ifndef _CRYPT_PRIM_HPP_
#define _CRYPT_PRIM_HPP_

#include <boost/multiprecision/gmp.hpp>
#include "rsa_pub_key.hpp"
#include "rsa_priv_key.hpp"

namespace basics {

typedef boost::multiprecision::mpz_int int_type;

class Crypt_prim 
{
    virtual int_type rsaep(const Rsa_pub_key& pubkey, const int_type& message) = 0;
    virtual int_type rsadp(const Rsa_priv_key& privkey, const int_type& cipher_text) = 0;
};

} //namespace

#endif
