include_directories(.)

add_library(catch_main catch_main.cpp)

SET( TEST_LIST
  angle
  documentation

  mat/constexpr
  mat/construction

  vec/algos
  vec/construction
  vec/operators

  quat
)

foreach(TEST_PATH ${TEST_LIST})
  STRING(REPLACE "/" "_" TGT_NAME ${TEST_PATH})
  add_executable("${TGT_NAME}" ${TEST_PATH}.cpp)
  target_link_libraries("${TGT_NAME}" catch_main)
  add_test("${TGT_NAME}" "${TGT_NAME}")
endforeach()

if(VECPP_BUILD_SINGLE_HEADER)
  add_executable(test_single_header single_header.cpp)
  target_link_libraries(test_single_header catch_main)
  add_test(test_single_header test_single_header)
endif()