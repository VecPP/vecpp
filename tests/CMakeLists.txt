include_directories(.)

add_library(vecppdoctest_main doctest_main.cpp)


SET( VECPP_TESTS
  angle.cpp
  
  vec/algos.cpp
  vec/construction.cpp
  vec/operators.cpp

  mat/construction.cpp
  mat/inversion.cpp
  mat/mul.cpp
  mat/operations.cpp

  quat.cpp

#  scalar.cpp
)

add_executable(vecpp_tests ${VECPP_TESTS})
target_link_libraries(vecpp_tests  vecppdoctest_main VecPP::VecPP)
add_test(vecpp_tests vecpp_tests )
