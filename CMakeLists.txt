cmake_minimum_required (VERSION 2.8)

project( RSA )

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/tool")

add_definitions( -Wall -Wextra -Werror -Weffc++ -std=c++11 )
#add_definitions( -Wall -Wextra -Weffc++ -std=c++11 )

add_subdirectory( lib )
add_subdirectory( main )
add_subdirectory( test )

