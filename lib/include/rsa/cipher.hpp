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
 */

#ifndef BASICS_CIPHER_HPP
#define BASICS_CIPHER_HPP

#include "int_type.hpp"
#include "data_prim.hpp"
#include "crypt_prim.hpp"

namespace basics {

class Cipher {
    
public:
    Cipher(std::unique_ptr<Data_prim> data_prim_ptr, std::unique_ptr<Crypt_prim> crypt_prim_ptr);
    ~Cipher();

    std::vector< int_type > cipher(const Rsa_pub_key& pubkey, const std::string& message);
    std::string decipher(const Rsa_priv_key& privkey, const std::vector< int_type >& cipher_elements);

    // Too early for this
    Cipher(const basics::Cipher&) = delete;
    Cipher& operator=(const Cipher& c) = delete;
    
private:
    std::unique_ptr<Data_prim> data_prim_ptr_;
    std::unique_ptr<Crypt_prim> crypt_prim_ptr_;

    int_type crypt(const Rsa_pub_key& pubkey, const std::string& message);
    std::string decrypt(const Rsa_priv_key& privkey, const int_type& cipher_text);
    
};

} // namespace

#endif
