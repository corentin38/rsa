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

#ifndef _KEYS_HPP_
#define _KEYS_HPP_

#define RSA_LENGTH 512
#define CHAR_SIZE 8

#include "rsa_pub_key.hpp"
#include "rsa_priv_key.hpp"

#include <boost/multiprecision/gmp.hpp>
#include <boost/multiprecision/integer.hpp>

namespace basics {

typedef boost::multiprecision::mpz_int int_type;

class Keys {

public:
   Keys();

   Rsa_pub_key getPublicKey();
   Rsa_priv_key getPrivateKey();

   inline bool isOperational() 
   {
      return operational_;
   }

   inline unsigned getKeyLength() 
   {
      return RSA_LENGTH;
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
