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
 * @file rsaep_rsadp.hpp
 * @brief 
 *
 * 
 */

#ifndef _RSAEP_RSADP_HPP_
#define _RSAEP_RSADP_HPP_

#include "keys.hpp"
#include "rsa_pub_key.hpp"
#include "rsa_priv_key.hpp"

#include <cmath>
#include <boost/multiprecision/gmp.hpp>
#include <string>
#include <stdexcept>
#include <sstream>

namespace basics {

using namespace boost::multiprecision;

typedef mpz_int int_type;

class Rsaep_rsadp {

public:
   Rsaep_rsadp()
   {
   }

   int_type rsaep(Rsa_pub_key pubkey, int_type message) 
   {
      std::cout << "    ciphering : " << message << std::endl;
      
      if (message < 0 || message >= pubkey.getModulus()) {
         std::stringstream err;
         err << "message representative out of range";
         throw std::runtime_error(err.str());
      }

      std::cout << "    computing : ( " << message << " exp " << pubkey.getExponent() << " ) mod " << pubkey.getModulus() << std::endl;
      
      // RSA : c = m^e mod n
      int_type c = powModulus(message, pubkey.getExponent(), pubkey.getModulus());

      return c;
   }
   
   int_type rsadp(Rsa_priv_key privkey, int_type cipher_text) 
   {
      if (cipher_text < 0 || cipher_text >= privkey.getModulus()) {
         std::stringstream err;
         err << "ciphertext representative out of range";
         throw std::runtime_error(err.str());
      }
      
      // RSA : m = c^d mod n
      int_type m = powModulus(cipher_text, privkey.getExponent(), privkey.getModulus());

      return m;
   }
   
private:
   int_type powModulus(int_type base, int_type exp, int_type mod) 
   {
      if (exp == 0) return 1;
      if (base == 0) return 0;
      if (mod <= 0) {
         std::stringstream err;
         err << "null or negative modulus: " << mod;
         throw std::runtime_error(err.str());
      }

      int_type acc = base;

      for (int i=1; i<exp; i++) {
         acc = (acc * base) % mod;
      }
      
      return acc;
   }   
   
};

} //namespace

#endif
