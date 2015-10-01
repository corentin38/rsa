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
 * @author Corentin MARCIAU	<corentin@marciau.fr>
 *
 * @version 1.0.0 / 01-09-2015
 * @todo 
 * @bug 
 */

/**
 * @file rsa.cpp
 * @brief 
 *
 * 
 */

#include "keys.hpp"
#include "cipher.hpp"
#include "pnrg.hpp"
#include "i2osp_os2ip.hpp"
#include "rsaep_rsadp.hpp"

#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>

void print_cipher_text(std::vector< int_type > cipher_elements) 
{
   std::cout << "Message chiffré : \n\n";
   std::cout << "-- CIPHERTEXT BEGIN --\n";

   for (int_type element : cipher_elements) {
      std::stringstream cipher_text_stream;
      cipher_text_stream << std::hex << element;
      std::string cipher_text = cipher_text_stream.str();

      std::cout << cipher_text << "\n";
   }

   std::cout << "-- CIPHERTEXT END --\n";
}

int main()
{
   std::string message = "Hello woooorld !"
      "Hello woooorld !"
      "Hello woooorld !"
      "Hello woooorld !"
      "Hello woooorld !"
      "Hello woooorld !"
      "Hello woooorld !"
      "Hello woooorld !"; // 128 char message
   std::cout << "Message clair : " << message << std::endl;

   // Création des cléfs
   basics::Keys keys;
   if (!keys.isOperational()) {
      std::stringstream err;
      err << "Key is not operational : \n";
      err << keys << "\n";
      throw std::runtime_error(err.str());
   }

   basics::I2osp_os2ip data_prim();
   basics::Rsaep_rsadp crypt_prim();

   // Chiffrement
   basics::Cipher my_cipher(data_prim, crypt_prim);
   std::vector< int_type > s3cr3t = my_cipher.cipher(keys.getPubKey(), message);
   print_cipher_text(s3cr3t);


   
   


   return 0;
}

