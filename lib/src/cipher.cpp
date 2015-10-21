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
std::vector< basics::int_type > basics::Cipher::cipher(basics::Rsa_pub_key pubkey, std::string message) 
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

std::string basics::Cipher::decipher(basics::Rsa_priv_key privkey, 
                                     std::vector< basics::int_type > cipher_elements) 
{
   std::stringstream msgstream;
   
   for (unsigned i=0; i<cipher_elements.size(); i++) {
      msgstream << decrypt(privkey, cipher_elements[i]);
   }
   
   return msgstream.str();
}

// Private
basics::int_type 
basics::Cipher::crypt(basics::Rsa_pub_key pubkey, 
                      std::string message) 
{
   basics::int_type message_int = data_prim_ptr_->os2ip(pubkey, message);
   basics::int_type cipher_int = crypt_prim_ptr_->rsaep(pubkey, message_int);
   
   return cipher_int;
}

std::string 
basics::Cipher::decrypt(basics::Rsa_priv_key privkey, 
                        basics::int_type cipher_text) 
{
   basics::int_type message_int = crypt_prim_ptr_->rsadp(privkey, cipher_text);
   std::string message = data_prim_ptr_->i2osp(privkey, message_int);
   
   return message;      
}

