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
 * @file pnrg.hpp
 *
 * @todo
 *  - Implémenter un vrai générateur de nombre aléatoires avec Boost
 *    random device et/ou une méthode appropriée pour la cryptographie
 * 
 */

#ifndef BASICS_PNRG_HPP
#define BASICS_PNRG_HPP

#include "int_type.hpp"

namespace basics {

/** 
 * Classe de génération de nombres aléatoires pour les clefs, le
 * module de chiffrement et les autres entiers nécessaires à
 * l'algorithme RSA.
 */
class Pnrg {

public:

    /** 
     * Constructeur
     *
     * @param  key_length  longueur souhaitée pour la clef RSA en
     *                     bits. Ex : 512 bits
     */
    Pnrg(unsigned key_length);

    /** 
     * Seule méthode de Pnrg. Fourni un nombre premier aléatoire sur
     * key_length bits, comme passé au constructeur. Attention, la
     * méthode utilisée est pratique mais pas sécurisée. Pour une
     * vraie utilisation, il faudrait renforcer l'aléa.
     */
    int_type getPrime() const;

private:
    unsigned key_length_;
   
};

} // namespaces
   
#endif
