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
 * @version 1.0.0 / 07-10-2015
 * @todo 
 * @bug 
 */

/**
 * @file cipher.cpp
 * @brief 
 *
 * 
 */

#include "rsalib/cipher.hpp"

#include "rsalib/i2osp_os2ip.hpp"
#include "rsalib/rsaep_rsadp.hpp"

#include <boost/multiprecision/gmp.hpp>

#include <string>
#include <sstream>
#include <stdexcept>

typedef boost::multiprecision::mpz_int int_type;

// Constructor
basics::Cipher::Cipher(I2osp_os2ip data_prim, Rsaep_rsadp crypt_prim) : 
   data_prim_(data_prim), crypt_prim_(crypt_prim)
{
}

// Public
std::vector< int_type > basics::Cipher::cipher(Rsa_pub_key pubkey, std::string message) 
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

std::string basics::Cipher::decipher(Rsa_priv_key privkey, std::vector< int_type > cipher_elements) 
{
   std::stringstream msgstream;
   
   for (unsigned i=0; i<cipher_elements.size(); i++) {
      msgstream << decrypt_prim(privkey, cipher_elements[i]);
   }
   
   return msgstream.str();
}

// Private
int_type basics::Cipher::crypt_prim(Rsa_pub_key pubkey, std::string message) 
{
   int_type message_int = data_prim_.os2ip(pubkey, message);
   int_type cipher_int = crypt_prim_.rsaep(pubkey, message_int);
   
   return cipher_int;
}

std::string basics::Cipher::decrypt_prim(Rsa_priv_key privkey, int_type cipher_text) 
{
   int_type message_int = crypt_prim_.rsadp(privkey, cipher_text);
   std::string message = data_prim_.i2osp(privkey, message_int);
   
   return message;      
}

