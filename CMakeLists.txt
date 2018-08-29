
cmake_minimum_required(VERSION 3.9)

project(vecpp)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

option(VECPP_BUILD_SINGLE_HEADER "Build the vecpp_single.h header" OFF)

include_directories(
  include
)

if(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra")
endif(MSVC)

if(VECPP_BUILD_SINGLE_HEADER)

  # List of vecpp headers
  FILE(GLOB_RECURSE
    VECPP_HEADERS_GLOBBED
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
  )

  SET(VECPP_HEADERS "")
  FOREACH(f ${VECPP_HEADERS_GLOBBED})
    IF(NOT ${f} MATCHES "vecpp_single.h")
      LIST(APPEND VECPP_HEADERS "${f}")
    ENDIF()
  ENDFOREACH(f)


  set(SINGLE_INCLUDE_FILE ${CMAKE_CURRENT_SOURCE_DIR}/include/vecpp/vecpp_single.h)
  set(NOTICE_FILE ${CMAKE_CURRENT_SOURCE_DIR}/misc/notice.txt)

  add_custom_command(
    OUTPUT ${SINGLE_INCLUDE_FILE}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include
    DEPENDS ${VECPP_HEADERS} 
    COMMAND python ${CMAKE_CURRENT_SOURCE_DIR}/tools/header_compiler/header_compiler.py 
      --output=${SINGLE_INCLUDE_FILE}
      --notice=${NOTICE_FILE}
      --header_guard="ABULAFIA_SINGLE_INCLUDE_H_"
      --input=${CMAKE_CURRENT_SOURCE_DIR}/include/vecpp/vecpp.h)

  add_custom_target(generate_single_include ALL DEPENDS ${SINGLE_INCLUDE_FILE})
endif()

#install headers
install(DIRECTORY include/vecpp DESTINATION include)

enable_testing()
add_subdirectory(tests)