/**
 * INSERT LICENCE INFORMATION HERE 
 */ 

/**
 * @author Corentin MARCIAU	<corentin@marciau.fr>
 */

/**
 * @file int_type.hpp
 */

#ifndef BASICS_INT_TYPE_HPP
#define BASICS_INT_TYPE_HPP

#include <boost/multiprecision/gmp.hpp>

namespace basics {

using int_type = boost::multiprecision::mpz_int;

//typedef boost::multiprecision::mpz_int int_type;

} // namespace

#endif
