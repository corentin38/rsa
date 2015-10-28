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
 * @file int_type.hpp
 */

#ifndef BASICS_INT_TYPE_HPP
#define BASICS_INT_TYPE_HPP

#include <boost/multiprecision/gmp.hpp>

namespace basics {

/** 
 * Définition du type entier utilisé par myRSA. La gestion de grands
 * entiers nécessaire pour l'application de l'algorithme RSA nécessite
 * une bibliothèque spéciale et un type particulier pour stocker et
 * manipuler des entiers d'une taille très suppérieure au type
 * primitif "int". Pour cela, on utilise Boost multiprecision.
 * 
 * La définition d'un type "int_type" générique permet éventuellement
 * de changer l'implémentation choisie pour le type_entier en ne
 * modifiant que ce fichier.
 */
using int_type = boost::multiprecision::mpz_int;

} // namespace

#endif
