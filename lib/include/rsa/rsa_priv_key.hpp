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
 * @file rsa_priv_key.hpp
 * @brief 
 *
 * 
 */

#ifndef _RSA_PRIV_KEY_HH_
#define _RSA_PRIV_KEY_HH_


#include <boost/multiprecision/gmp.hpp>

namespace basics { 

typedef boost::multiprecision::mpz_int int_type;

class Rsa_priv_key 
{
public:
   Rsa_priv_key(unsigned rsa_key_length, unsigned char_size, int_type n, int_type d) : 
      n_(n), d_(d),
      rsa_key_length_(rsa_key_length),
      max_message_length_(rsa_key_length / char_size - 1)
   {
   }
   
   int_type getModulus() 
   {
      return n_;
   }
   
   int_type getExponent() 
   {
      return d_;
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
   int_type d_;

   unsigned rsa_key_length_;
   unsigned max_message_length_;
   
};

} // namespace

#endif