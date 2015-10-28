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
 * @file rsa_pub_key.cpp
 */

#include "rsa/rsa_pub_key.hpp"

basics::Rsa_pub_key::Rsa_pub_key(unsigned rsa_key_length, 
                                 unsigned char_size, 
                                 basics::int_type n, 
                                 basics::int_type e) 
    : n_(n), e_(e), rsa_key_length_(rsa_key_length), 
      max_message_length_(rsa_key_length / char_size - 1)
{
}

