/** -*- c-basic-offset: 3 -*- 
 *
 * ENSICAEN
 * 6 Boulevard Maréchal Juin 
 * F-14050 Caen Cedex
 * 
 * Ce fichier est l'oeuvre d'élèves de l'ENSI de Caen. Il ne peut être 
 * reproduit, utilisé ou modifié sans l'avis express de ses auteurs.
 * 
 */ 

/** 
 * @author Corentin MARCIAU	<corentin.marciau@ecole.ensicaen.fr>
 *
 * @version 1.0.0 / 05-09-2015
 * @todo 
 * @bug 
 */

/** 
 * @file cipher.hpp
 * @brief 
 *
 * 
 */

#ifndef _CIPHER_HPP_
#define _CIPHER_HPP_

#include "keys.hpp"
#include "i2osp_os2ip.hpp"
#include "rsaep_rsadp.hpp"

namespace basics {

class Cipher {
   
public:
   Cipher(I2osp_os2ip data_prim, Rsaep_rsadp crypt_prim);

   std::vector< int_type > cipher(Rsa_pub_key pubkey, std::string message);
   std::string decipher(Rsa_priv_key privkey, std::vector< int_type > cipher_elements);
   
private:
   I2osp_os2ip data_prim_;
   Rsaep_rsadp crypt_prim_;

   int_type crypt_prim(Rsa_pub_key pubkey, std::string message);
   std::string decrypt_prim(Rsa_priv_key privkey, int_type cipher_text);
   
};

}

#endif
