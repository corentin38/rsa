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


int main()
{
   std::string message = "Hello woooorld !";
   std::cout << "Message clair : " << message << std::endl;

   // Création des cléfs
   basics::Keys keys;
   if (!keys.isOperational()) {
      std::cout << "Key is not operational : " << std::endl;
      std::cout << keys << std::endl;
      return 1;
   }

   basics::I2osp_os2ip data_prim(keys.getKeyLength());
   basics::Rsaep_rsadp crypt_prim(keys);

   // Chiffrement
   basics::Cipher cipher((unsigned) keys.getKeyLength(), data_prim, crypt_prim);
   std::string s3cr3t = cipher.cipher(message);
   
   std::cout << "Message chiffré : " << s3cr3t << std::endl;

   // Test des primitives de conversion
//   basics::I2osp_os2ip prim(1024);
//   basics::int_type code = prim.os2ip(message);
//   std::cout << "Encoded message with os2ip: " << code << std::endl;
//   std::string decode = prim.i2osp(code);
//   std::cout << "Decoded message with i2osp: " << decode << std::endl;
//   
   


   return 0;
}

