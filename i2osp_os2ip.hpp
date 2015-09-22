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
 * @version 1.0.0 / 11-09-2015
 * @todo 
 * @bug 
 */

/** 
 * @file i2osp_os2ip.hpp
 * @brief 
 *
 * 
 */

#ifndef _I2OSP_OS2IP_HPP_
#define _I2OSP_OS2IP_HPP_

#include <iostream>
#include <cmath>
#include <boost/multiprecision/gmp.hpp>
#include <stdexcept>
#include <sstream>


namespace basics {

typedef mpz_int int_type;

class I2osp_os2ip 
{
public:
   I2osp_os2ip(unsigned key_length) : key_length_(key_length), max_message_length_(key_length / 8)
   {
   }
   
   int_type os2ip(std::string message_part) 
   {
      if (message_part.size() > (unsigned) max_message_length_) {
         std::stringstream err;
         err << "message part too large max_size=" << max_message_length_ << 
            " size=" << message_part.size() << " str=\"" << message_part << "\"";
         throw std::runtime_error(err.str());
      }
      
      int_type message_part_int = 0;

      for (unsigned i=0; i<message_part.size(); i++) {
         message_part_int += (int_type) (message_part[i] * std::pow(256, message_part.size() -i - 1));
      }
      
      return message_part_int;
   }
   
   std::string i2osp(int_type message_part) 
   {
      if (message_part >> key_length_ > 0) {
         std::stringstream err;
         err << "integer too large (CMB)";
         throw std::runtime_error(err.str());
      }
      
      std::string message_part_str = "";
      int_type current_order(message_part);
      int_type current_char = 0;

      for (unsigned i=0; i<key_length_; i++) {
         if (current_order == 0) break;
         current_char = current_order % 256;
         message_part_str = char(current_char.convert_to<int>()) + message_part_str;
         current_order >>= 8;
      }
      
      return message_part_str;
   }

private:
   unsigned key_length_;
   unsigned max_message_length_;

};

   
         

}//namespace

#endif
