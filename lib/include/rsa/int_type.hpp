/**
 * INSERT LICENCE INFORMATION HERE 
 */ 

/**
 * @author Corentin MARCIAU	<corentin@marciau.fr>
 */

/**
 * @file int_type.hpp
 */

#ifndef _INT_TYPE_HPP_
#define _INT_TYPE_HPP_

#include <boost/multiprecision/gmp.hpp>

namespace basics {

using int_type = boost::multiprecision::mpz_int;

//typedef boost::multiprecision::mpz_int int_type;

} // namespace

#endif
