project( runtest )

option( INSTALL_TEST "install test" OFF )

find_package(
  Boost REQUIRED COMPONENTS
  unit_test_framework prg_exec_monitor
)

include_directories(
    .
    ${CMAKE_SOURCE_DIR}/lib/include
    ${Boost_INCLUDE_DIR}
)

add_executable(
  ${PROJECT_NAME}
  math_extra_test.cpp
)

remove_definitions( -Werror -Weffc++ )

target_link_libraries(
  ${PROJECT_NAME}
  ${Boost_LIBRARIES}
  math_extra
)

install( TARGETS ${PROJECT_NAME} DESTINATION . OPTIONAL )

if( INSTALL_TEST )
    install( DIRECTORY output DESTINATION _ref )
    install( DIRECTORY input DESTINATION _ref )
endif()
