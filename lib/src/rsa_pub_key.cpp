/**
 * INSERT LICENCE INFORMATION HERE 
 */ 

/**
 * @author Corentin MARCIAU	<corentin@marciau.fr>
 */

/**
 * @file rsa_pub_key.cpp
 */

#include "rsa/rsa_pub_key.hpp"

basics::Rsa_pub_key::Rsa_pub_key(
    unsigned rsa_key_length, 
    unsigned char_size, 
    basics::int_type n, 
    basics::int_type e) : 
    n_(n), e_(e),
    rsa_key_length_(rsa_key_length),
    max_message_length_(rsa_key_length / char_size - 1)
{
}

