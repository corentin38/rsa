/**
 * INSERT LICENCE INFORMATION HERE 
 */ 

/**
 * @author Corentin MARCIAU	<corentin@marciau.fr>
 */

/**
 * @file math_extra.cpp
 */

#include "math_extra/math_extra.hpp"

#include <iostream>

basics::int_type basics::inverse(basics::int_type e, basics::int_type phi) 
{
    basics::int_type r0=phi, r1=e, u0=1, u1=0, v0=0, v1=1;
    basics::int_type q=0, rs=0, us=0, vs=0;
    
    while (r1 > 0) {
        q = r0 / r1;
        
        rs = r0;
        us = u0;
        vs = v0;
        
        r0 = r1;
        u0 = u1;
        v0 = v1;
        
        r1 = rs - q * r1;
        u1 = us - q * u1;
        v1 = vs - q * v1;
    }
    
    return v0 < 0 ? phi + v0 : v0;
}  

basics::int_type basics::powModulus(basics::int_type base, basics::int_type exp, basics::int_type mod) 
{
    if (exp == 0) return 1;
    if (base == 0) return 0;
    if (mod <= 0) {
        std::stringstream err;
        err << "null or negative modulus: " << mod;
        throw std::runtime_error(err.str());
    }

    basics::int_type exp_bits = exp;
    basics::int_type acc = 1;
    
    // Modular exponentiation specific to RSA
    for (basics::int_type acc_square = base; exp_bits > 0; exp_bits = exp_bits >> 1) {
        if (exp_bits & 1) {
            acc = (acc * acc_square) % mod;
        }
        acc_square = (acc_square * acc_square) % mod;
    }
    
    return acc;
}   
