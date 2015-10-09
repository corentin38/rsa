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

#include "rsa_pub_key.hpp"
#include "rsa_priv_key.hpp"

namespace basics {

typedef boost::multiprecision::mpz_int int_type;

class Rsaep_rsadp {

public:
   Rsaep_rsadp();
   
   int_type rsaep(Rsa_pub_key pubkey, int_type message);
   int_type rsadp(Rsa_priv_key privkey, int_type cipher_text);
   
};

} //namespace

#endif
