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

#include "pnrg.hpp"
#include "rsa_pub_key.hpp"
#include "rsa_priv_key.hpp"

#include <boost/multiprecision/gmp.hpp>
#include <boost/multiprecision/integer.hpp>
#include <iostream>
#include <stdexcept>
#include <sstream>

namespace basics { 


using namespace boost::multiprecision;

typedef mpz_int int_type;

class Keys {
   
private:
   int_type p_;
   int_type q_;

   int_type n_;
   int_type phi_;
   
   int_type e_;
   int_type d_;

   bool operational_;

   void generate() 
   {
      // Trouvons p et q deux grands entiers premiers
      Pnrg pnrg(RSA_LENGTH);
      p_ = pnrg.getPrime();
      q_ = pnrg.getPrime();
      
      if (p_ == 0 || q_ == 0) {
         std::cout << "Impossible de générer p et q premiers." << std::endl;
         return;
      }
      
      // Calculons n, le produit de p et q
      n_ = p_ * q_;

      // Calculons l'indicatrice d'Euler de n
      phi_ = (p_ - 1)* (q_ - 1);
      
      // Calculons e, premier avec phi(n) (il faudrait lire pas mal de
      // littérature pour faire un choix rationel ...)
      e_ = 65537;
      while (gcd(e_, phi_) != 1) {
         e_ += 2;
      }
  
      // On calcule d, inverse de e modulo phi(n)
      d_ = inverse(e_, phi_);

      int_type prod = (e_ * d_) % phi_;
      if ( prod != 1) {
         std::stringstream err;
         err << "Mauvais inverse d ! prod=" << prod << std::endl;
         throw std::runtime_error(err.str());
      }

      // Tout s'est bien passé !
      operational_ = true;
   }
   

   int_type inverse(int_type e, int_type phi) 
   {
      int_type r0=phi, r1=e, u0=1, u1=0, v0=0, v1=1;
      int_type q=0, rs=0, us=0, vs=0;
      
      while (r1 > 0) {
         q = r0 / r1;
         
         rs = r0;
         us = u0;
         vs = v0;
         
         r0 = r1;
         u0 = u1;
         v0 = v1;
         
         r1 = rs - q * r1;
         u1 = us - q * u1;
         v1 = vs - q * v1;
      }
      
      return v0 < 0 ? phi + v0 : v0;
   }  

   friend std::ostream &operator<<( std::ostream &os, const Keys &data );

public:
   Keys() : p_(0), q_(0), n_(0), phi_(0), e_(0), d_(0), operational_(false)        
   {
      generate();
   }
   
   bool isOperational() 
   {
      return operational_;
   }

   Rsa_pub_key getPublicKey() 
   {
      Rsa_pub_key key(n_, e_);
      return key;
   }

   Rsa_priv_key getPrivateKey() 
   {
      Rsa_priv_key key(n_, d_);
      return key;
   }

   unsigned getKeyLength() 
   {
      return RSA_LENGTH;
   }
   
};

inline std::ostream &operator<<(std::ostream &os, const Keys &data) 
{
   return os << 
      "p : " << data.p_ << std::endl << 
      "-----------------" << std::endl <<
      "q : " << data.q_ << std::endl <<
      "-----------------" << std::endl <<
      "n : " << data.n_ << std::endl <<
      "-----------------" << std::endl <<
      "phi : " << data.phi_ << std::endl <<
      "-----------------" << std::endl <<
      "e : " << data.e_ << std::endl <<
      "-----------------" << std::endl <<
      "d : " << data.d_;
}

} // namespace

#endif 
