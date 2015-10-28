/**
 * This file is part of myRSA.
 * 
 * myRSA is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * myRSA is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Foobar.  If not, see <http://www.gnu.org/licenses/>. 
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

basics::int_type basics::Pnrg::getPrime() const
{
    using mt11213b = boost::random::mt11213b;
    using mt19937  = boost::random::mt19937;    

    mt11213b base_gen(clock());
    boost::random::independent_bits_engine< mt11213b, basics::rsa_length/2, basics::int_type > gen(base_gen);
    
    mt19937 gen2(clock());
    
    /* Voir si le test en plus serait utile ? De toutes les façons, il fait exploser le */
    for (unsigned i = 0; i < 10000; i++) {
        basics::int_type n = gen();
        if (miller_rabin_test(n, 25, gen2) /*&& miller_rabin_test((n-1)/2, 25, gen2)*/) {
            return n;
        }
    }
    
    return 0;
}
