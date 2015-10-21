/** 
 * INSERT LICENCE INFORMATION HERE 
 */ 

/**
 * @author Corentin MARCIAU	<corentin@marciau.fr>
 */

/**
 * @file keys.cpp
 */

#include <boost/multiprecision/gmp.hpp>
#include <boost/multiprecision/integer.hpp>

#include "rsa/keys.hpp"
#include "rsa/pnrg.hpp"

#include "math_extra/math_extra.hpp"

basics::Keys::Keys()
    : p_(0), q_(0), n_(0), 
      phi_(0), e_(0), d_(0), 
      operational_(false)        
{
    generate();
}

basics::Rsa_pub_key basics::Keys::getPublicKey() const
{
    basics::Rsa_pub_key key(basics::rsa_length, basics::char_size, n_, e_);
    return key;
}

basics::Rsa_priv_key basics::Keys::getPrivateKey() const
{
    basics::Rsa_priv_key key(basics::rsa_length, basics::char_size, n_, d_);
    return key;
}

void basics::Keys::generate() 
{
    // Trouvons p et q deux grands entiers premiers
    basics::Pnrg pnrg(basics::rsa_length);
    p_ = pnrg.getPrime();
    q_ = pnrg.getPrime();
    
    if (p_ == 0 || q_ == 0) {
        std::cout << "Impossible de générer p et q premiers." << std::endl;
        return;
    }
    
    // Calculons n, le produit de p et q
    n_ = p_ * q_;
    
    // Calculons l'indicatrice d'Euler de n
    phi_ = (p_ - 1)* (q_ - 1);
    
    // Calculons e, premier avec phi(n) (il faudrait lire pas mal de
    // littérature pour faire un choix rationel ...)
    e_ = 65537;
    while (gcd(e_, phi_) != 1) {
        e_ += 2;
    }
    
    // On calcule d, inverse de e modulo phi(n)
    d_ = basics::inverse(e_, phi_);
    
    basics::int_type prod = (e_ * d_) % phi_;
    if ( prod != 1) {
        std::stringstream err;
        err << "Mauvais inverse d ! prod=" << prod << std::endl;
        throw std::runtime_error(err.str());
    }
    
    // Tout s'est bien passé !
    operational_ = true;
}

