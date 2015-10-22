/** -*- c-basic-offset: 3 -*- 
 *
 * ENSICAEN
 * 6 Boulevard Maréchal Juin 
 * F-14050 Caen Cedex
 * 
 * Ce fichier est l'oeuvre d'élèves de l'ENSI de Caen. Il ne peut être 
 * reproduit, utilisé ou modifié sans l'avis express de ses auteurs.
 * 
 */ 

/** 
 * @author Corentin MARCIAU	<corentin.marciau@ecole.ensicaen.fr>
 *
 * @version 1.0.0 / 02-09-2015
 * @todo 
 * @bug 
 */

/** 
 * @file keys.h
 * @brief 
 *
 * 
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
