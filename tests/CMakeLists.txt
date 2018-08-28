include_directories(.)

add_library(catch_main catch_main.cpp)

SET( TEST_LIST
  mat/constexpr
  mat/construction

  vec/algos
  vec/constexpr
  vec/construction
  vec/operators

  transform
)

foreach(TEST_PATH ${TEST_LIST})
  STRING(REPLACE "/" "_" TGT_NAME ${TEST_PATH})
  add_executable("${TGT_NAME}" ${TEST_PATH}.cpp)
  target_link_libraries("${TGT_NAME}" catch_main)
  add_test("${TGT_NAME}" "${TGT_NAME}")
endforeach()