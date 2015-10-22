/**
 * INSERT LICENCE INFORMATION HERE 
 */ 

/**
 * @author Corentin MARCIAU	<corentin@marciau.fr>
 */

/** 
 * @file crypt_prim.hpp
 */

#ifndef BASICS_CRYPT_PRIM_HPP
#define BASICS_CRYPT_PRIM_HPP

#include "int_type.hpp"
#include "rsa_pub_key.hpp"
#include "rsa_priv_key.hpp"

namespace basics {

class Crypt_prim 
{
public:
    virtual ~Crypt_prim() {};
    virtual int_type rsaep(const Rsa_pub_key& pubkey, const int_type& message) = 0;
    virtual int_type rsadp(const Rsa_priv_key& privkey, const int_type& cipher_text) = 0;
};

} //namespace

#endif
