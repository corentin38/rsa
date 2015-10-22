/**
 * INSERT LICENCE INFORMATION HERE 
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
