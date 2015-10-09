/**
 * INSERT LICENCE INFORMATION HERE 
 */ 

/**
 * @author Corentin MARCIAU	<corentin@marciau.fr>
 */

/** 
 * @file rsa_priv_key.hpp
 */

#ifndef _RSA_PRIV_KEY_HH_
#define _RSA_PRIV_KEY_HH_


#include <boost/multiprecision/gmp.hpp>

namespace basics { 

typedef boost::multiprecision::mpz_int int_type;

class Rsa_priv_key 
{
public:
   Rsa_priv_key(unsigned rsa_key_length, unsigned char_size, int_type n, int_type d);
   
   inline int_type getModulus() 
   {
      return n_;
   }
   
   inline int_type getExponent() 
   {
      return d_;
   }

   inline unsigned getRsaKeyLength() 
   {
      return rsa_key_length_;
   }
   
   inline unsigned getMaxMessageLength() 
   {
      return max_message_length_;
   }
   

private:
   int_type n_;
   int_type d_;

   unsigned rsa_key_length_;
   unsigned max_message_length_;
   
};

} // namespace

#endif
