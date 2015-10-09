/**
 * INSERT LICENCE INFORMATION HERE 
 */ 

/**
 * @author Corentin MARCIAU	<corentin@marciau.fr>
 */

/**
 * @file rsa_priv_key.cpp
 */

#include "rsa/rsa_priv_key.hpp"

basics::Rsa_priv_key::Rsa_priv_key(
    unsigned rsa_key_length, 
    unsigned char_size, 
    basics::int_type n, 
    basics::int_type d) : 
    n_(n), d_(d),
    rsa_key_length_(rsa_key_length),
    max_message_length_(rsa_key_length / char_size - 1)
{
}

