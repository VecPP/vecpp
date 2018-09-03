include_directories(.)

add_library(catch_main catch_main.cpp)
set_target_properties(catch_main PROPERTIES FOLDER "tests")

SET( VECPP_TESTS
  angle.cpp
  documentation.cpp

  vec/algos.cpp
  vec/construction.cpp
  vec/operators.cpp

  quat.cpp

  scalar.cpp
)

add_executable(all_tests ${VECPP_TESTS})
target_link_libraries(all_tests catch_main VecPP::VecPP)
set_target_properties(all_tests PROPERTIES FOLDER "tests")
add_test(all_tests all_tests)

if(VECPP_BUILD_SINGLE_HEADER)
  add_executable(all_tests_sh ${VECPP_TESTS})
  target_include_directories(all_tests_sh PRIVATE ${CMAKE_CURRENT})
  target_compile_definitions(all_tests_sh
    PRIVATE VECPP_TEST_SINGLE_HEADER
  )
  add_dependencies(all_tests_sh generate_single_include)
  target_link_libraries(all_tests_sh catch_main VecPP::VecPP)
  set_target_properties(all_tests_sh PROPERTIES FOLDER "tests")
  add_test(all_tests_sh all_tests_sh)
endif()

if(VECPP_BUILD_FAILING_TESTS)
  add_executable( failing catch_main.cpp failing.cpp)
  add_test(failing failing)
  set_target_properties(failing PROPERTIES FOLDER "tests")
endif()
