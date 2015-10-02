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
 * @version 1.0.0 / 15-09-2015
 * @todo 
 * @bug 
 */

/** 
 * @file rsa_pub_key.hpp
 * @brief 
 *
 * 
 */

#ifndef _RSA_PUB_KEY_HPP_
#define _RSA_PUB_KEY_HPP_

#include <boost/multiprecision/gmp.hpp>
#include "keys.hpp"

namespace basics { 

using namespace boost::multiprecision;

typedef mpz_int int_type;

class Rsa_pub_key 
{
public:
   Rsa_pub_key(unsigned rsa_key_length, int_type n, int_type e) : 
      n_(n), e_(e),
      rsa_key_length_(rsa_key_length),
      max_message_length_(rsa_key_length / CHAR_SIZE - 1) 
   {
   }
   
   int_type getModulus() 
   {
      return n_;
   }
   
   int_type getExponent() 
   {
      return e_;
   }

   unsigned getRsaKeyLength() 
   {
      return rsa_key_length_;
   }
   
   unsigned getMaxMessageLength() 
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
