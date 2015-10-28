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
 * @file rsaep_rsadp.hpp
 */

#ifndef BASICS_RSAEP_RSADP_HPP
#define BASICS_RSAEP_RSADP_HPP

#include "int_type.hpp"
#include "crypt_prim.hpp"
#include "rsa_pub_key.hpp"
#include "rsa_priv_key.hpp"

namespace basics {

/** 
 * Implémentation de l'interface Crypt_prim.
 *
 * Primitive cryptographique telle que décrite dans le standard 
 * PKCS #1.
 */
class Rsaep_rsadp : public Crypt_prim {

public:
    Rsaep_rsadp();
    ~Rsaep_rsadp();
    
    /**
     * Chiffre le message (nombre entier) à l'aide du module et de
     * l'exposant de chiffrement contenu dans la clef publique passée
     * en paramètre
     * 
     * @param pubKey   Clef publique RSA
     * @param message  entier dans le domaine de chiffrement ( < N )
     * @return         chiffré associé au message
     */
    int_type rsaep(const Rsa_pub_key& pubkey, const int_type& message);

    /**
     * Déchiffre le chiffré (nombre entier) à l'aide du module et de
     * l'exposant de déchiffrement contenu dans la clef privée passée
     * en paramètre
     * 
     * @param privKey      Clef privée RSA
     * @param cipher_text  entier dans le domaine de chiffrement ( < N )
     * @return             message clair associé au chiffré
     */
    int_type rsadp(const Rsa_priv_key& privkey, const int_type& cipher_text);
   
};

} //namespace

#endif
