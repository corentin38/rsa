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

#include "rsa/data_prim.hpp"

#include "rsa/rsa_pub_key.hpp"
#include "rsa/rsa_priv_key.hpp"

#include <boost/multiprecision/gmp.hpp>

namespace basics {

typedef boost::multiprecision::mpz_int int_type;

class I2osp_os2ip : public basics::Data_prim
{

public:
    I2osp_os2ip();
    ~I2osp_os2ip();
      
    int_type os2ip(const Rsa_pub_key& pubkey, const std::string& message_part);
    std::string i2osp(const Rsa_priv_key& privkey, const int_type& message_part);

};         

}//namespace

#endif
