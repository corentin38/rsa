/**
 * INSERT LICENCE INFORMATION HERE 
 */ 

/**
 * @author Corentin MARCIAU	<corentin@marciau.fr>
 */

/**
 * @file data_prim.hpp
 */

#ifndef BASICS_DATA_PRIM_HPP
#define BASICS_DATA_PRIM_HPP

#include "int_type.hpp"
#include "rsa_pub_key.hpp"
#include "rsa_priv_key.hpp"

namespace basics {

typedef boost::multiprecision::mpz_int int_type;

class Data_prim {
   
public:
   virtual ~Data_prim() {};
   virtual int_type os2ip(const Rsa_pub_key& pubkey, const std::string& message_part) = 0;
   virtual std::string i2osp(const Rsa_priv_key& privkey, const int_type& message_part) = 0;

};

} // namespace

#endif
