find_package(GMP REQUIRED)
find_package(Boost REQUIRED)

include_directories( ${Boost_INCLUDE_DIRS} )
include_directories( ${GMP_INCLUDE_DIR} )
include_directories( ${CMAKE_SOURCE_DIR}/lib/include )

add_library( rsa 
  cipher.cpp 
  keys.cpp 
  pnrg.cpp 
  i2osp_os2ip.cpp 
  rsa_priv_key.cpp 
  rsa_pub_key.cpp 
  rsaep_rsadp.cpp )

add_library( math_extra math_extra.cpp )

target_link_libraries( rsa math_extra )
