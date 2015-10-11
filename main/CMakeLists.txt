project( RSA )

include_directories( ${CMAKE_SOURCE_DIR}/lib/include )
add_executable( ${PROJECT_NAME} rsa.cpp )
target_link_libraries( ${PROJECT_NAME} rsa )
