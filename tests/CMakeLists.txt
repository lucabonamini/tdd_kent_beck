cmake_minimum_required(VERSION 3.15)

project(tests)

find_package(GTest REQUIRED)

if (NOT ${GTEST_FOUND})
  include(FetchContent)
  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
  )

  FetchContent_MakeAvailable(googletest)
endif()


enable_testing()

add_executable(test_example test_example.cpp)
target_link_libraries(test_example
  PRIVATE
    GTest::gtest_main
)
target_compile_features(test_example PUBLIC cxx_std_17)

add_test(NAME test_example COMMAND test_example)
