cmake_minimum_required(VERSION 3.17)
project(bigint)

set(CMAKE_CXX_STANDARD 20)

include_directories( ./src )

add_executable(bigint main.cpp src/big_int.cpp)