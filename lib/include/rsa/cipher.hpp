/**
 * INSERT LICENCE INFORMATION HERE 
 */ 

/**
 * @author Corentin MARCIAU	<corentin@marciau.fr>
 */

/** 
 * @file cipher.hpp
 */

#ifndef _CIPHER_HPP_
#define _CIPHER_HPP_

#include "int_type.hpp"

#include "data_prim.hpp"
#include "crypt_prim.hpp"

namespace basics {

class Cipher {
    
public:
    Cipher(std::unique_ptr<Data_prim> data_prim_ptr, std::unique_ptr<Crypt_prim> crypt_prim_ptr);
    ~Cipher();

    std::vector< int_type > cipher(Rsa_pub_key pubkey, std::string message);
    std::string decipher(Rsa_priv_key privkey, std::vector< int_type > cipher_elements);

    // Too early for this
    Cipher(const basics::Cipher&) = delete;
    Cipher& operator=(const Cipher& c) = delete;
    
private:
    std::unique_ptr<Data_prim> data_prim_ptr_;
    std::unique_ptr<Crypt_prim> crypt_prim_ptr_;

    int_type crypt(Rsa_pub_key pubkey, std::string message);
    std::string decrypt(Rsa_priv_key privkey, int_type cipher_text);
    
};

} // namespace

#endif
