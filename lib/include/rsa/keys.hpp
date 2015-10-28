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
 * @file keys.hpp
 */

#ifndef BASICS_KEYS_HPP
#define BASICS_KEYS_HPP

#include "int_type.hpp"
#include "rsa_pub_key.hpp"
#include "rsa_priv_key.hpp"

namespace basics {

// Constants
unsigned const rsa_length = 512;
unsigned const char_size = 8;

/** 
 * Classe de génération de bi-clef RSA. La génération d'une paire de
 * clef se fait dans le constructeur. 
 */
class Keys {

public:
   Keys();

   Rsa_pub_key getPublicKey() const;
   Rsa_priv_key getPrivateKey() const;

   inline bool isOperational() const
   {
      return operational_;
   }

   inline unsigned getKeyLength() const
   {
      return rsa_length;
   }
   
private:
   int_type p_, q_;
   int_type n_, phi_;
   int_type e_, d_;
   bool operational_;

   void generate();

   friend std::ostream &operator<<( std::ostream &os, const Keys &data );
   
};

inline std::ostream &operator<<(std::ostream &os, const Keys &data) 
{
   return os << 
      "p : " << data.p_ << "\n-----------------\n" <<
      "q : " << data.q_ << "\n-----------------\n" <<
      "n : " << data.n_ << "\n-----------------\n" <<
      "phi : " << data.phi_ << "\n-----------------\n" <<
      "e : " << data.e_ << "\n-----------------\n" <<
      "d : " << data.d_;
}

} // namespace

#endif 
