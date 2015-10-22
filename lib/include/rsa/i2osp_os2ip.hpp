/**
 * INSERT LICENCE INFORMATION HERE 
 */ 

/**
 * @author Corentin MARCIAU	<corentin@marciau.fr>
 */

/** 
 * @file i2osp_os2ip.hpp
 */

#ifndef BASICS_I2OSP_OS2IP_HPP
#define BASICS_I2OSP_OS2IP_HPP

#include "int_type.hpp"
#include "data_prim.hpp"
#include "rsa_pub_key.hpp"
#include "rsa_priv_key.hpp"

namespace basics {

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
