/**
 * INSERT LICENCE INFORMATION HERE 
 */ 

/**
 * @author Corentin MARCIAU	<corentin@marciau.fr>
 */

/**
 * @file pnrg.cpp
 */

#include "rsa/pnrg.hpp"
#include "rsa/keys.hpp"

#include <boost/multiprecision/miller_rabin.hpp>

basics::Pnrg::Pnrg(unsigned key_length) : key_length_(key_length) 
{
}

// TODO: Make RSA_LENGTH dynamic with key_length_
basics::int_type basics::Pnrg::getPrime() 
{
    boost::random::mt11213b base_gen(clock());
    boost::random::independent_bits_engine< boost::random::mt11213b, basics::rsa_length/2, basics::int_type > gen(base_gen);
    boost::random::mt19937 gen2(clock());
    
    /* Voir si le test en plus serait utile ? De toutes les façons, il fait exploser le */
    for (unsigned i = 0; i < 10000; i++) {
        basics::int_type n = gen();
        if (miller_rabin_test(n, 25, gen2) /*&& miller_rabin_test((n-1)/2, 25, gen2)*/) {
            return n;
        }
    }
    
    return 0;
}
