/** 
 * INSERT LICENCE INFORMATION HERE
 */ 

/** 
 * @author Corentin MARCIAU	<corentin@marciau.fr>
 */

/** 
 * @file rsa.cpp
 */

#include "rsa/keys.hpp"
#include "rsa/cipher.hpp"
#include "rsa/i2osp_os2ip.hpp"
#include "rsa/rsaep_rsadp.hpp"

#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>

typedef boost::multiprecision::mpz_int int_type;

void print_cipher_text(std::vector< int_type > cipher_elements) 
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
   basics::I2osp_os2ip data_prim;
   basics::Rsaep_rsadp crypt_prim;
   basics::Cipher my_cipher(data_prim, crypt_prim);

   // Chiffrement
   std::vector< int_type > s3cr3t = my_cipher.cipher(keys.getPublicKey(), message);
   print_cipher_text(s3cr3t);

   // Déchiffrement
   std::string deciphered = my_cipher.decipher(keys.getPrivateKey(), s3cr3t);
   std::cout << "\nMessage déchiffré : \n\n" << deciphered << std::endl;

   return 0;
}

