cmake_minimum_required(VERSION 3.12)
project(stupid_prak_of_stupid_prak)

find_package(Threads REQUIRED)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_EXE main.cpp)

# google test framework
add_subdirectory(lib/googletest)

include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

# end google test framework

include_directories(mystr)

add_executable(stupid_prak_of_stupid_prak main.cpp)

add_executable(RunMatrixTest ./test/string_test.cpp)

add_subdirectory(mystr)

target_link_libraries(stupid_prak_of_stupid_prak mystr_lib)

target_link_libraries(RunMatrixTest gtest gtest_main Threads::Threads mystr_lib)

#target_link_libraries(stupid_prak_of_stupid_prak gtest gtest_main)
