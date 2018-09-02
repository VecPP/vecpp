include_directories(.)

add_library(catch_main catch_main.cpp)
set_target_properties(catch_main PROPERTIES FOLDER "tests")

SET( TEST_LIST
  angle
  documentation

  vec/algos
  vec/construction
  vec/operators

  quat

  scalar
)

foreach(TEST_PATH ${TEST_LIST})
  STRING(REPLACE "/" "_" TGT_NAME ${TEST_PATH})
  add_executable("${TGT_NAME}" ${TEST_PATH}.cpp)
  set_target_properties("${TGT_NAME}" PROPERTIES FOLDER "tests")
  target_link_libraries("${TGT_NAME}" catch_main)
  add_test("${TGT_NAME}" "${TGT_NAME}")
endforeach()

if(VECPP_BUILD_SINGLE_HEADER)
  foreach(TEST_PATH ${TEST_LIST})
    STRING(REPLACE "/" "_" TGT_NAME ${TEST_PATH})
    add_executable("${TGT_NAME}_sh" ${TEST_PATH}.cpp)
    target_compile_definitions(${TGT_NAME}_sh
      PRIVATE VECPP_TEST_SINGLE_HEADER
    )

    set_target_properties("${TGT_NAME}_sh" PROPERTIES FOLDER "tests_sh")
    add_dependencies("${TGT_NAME}_sh" generate_single_include)
    target_link_libraries("${TGT_NAME}_sh" catch_main)
    add_test("${TGT_NAME}_sh" "${TGT_NAME}_sh")
  endforeach()
endif()

if(VECPP_BUILD_FAILING_TESTS)
  add_executable(failing_tests failing.cpp)
  target_link_libraries(failing_tests catch_main)
  add_test(failing_tests failing)
endif()
