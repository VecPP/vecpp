include_directories(.)

add_library(catch_main catch_main.cpp)
set_target_properties(catch_main PROPERTIES FOLDER "tests")

SET( VECPP_TESTS
  angle.cpp
  documentation.cpp

  vec/algos.cpp
  vec/construction.cpp
  vec/operators.cpp

  mat/construction.cpp
  mat/mul.cpp
  mat/operations.cpp

  quat.cpp

  scalar.cpp
)

MACRO(config_test_target TGT)

target_link_libraries(${TGT} catch_main VecPP::VecPP)
set_target_properties(${TGT} PROPERTIES FOLDER "tests")
add_test(${TGT} ${TGT})

if(MSVC)
  target_compile_options(${TGT} PRIVATE /W4 /WX)
else(MSVC)
  target_compile_options(${TGT} PRIVATE -Wall -Wextra -pedantic -Werror)
endif(MSVC)
endmacro()

add_executable(all_tests ${VECPP_TESTS})
config_test_target(all_tests)

if(VECPP_BUILD_SINGLE_HEADER)
  add_executable(all_tests_sh ${VECPP_TESTS})
  target_include_directories(all_tests_sh PRIVATE ${CMAKE_CURRENT})
  target_compile_definitions(all_tests_sh
    PRIVATE VECPP_TEST_SINGLE_HEADER
  )
  add_dependencies(all_tests_sh generate_single_include)
  config_test_target(all_tests_sh)
endif()

if(VECPP_BUILD_FAILING_TESTS)
  add_executable( failing catch_main.cpp failing.cpp)
  config_test_target(failing)
endif()