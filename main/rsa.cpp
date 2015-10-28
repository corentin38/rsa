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
 * @file rsa.cpp
 */

#include "rsa/int_type.hpp"
#include "rsa/keys.hpp"
#include "rsa/cipher.hpp"
#include "rsa/i2osp_os2ip.hpp"
#include "rsa/rsaep_rsadp.hpp"

#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>

void print_cipher_text(std::vector< basics::int_type > cipher_elements) 
{
   std::cout << "Message chiffré : \n\n";
   std::cout << "-- CIPHERTEXT BEGIN --\n";

   for (unsigned i=0; i<cipher_elements.size(); i++) {
      std::stringstream cipher_text_stream;
      cipher_text_stream << std::hex << cipher_elements[i];
      std::string cipher_text = cipher_text_stream.str();

      std::cout << cipher_text << "\n";
   }

   std::cout << "-- CIPHERTEXT   END --\n";
}

int main()
{
   std::string message = "Hello woooorld !"
      "Hello woooorld !"
      "Hello woooorld !"
      "Hello woooorldX"
      "Hello woooorld !"
      "Hello woooorld !"
      "Hello woooorld !"
      "Hello woooorldXMORE?"; // 128 char message
   std::cout << "Message clair : \n\n" << message << "\n\n";

   // Création des cléfs
   basics::Keys keys;
   if (!keys.isOperational()) {
      std::stringstream err;
      err << "Key is not operational : \n";
      err << keys << "\n";
      throw std::runtime_error(err.str());
   }

   // Initialisation du chiffreur
//   basics::Data_prim *data_prim = new basics::I2osp_os2ip();
//   basics::Crypt_prim *crypt_prim = new basics::Rsaep_rsadp();

   std::unique_ptr<basics::Data_prim> data_prim_ptr( new basics::I2osp_os2ip() );
   std::unique_ptr<basics::Crypt_prim> crypt_prim_ptr( new basics::Rsaep_rsadp() );

   basics::Cipher my_cipher( std::move(data_prim_ptr), std::move(crypt_prim_ptr) );

   // Chiffrement
   std::vector< basics::int_type > s3cr3t = my_cipher.cipher(keys.getPublicKey(), message);
   print_cipher_text(s3cr3t);

   // Déchiffrement
   std::string deciphered = my_cipher.decipher(keys.getPrivateKey(), s3cr3t);
   std::cout << "\nMessage déchiffré : \n\n" << deciphered << std::endl;

   return 0;
}

