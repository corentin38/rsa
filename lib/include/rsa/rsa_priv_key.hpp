/**
 * INSERT LICENCE INFORMATION HERE 
 */ 

/**
 * @author Corentin MARCIAU	<corentin@marciau.fr>
 */

/** 
 * @file rsa_priv_key.hpp
 */

#ifndef BASICS_RSA_PRIV_KEY_HPP
#define BASICS_RSA_PRIV_KEY_HPP

#include "int_type.hpp"

namespace basics { 

class Rsa_priv_key 
{
public:
   Rsa_priv_key(unsigned rsa_key_length, unsigned char_size, int_type n, int_type d);
   
   inline const int_type& getModulus() const
   {
      return n_;
   }
   
   inline const int_type& getExponent() const
   {
      return d_;
   }

   inline unsigned getRsaKeyLength() const
   {
      return rsa_key_length_;
   }
   
   inline unsigned getMaxMessageLength() const
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
