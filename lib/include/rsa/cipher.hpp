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

#include "i2osp_os2ip.hpp"
#include "crypt_prim.hpp"

namespace basics {

class Cipher {
    
public:
    Cipher(I2osp_os2ip data_prim, Crypt_prim *crypt_prim);
    ~Cipher();

    std::vector< int_type > cipher(Rsa_pub_key pubkey, std::string message);
    std::string decipher(Rsa_priv_key privkey, std::vector< int_type > cipher_elements);
    
private:
    I2osp_os2ip data_prim_;
    Crypt_prim *crypt_prim_;

    int_type crypt(Rsa_pub_key pubkey, std::string message);
    std::string decrypt(Rsa_priv_key privkey, int_type cipher_text);
    
};

}

#endif
