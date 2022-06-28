project(Google_tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

add_executable(Google_Tests_run ConverterTests.cpp AbsoluteDateTest.cpp AuthorizationTest.cpp)

target_link_libraries(Google_Tests_run Example_lib)

target_link_libraries(Google_Tests_run gtest gtest_main)
