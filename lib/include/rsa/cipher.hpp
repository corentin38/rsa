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
 * @author Corentin MARCIAU <corentin@marciau.fr>
 */

/** 
 * @file cipher.hpp
 *
 * @todo
 * - Passer à des templates plutôt que par une ABC pour les
 *   interfaces. 
 */

#ifndef BASICS_CIPHER_HPP
#define BASICS_CIPHER_HPP

#include "int_type.hpp"
#include "data_prim.hpp"
#include "crypt_prim.hpp"

namespace basics {

/** 
 * Classe gérant le chiffrement de bout en bout à l'aide
 * d'une primitive de données et d'une primitive cryptographique
 * fournies respectivement par une implémentation de Data_prim et une
 * autre de Crypt_prim.
 */
class Cipher {
    
public:
    Cipher(std::unique_ptr<Data_prim> data_prim_ptr, std::unique_ptr<Crypt_prim> crypt_prim_ptr);
    ~Cipher();

    /** 
     * Fonction tout en un pour chiffrer un message sous forme de
     * string de n'importe quelle longueur. Renvoie le chiffré sous
     * forme de vecteur d'entiers correspondant aux chiffrés de chaque
     * tronçon la string.
     *
     * @param  pubkey    Clef publique contenant N et e
     * @param  message   message de n'importe quelle longueur
     *
     * @return  Un vecteur de chiffrés sous forme d'entiers
     */ 
    std::vector< int_type > cipher(const Rsa_pub_key& pubkey, const std::string& message);

    /** 
     * Fonction tout en un pour déchiffrer un code sous forme de
     * tableau d'entiers. Renvoie le message original sous forme de
     * string.
     *
     * @param  privkey          la clef privée contenant N et d
     * @param  cipher_elements  les chiffrés sous forme de vecteur
     *
     * @return  une string restituant le message original
     */
    std::string decipher(const Rsa_priv_key& privkey, const std::vector< int_type >& cipher_elements);

    /** 
     * Comme Cipher contient deux pointeurs vers les primitives, il
     * est important de ne pas pouvoir utiliser le constructeur par
     * copie. (Enfin, ça pourrait être géré, mais la flemme)
     */
    Cipher(const basics::Cipher&) = delete;

    /** 
     * Comme cipher contient deux pointeurs vers les primitives, il
     * est important de ne pas pouvoir utiliser l'opérateur
     * d'assignation. (Enfin, ça pourrait être géré, mais la flemme)
     */
    Cipher& operator=(const Cipher&) = delete;
    
private:
    std::unique_ptr<Data_prim> data_prim_ptr_;
    std::unique_ptr<Crypt_prim> crypt_prim_ptr_;

    int_type crypt(const Rsa_pub_key& pubkey, const std::string& message);
    std::string decrypt(const Rsa_priv_key& privkey, const int_type& cipher_text);
    
};

} // namespace

#endif
