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
 * @file data_prim.hpp
 */

#ifndef BASICS_DATA_PRIM_HPP
#define BASICS_DATA_PRIM_HPP

#include "int_type.hpp"
#include "rsa_pub_key.hpp"
#include "rsa_priv_key.hpp"

namespace basics {

typedef boost::multiprecision::mpz_int int_type;

/** 
 * Interface de primitive de données utilisable par la classe Cipher.
 */
class Data_prim {
   
public:
    virtual ~Data_prim() {};

    /** 
     * La méthode os2ip pour Octet String To Integer Primitive prend
     * une chaîne de caractères et renvoie sa représentation sous
     * forme d'un entier.
     *
     * @param  pubkey     Clef publique RSA pour connaître la largeur
     *                    du domaine de chiffrement
     * @param  message    Le message sous forme de string. Si le
     *                    message est trop long pour être converti en
     *                    entier dans le domaine de chiffrement (<N), 
     *                    une erreur "message out of range" est
     *                    levée. 
     *
     * @return  Un entier représentant le message et restituant le
     *          message original si passé à i2osp.
     */
    virtual int_type os2ip(const Rsa_pub_key& pubkey, const std::string& message_part) = 0;

    /** 
     * La méthode i2osp pour Integer To Octet String Primitive prend
     * un entier et renvoie le message sous forme de string qu'il
     * représente.
     *
     * @param  privkey       Clef privée RSA pour connaître la largeur
     *                       du domaine de chiffrement
     * @param  message_part  Le message sous forme d'un entier. Si le
     *                       message est trop grand pour être converti en
     *                       string dans le domaine de chiffrement (<N), 
     *                       une erreur "message out of range" est
     *                       levée. 
     *
     * @return  Le message original correspondant à la string passée à
     *          os2ip.
     */
    virtual std::string i2osp(const Rsa_priv_key& privkey, const int_type& message_part) = 0;

};

} // namespace

#endif
