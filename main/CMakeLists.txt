find_package(GMP REQUIRED)
find_package(Boost REQUIRED)

project( RSA )

include_directories( ${Boost_INCLUDE_DIRS} )
include_directories( ${GMP_INCLUDE_DIR} )
include_directories( ${CMAKE_SOURCE_DIR}/lib/include )

add_executable( ${PROJECT_NAME} rsa.cpp )

target_link_libraries( 
  ${PROJECT_NAME}
  ${Boost_LIBRARIES} 
  ${GMP_LIBRARIES} 
  ${GMPXX_LIBRARIES}
  rsa
)
