cmake_minimum_required(VERSION 3.9)

project(VecPP 
  VERSION 0.1
  DESCRIPTION "C++ vector math"
  LANGUAGES CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

option(VECPP_BUILD_SINGLE_HEADER "Build the vecpp_single.h header" OFF)
option(VECPP_BUILD_DOCS "Build documentation" OFF)
option(VECPP_BUILD_TESTS "Build tests" OFF)
option(VECPP_BUILD_FAILING_TESTS "Build failing tests" OFF)
option(VECPP_BUILD_PACKAGE "Build Release Package" OFF)

SET(VECPP_HEADERS
  include/vecpp/angle/angle.h
  include/vecpp/angle/operations.h
  include/vecpp/mat/mat.h
  include/vecpp/mat/operations.h
  include/vecpp/quat/quat.h
  include/vecpp/scalar/constants.h
  include/vecpp/scalar/operations.h
  include/vecpp/vec/operations.h
  include/vecpp/vec/operations_per_member.h
  include/vecpp/vec/vec.h
  include/vecpp/config.h
  include/vecpp/flags.h

  include/vecpp/vecpp.h
)

if(VECPP_BUILD_DOCS)
  add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/docs/404.html
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS mkdocs.yml
    COMMAND mkdocs build --verbose --clean --strict -f ${CMAKE_CURRENT_SOURCE_DIR}/mkdocs.yml -d ${CMAKE_CURRENT_BINARY_DIR}/docs
  )

  add_custom_target(generate_doc ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/docs/404.html)
  set_target_properties(generate_doc PROPERTIES FOLDER "prepare_for_deploy")
endif()

if(VECPP_BUILD_SINGLE_HEADER)
  file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/vecpp/)

  set(SINGLE_INCLUDE_FILE ${CMAKE_CURRENT_BINARY_DIR}/vecpp/vecpp_single.h)
  set(NOTICE_FILE ${CMAKE_CURRENT_SOURCE_DIR}/misc/notice.txt)

  add_custom_command(
    OUTPUT ${SINGLE_INCLUDE_FILE}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
    DEPENDS ${VECPP_HEADERS}
    COMMAND python ${CMAKE_CURRENT_SOURCE_DIR}/tools/header_compiler/header_compiler.py 
      --output=${SINGLE_INCLUDE_FILE}
      --notice=${NOTICE_FILE}
      --header_guard="VECPP_SINGLE_INCLUDE_H_"
      --input=${CMAKE_CURRENT_SOURCE_DIR}/include/vecpp/vecpp.h)

  add_custom_target(generate_single_include ALL DEPENDS ${SINGLE_INCLUDE_FILE})
  set_target_properties(generate_single_include PROPERTIES FOLDER "prepare_for_deploy")
endif()


add_library(VecPP INTERFACE)
add_library(VecPP::VecPP ALIAS VecPP)

target_include_directories(VecPP INTERFACE 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

target_compile_features(VecPP INTERFACE cxx_std_17)

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
      ${SINGLE_INCLUDE_FILE}
      ${CMAKE_CURRENT_BINARY_DIR}/docs/404.html
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/include ${CMAKE_CURRENT_BINARY_DIR}/include
    COMMAND ${CMAKE_COMMAND} -E copy ${SINGLE_INCLUDE_FILE} ${CMAKE_CURRENT_BINARY_DIR}/include
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
