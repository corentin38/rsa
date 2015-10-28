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
 * @file rsa_priv_key.hpp
 */

#ifndef BASICS_RSA_PUB_KEY_HPP
#define BASICS_RSA_PUB_KEY_HPP

#include "int_type.hpp"

namespace basics { 

/**
 * Classe support de clef publique
 * 
 * Membres :
 *  - N   le module de chiffrement
 *  - e   l'exposant de chiffrement
 */
class Rsa_pub_key 
{
public:
   Rsa_pub_key(unsigned rsa_key_length, unsigned char_size, int_type n, int_type e);
   
   inline const int_type& getModulus() const
   {
      return n_;
   }
   
   inline const int_type& getExponent() const 
   {
      return e_;
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
   int_type e_;

   unsigned rsa_key_length_;
   unsigned max_message_length_;
   
};

} // namespace

#endif
