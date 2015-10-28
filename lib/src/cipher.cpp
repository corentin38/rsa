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
 * @file cipher.cpp
 */

#include "rsa/cipher.hpp"

// Constructor / Destructor
basics::Cipher::Cipher( std::unique_ptr<basics::Data_prim> data_prim_ptr, 
                        std::unique_ptr<basics::Crypt_prim> crypt_prim_ptr) : 
   data_prim_ptr_( std::move(data_prim_ptr) ), crypt_prim_ptr_( std::move(crypt_prim_ptr) )
{
}

basics::Cipher::~Cipher() 
{
}

// Public
std::vector< basics::int_type > 
basics::Cipher::cipher(const basics::Rsa_pub_key& pubkey, const std::string& message) 
{
   std::vector< int_type > cipher_elements;
   unsigned message_length = pubkey.getMaxMessageLength();
   
   std::string message_part = message;
   while(message_part.size() >= message_length) {
      std::string message_substring = message_part.substr(0, message_length);
      message_part = message_part.substr(message_length);         
      cipher_elements.push_back(crypt(pubkey, message_substring));
   }
   
   // Remainder
   cipher_elements.push_back(crypt(pubkey, message_part));
   
   return cipher_elements;
}

std::string basics::Cipher::decipher(const basics::Rsa_priv_key& privkey, 
                                     const std::vector< basics::int_type >& cipher_elements) 
{
   std::stringstream msgstream;
   
   for (unsigned i=0; i<cipher_elements.size(); i++) {
      msgstream << decrypt(privkey, cipher_elements[i]);
   }
   
   return msgstream.str();
}

// Private
basics::int_type 
basics::Cipher::crypt(const basics::Rsa_pub_key& pubkey, 
                      const std::string& message) 
{
   basics::int_type message_int = data_prim_ptr_->os2ip(pubkey, message);
   basics::int_type cipher_int = crypt_prim_ptr_->rsaep(pubkey, message_int);
   
   return cipher_int;
}

std::string 
basics::Cipher::decrypt(const basics::Rsa_priv_key& privkey, 
                        const basics::int_type& cipher_text) 
{
   basics::int_type message_int = crypt_prim_ptr_->rsadp(privkey, cipher_text);
   std::string message = data_prim_ptr_->i2osp(privkey, message_int);
   
   return message;      
}

