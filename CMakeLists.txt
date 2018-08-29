
cmake_minimum_required(VERSION 3.9)

project(vecpp)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(
  include
)

if(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra")
endif(MSVC)

#install headers
install(DIRECTORY include/vecpp DESTINATION include)

enable_testing()
add_subdirectory(tests)