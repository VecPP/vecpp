cmake_minimum_required(VERSION 3.9)

project(VecPP 
  VERSION 0.2
  DESCRIPTION "C++ vector math"
  LANGUAGES CXX)

option(VECPP_BUILD_DOCS "Build documentation" OFF)
option(VECPP_BUILD_TESTS "Build tests" ON)
option(VECPP_BUILD_FAILING_TESTS "Build failing tests" OFF)
option(VECPP_BUILD_PACKAGE "Build Release Package" OFF)

SET(VECPP_HEADERS
  include/vecpp/angle/angle.h
  include/vecpp/angle/operations.h
  include/vecpp/mat/mat.h
  include/vecpp/mat/mul.h
  include/vecpp/mat/operations.h
  include/vecpp/quat/quat.h
  include/vecpp/scalar/constants.h
  include/vecpp/scalar/operations.h
  include/vecpp/vec/operations.h
  include/vecpp/vec/operations_per_member.h
  include/vecpp/vec/vec.h
  include/vecpp/config.h
  include/vecpp/traits.h

  include/vecpp/vecpp.h
)

add_library(VecPP INTERFACE)
add_library(VecPP::VecPP ALIAS VecPP)

target_compile_features(VecPP INTERFACE cxx_std_20)

target_include_directories(VecPP INTERFACE 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS VecPP EXPORT VecPPTargets)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/vecpp DESTINATION include)

install(EXPORT VecPPTargets
        FILE VecPPConfig.cmake
        NAMESPACE VecPP::
        DESTINATION lib/cmake/VecPP
         )

if(VECPP_BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()

if(VECPP_BUILD_PACKAGE)
  file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/vecpp_pkg/)

  add_custom_command( 
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/vecpp.zip
    DEPENDS
      ${CMAKE_CURRENT_BINARY_DIR}/docs/404.html
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/include ${CMAKE_CURRENT_BINARY_DIR}/include
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/README.md ${CMAKE_CURRENT_BINARY_DIR}/README.md
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/LICENSE ${CMAKE_CURRENT_BINARY_DIR}/LICENSE
    COMMAND ${CMAKE_COMMAND} -E tar "cf" "vecpp.zip" --format=zip 
      "${CMAKE_CURRENT_BINARY_DIR}/README.md"
      "${CMAKE_CURRENT_BINARY_DIR}/LICENSE"
      "${CMAKE_CURRENT_BINARY_DIR}/include"
      "${CMAKE_CURRENT_BINARY_DIR}/docs"
  )

  add_custom_target(generate_zip ALL
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/vecpp.zip )
    set_target_properties(generate_zip PROPERTIES FOLDER "prepare_for_deploy")
endif()
