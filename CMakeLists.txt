cmake_minimum_required(VERSION 3.17)
project(bigint)

set(CMAKE_CXX_STANDARD 20)

include_directories( ./src )

file(GLOB TESTS "./tests/*.txt")
file(COPY ${TESTS} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/tests/)

add_executable(bigint main.cpp src/big_int.cpp)
add_executable(run_tests ./tests/run_tests.cpp src/big_int.cpp)