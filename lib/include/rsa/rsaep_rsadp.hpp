/**
 * INSERT LICENCE INFORMATION HERE 
 */ 

/**
 * @author Corentin MARCIAU	<corentin@marciau.fr>
 */

/** 
 * @file rsaep_rsadp.hpp
 */

#ifndef _RSAEP_RSADP_HPP_
#define _RSAEP_RSADP_HPP_

#include <boost/multiprecision/gmp.hpp>

#include "crypt_prim.hpp"

#include "rsa_pub_key.hpp"
#include "rsa_priv_key.hpp"

namespace basics {

typedef boost::multiprecision::mpz_int int_type;

class Rsaep_rsadp : public Crypt_prim {

public:
   Rsaep_rsadp();
   ~Rsaep_rsadp();
   
   int_type rsaep(const Rsa_pub_key& pubkey, const int_type& message);
   int_type rsadp(const Rsa_priv_key& privkey, const int_type& cipher_text);
   
};

} //namespace

#endif
