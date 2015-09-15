cmake_minimum_required (VERSION 2.8)

project(RSA)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/tool")

find_package(GMP REQUIRED)
find_package(Boost REQUIRED)

include_directories( ${Boost_INCLUDE_DIRS} )
include_directories( ${GMP_INCLUDE_DIR} )

add_definitions( -Wall -Wextra -Werror -Weffc++ )

add_executable( rsa rsa.cpp )

target_link_libraries( 
  rsa 
  ${Boost_LIBRARIES} 
  ${GMP_LIBRARIES} 
  ${GMPXX_LIBRARIES}
)

