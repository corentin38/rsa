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

#define CIPHERTEXT_BEGIN "-- CIPHERTEXT BEGIN --"
#define CIPHERTEXT_END "-- CIPHERTEXT END --"

class Cipher {
   
public:
   Cipher(Keys keys, I2osp_os2ip data_prim, Rsaep_rsadp crypt_prim) : 
      data_prim_(data_prim), 
      crypt_prim_(crypt_prim), 
      key_length_(keys.getKeyLength()), 
      message_length_(keys.getKeyLength() / CHAR_SIZE - 1),
      cipher_text_hexadecimal_length_( (message_length_+1) * 2)
   {
   }
   
   std::string cipher(std::string message) 
   {
      std::string cipher_text = CIPHERTEXT_BEGIN;
      std::string message_part = message;

      while(message_part.size() >= message_length_) {
         std::string message_substring = message_part.substr(0, message_length_);
         message_part = message_part.substr(message_length_);
         
         cipher_text += "\n" + crypt_prim_str(message_substring);
      }
      
      cipher_text += "\n" + crypt_prim_str(message_part);
      cipher_text += "\n";
      cipher_text += CIPHERTEXT_END;
   
      return cipher_text;
   }

   std::string decipher(std::string cipher_text) 
   {
      std::string message = "";
      std::string cipher_text_substring = cipher_text;

      while(cipher_text_substring.size() >= message_length_) {
         std::string cipher_text_part = cipher_text_substring.substr(0, message_length_);
         cipher_text_substring = cipher_text_substring.substr(message_length_);
         
         message += decrypt_prim_str(cipher_text_part);
      }
      
      message += decrypt_prim_str(cipher_text_substring);
   
      return message;
   }
   

private:
   I2osp_os2ip data_prim_;
   Rsaep_rsadp crypt_prim_;
   
   unsigned key_length_;
   unsigned message_length_;
   unsigned cipher_text_hexadecimal_length_;
   

   std::string crypt_prim_str(std::string message) 
   {
      std::cout << "  Ciphering : " << message << "\n";

      int_type cipher_int = crypt_prim_.rsaep(data_prim_.os2ip(message));
      
      std::stringstream cipher_text_stream;
      cipher_text_stream << std::hex << cipher_int;
      std::string cipher_text = cipher_text_stream.str();

      // HEX number takes two digits for each char
      if (cipher_text.size() > cipher_text_hexadecimal_length_) {
         std::stringstream err;
         err << "Ciphertext length in hexadecimal is too wide: " << cipher_text << "\n";
         throw std::runtime_error(err.str());
      }
      
      while (cipher_text.size() < cipher_text_hexadecimal_length_) {
         cipher_text = "0" + cipher_text;
      }   

      std::cout << "  Ciphertext computed as hexa: " << cipher_text << "\n";

      return cipher_text;
   }
   
   std::string decrypt_prim_str(std::string cipher_text) 
   {
      std::string message = data_prim_.i2osp(crypt_prim_.rsadp(data_prim_.os2ip(cipher_text)));
      
      if (cipher_text.size() != message.size()) {
         std::cout << "cipher_text size different from message size" << std::endl;
      }

      return message;      
   }
   
   
};

}

#endif
