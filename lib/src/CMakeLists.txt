find_package(GMP REQUIRED)
find_package(Boost REQUIRED)

include_directories( ${Boost_INCLUDE_DIRS} )
include_directories( ${GMP_INCLUDE_DIR} )
include_directories( ${CMAKE_SOURCE_DIR}/lib/include )

add_library( rsalib cipher.cpp )