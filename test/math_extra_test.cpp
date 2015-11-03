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
 * along with myRSA.  If not, see <http://www.gnu.org/licenses/>. 
 */ 

/**
 * @author Corentin MARCIAU	<corentin@marciau.fr>
 */

/**
 * @file math_extra_test.cpp
 */

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE math_extra_testmod

#include <boost/test/unit_test.hpp>
#include <boost/multiprecision/gmp.hpp>
#include <boost/multiprecision/integer.hpp>
#include "math_extra/math_extra.hpp"

using int_type = boost::multiprecision::mpz_int;

// basics::inverse

BOOST_AUTO_TEST_SUITE( inversion_modulaire_suite )

BOOST_AUTO_TEST_CASE( trivial_case )
{
    BOOST_TEST_MESSAGE( "________________________________________" );
    BOOST_TEST_MESSAGE( "Trivial test:\n\tinverse(4, 11) == 3" );
    BOOST_CHECK_MESSAGE( basics::inverse(4, 11) == 3, "KO" );
    BOOST_TEST_MESSAGE( "OK" );
}

BOOST_AUTO_TEST_CASE( bad_case_1 ) 
{
    BOOST_TEST_MESSAGE( "________________________________________" );
    BOOST_TEST_MESSAGE( "Bad case 1:\n\tinverse(0, 11) should throw exception" );
    BOOST_CHECK_THROW( basics::inverse(0, 11), std::runtime_error);
    BOOST_TEST_MESSAGE( "OK" );
}

BOOST_AUTO_TEST_CASE( bad_case_2 )
{
    BOOST_TEST_MESSAGE( "________________________________________" );
    BOOST_TEST_MESSAGE( "Bad case 2:\n\tinverse(11, 11) should throw exception" );
    BOOST_CHECK_THROW( basics::inverse(11, 11), std::runtime_error);
    BOOST_TEST_MESSAGE( "OK" );
}

BOOST_AUTO_TEST_CASE( bad_case_3 )
{
    BOOST_TEST_MESSAGE( "________________________________________" );    
    BOOST_TEST_MESSAGE( "Bad case 3:\n\tinverse(3, -1) should throw exception" );
    BOOST_CHECK_THROW( basics::inverse(3, -1), std::runtime_error);
    BOOST_TEST_MESSAGE( "OK" );
}

BOOST_AUTO_TEST_SUITE_END()

// basics::powModulus

BOOST_AUTO_TEST_SUITE( exponentiation_modulaire_suite )

BOOST_AUTO_TEST_CASE( trivial_case )
{
    BOOST_TEST_MESSAGE( "________________________________________" );
    BOOST_TEST_MESSAGE( "Trivial test:\n\tpowModulus(2, 5, 3) == 2" );
    BOOST_CHECK_MESSAGE( basics::powModulus(2, 5, 3) == 2, "KO" );
    BOOST_TEST_MESSAGE( "OK" );
}

BOOST_AUTO_TEST_CASE( specific_case_1 )
{
    BOOST_TEST_MESSAGE( "________________________________________" );
    BOOST_TEST_MESSAGE( "Specific case 1:\n\tpowModulus(0, 5, 3) == 0" );
    BOOST_CHECK_MESSAGE( basics::powModulus(0, 5, 3) == 0, "KO" );
    BOOST_TEST_MESSAGE( "OK" );
}

BOOST_AUTO_TEST_CASE( specific_case_2 )
{
    BOOST_TEST_MESSAGE( "________________________________________" );
    BOOST_TEST_MESSAGE( "Specific case 2:\n\tpowModulus(2, 0, 3) == 1" );
    BOOST_CHECK_MESSAGE( basics::powModulus(2, 0, 3) == 1, "KO" );
    BOOST_TEST_MESSAGE( "OK" );
}

BOOST_AUTO_TEST_CASE( bad_case_1 ) 
{
    BOOST_TEST_MESSAGE( "________________________________________" );
    BOOST_TEST_MESSAGE( "Bad case 1:\n\tpowModulus(2, 5, 0) should throw exception" );
    BOOST_CHECK_THROW( basics::powModulus(2, 5, 0), std::runtime_error);
    BOOST_TEST_MESSAGE( "OK" );
}

BOOST_AUTO_TEST_CASE( bad_case_2 ) 
{
    BOOST_TEST_MESSAGE( "________________________________________" );
    BOOST_TEST_MESSAGE( "Bad case 2:\n\tpowModulus(-1, 5, 3) should throw exception" );
    BOOST_CHECK_THROW( basics::powModulus(-1, 5, 3), std::runtime_error);
    BOOST_TEST_MESSAGE( "OK" );
}

BOOST_AUTO_TEST_CASE( bad_case_3 ) 
{
    BOOST_TEST_MESSAGE( "________________________________________" );
    BOOST_TEST_MESSAGE( "Bad case 3:\n\tpowModulus(2, -1, 3) should throw exception" );
    BOOST_CHECK_THROW( basics::powModulus(2, -1, 3), std::runtime_error);
    BOOST_TEST_MESSAGE( "OK" );
}

BOOST_AUTO_TEST_SUITE_END()

