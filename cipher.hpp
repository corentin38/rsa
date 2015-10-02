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
#include <string>
#include <sstream>
#include <stdexcept>

namespace basics {

class Cipher {
   
public:
   Cipher(I2osp_os2ip data_prim, Rsaep_rsadp crypt_prim) : 
      data_prim_(data_prim), crypt_prim_(crypt_prim)
   {
   }
   
   std::vector< int_type > cipher(Rsa_pub_key pubkey, std::string message) 
   {
      std::vector< int_type > cipher_elements;
      unsigned message_length = pubkey.getMaxMessageLength();

      std::string message_part = message;
      while(message_part.size() >= message_length) {
         std::string message_substring = message_part.substr(0, message_length);
         message_part = message_part.substr(message_length);         
         cipher_elements.push_back(crypt_prim(pubkey, message_substring));
      }

      // Remainder
      cipher_elements.push_back(crypt_prim(pubkey, message_part));
   
      return cipher_elements;
   }

   std::string decipher(Rsa_priv_key privkey, std::vector< int_type > cipher_elements) 
   {
      std::stringstream msgstream;

      for (unsigned i=0; i<cipher_elements.size(); i++) {
         msgstream << decrypt_prim(privkey, cipher_elements[i]);
      }

      return msgstream.str();
   }
   

private:
   I2osp_os2ip data_prim_;
   Rsaep_rsadp crypt_prim_;

   int_type crypt_prim(Rsa_pub_key pubkey, std::string message) 
   {
//      std::cout << "  Ciphering : " << message << "\n";

      int_type message_int = data_prim_.os2ip(pubkey, message);
      int_type cipher_int = crypt_prim_.rsaep(pubkey, message_int);

      return cipher_int;
   }
   
   std::string decrypt_prim(Rsa_priv_key privkey, int_type cipher_text) 
   {
      int_type message_int = crypt_prim_.rsadp(privkey, cipher_text);
      std::string message = data_prim_.i2osp(privkey, message_int);
      
      return message;      
   }
   
   
};

}

#endif
