/**
 * INSERT LICENCE INFORMATION HERE 
 */ 

/**
 * @author Corentin MARCIAU	<corentin@marciau.fr>
 */

/** 
 * @file i2osp_os2ip.hpp
 */

#ifndef _I2OSP_OS2IP_HPP_
#define _I2OSP_OS2IP_HPP_

#include "rsa/rsa_pub_key.hpp"
#include "rsa/rsa_priv_key.hpp"

#include <boost/multiprecision/gmp.hpp>

namespace basics {

typedef boost::multiprecision::mpz_int int_type;

class I2osp_os2ip 
{

public:
   I2osp_os2ip();
      
   int_type os2ip(Rsa_pub_key pubkey, std::string message_part);
   std::string i2osp(Rsa_priv_key privkey, int_type message_part);

};         

}//namespace

#endif
