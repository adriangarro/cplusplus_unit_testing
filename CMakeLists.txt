cmake_minimum_required(VERSION 3.14)
project(testing_test)

set(CMAKE_CXX_STANDARD 23)

set(SOURCE_FILES main.cpp)
add_executable(Example_run ${SOURCE_FILES})

include_directories(Example_lib)
add_subdirectory(Example_lib)

target_link_libraries(Example_run Example_lib)

add_subdirectory(Google_tests)
