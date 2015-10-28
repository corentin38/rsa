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
 * @file i2osp_os2ip.hpp
 */

#ifndef BASICS_I2OSP_OS2IP_HPP
#define BASICS_I2OSP_OS2IP_HPP

#include "int_type.hpp"
#include "data_prim.hpp"
#include "rsa_pub_key.hpp"
#include "rsa_priv_key.hpp"

namespace basics {

/** 
 * Implémentation de l'interface Data_prim décrite dans le standard
 * PKCS #1
 */
class I2osp_os2ip : public basics::Data_prim
{

public:
    I2osp_os2ip();
    ~I2osp_os2ip();

    /** 
     * Convertis un message sous forme de string standard en un entier
     * exploitable par une primitive cryptographique.
     *
     * @param pubKey         Clef publique RSA pour connaître la largeur
     *                       du domaine de chiffrement
     * @param message_part   message sous forme de std::string
     * @return               message sous forme d'entier
     */
    int_type os2ip(const Rsa_pub_key& pubkey, const std::string& message_part);

    /** 
     * Convertis un entier tel que fourni par une primitive
     * cryptographique en chaîne de caractères lisible
     * 
     * @param privkey        Clef privée RSA pour connaître la largeur
     *                       du domaine de chiffrement
     * @param message_part   message sous forme d'entier
     * @return               message sous forme de chaîne de
     *                       caractères lisible
     */
    std::string i2osp(const Rsa_priv_key& privkey, const int_type& message_part);

};         

}//namespace

#endif
