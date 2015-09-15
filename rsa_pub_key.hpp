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

namespace basics { 

using namespace boost::multiprecision;

typedef mpz_int int_type;

class Rsa_pub_key 
{
private:
   int_type n_;
   int_type e_;
   
public:
   Rsa_pub_key(int_type n, int_type e) : n_(n), e_(e) 
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
   
};

} // namespace

#endif
