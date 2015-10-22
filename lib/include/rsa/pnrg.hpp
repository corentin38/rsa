/**
 * INSERT LICENCE INFORMATION HERE 
 */ 

/**
 * @author Corentin MARCIAU	<corentin@marciau.fr>
 */

/**
 * @file pnrg.hpp
 */

#ifndef BASICS_PNRG_HPP
#define BASICS_PNRG_HPP

#include "int_type.hpp"

namespace basics {

class Pnrg {

public:
   Pnrg(unsigned key_length);

   int_type getPrime() const;

private:
   unsigned key_length_;
   
};

} // namespaces
   
#endif
