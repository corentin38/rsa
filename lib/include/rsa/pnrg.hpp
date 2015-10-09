/**
 * INSERT LICENCE INFORMATION HERE 
 */ 

/**
 * @author Corentin MARCIAU	<corentin@marciau.fr>
 */

/**
 * @file pnrg.hpp
 */

#ifndef _PNRG_HPP_
#define _PNRG_HPP_

#include <boost/multiprecision/gmp.hpp>

namespace basics {

typedef boost::multiprecision::mpz_int int_type;

class Pnrg {

public:
   Pnrg(unsigned key_length);

   int_type getPrime();

private:
   unsigned key_length_;
   
};

} // namespaces
   
#endif
