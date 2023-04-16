cmake_minimum_required(VERSION 3.24)
project(memoizor)

set(CMAKE_CXX_STANDARD 20)

add_library(memoizor INTERFACE)
target_include_directories(memoizor INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# TESTS
enable_testing()
find_package(Catch2 3 REQUIRED)
add_executable(test_memoizor test/test_memoizor.cpp)
target_link_libraries(test_memoizor PRIVATE memoizor Catch2::Catch2)
add_test(NAME test_memoizor COMMAND test_memoizor)