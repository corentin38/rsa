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

#include "int_type.hpp"

namespace basics { 

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
