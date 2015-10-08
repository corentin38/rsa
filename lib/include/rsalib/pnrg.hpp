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
 * @version 1.0.0 / 04-09-2015
 * @todo 
 * @bug 
 */

/** 
 * @file pnrg.hpp
 * @brief 
 *
 * 
 */

#ifndef _PNRG_HPP_
#define _PNRG_HPP_

#include <boost/multiprecision/gmp.hpp>
#include <boost/multiprecision/miller_rabin.hpp>

namespace basics {

using namespace boost::random;
using namespace boost::multiprecision;

typedef mpz_int int_type;

class Pnrg {

private:
   int key_length_;
   
public:
   Pnrg(int key_length) : key_length_(key_length) 
   {
   }
   
   int_type getPrime() 
   {
      mt11213b base_gen(clock());
      independent_bits_engine<mt11213b, RSA_LENGTH/2, int_type> gen(base_gen);
      mt19937 gen2(clock());
      
      /* Voir si le test en plus serait utile ? De toutes les façons, il fait exploser le */
      for (unsigned i = 0; i < 10000; i++) {
         int_type n = gen();
         if (miller_rabin_test(n, 25, gen2) /*&& miller_rabin_test((n-1)/2, 25, gen2)*/) {
            return n;
         }
      }
      
      return 0;
   }
};

} // namespaces
   
#endif
