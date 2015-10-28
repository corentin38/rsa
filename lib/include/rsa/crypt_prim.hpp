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
 * @file crypt_prim.hpp
 */

#ifndef BASICS_CRYPT_PRIM_HPP
#define BASICS_CRYPT_PRIM_HPP

#include "int_type.hpp"
#include "rsa_pub_key.hpp"
#include "rsa_priv_key.hpp"

namespace basics {

/** 
 * Interface de primitive cryptographique utilisable par la classe Cipher.
 */
class Crypt_prim 
{
public:
    virtual ~Crypt_prim() {};

    /** 
     * La méthode rsaep pour RSA Encryption Primitive prend une clef
     * publique et un message sous forme d'entier et renvoie un entier
     * chiffré selon la description du standard PKCS #1
     *
     * @param   pubkey    clef publique Rsa_pub_key contenant le
     *                    module et l'exposant de chiffrement
     * @param   message   entier à chiffrer
     *
     * @return  le chiffré correspondant au message sous forme d'entier
     */
    virtual int_type rsaep(const Rsa_pub_key& pubkey, const int_type& message) = 0;

    /** 
     * La méthode rsadp pour RSA De-encryption Primitive prend une clef
     * privée et un chiffré sous forme d'entier et renvoie le message
     * original sous la forme d'un entier selon la description du
     * standard PKCS #1
     *
     * @param   privkey      clef privée Rsa_priv_key contenant le
     *                       module et l'exposant de déchiffrement
     * @param   cipher_text  entier à déchiffrer
     *
     * @return  le message correspondant au chiffré sous forme d'entier
     */
    virtual int_type rsadp(const Rsa_priv_key& privkey, const int_type& cipher_text) = 0;
};

} //namespace

#endif
