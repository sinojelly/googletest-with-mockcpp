cmake_minimum_required(VERSION 2.6...3.19)
project(basic_test)

################################
# GTest
################################
set(GOOGLETEST_VERSION 1.10.0)
set(gtest_SOURCE_DIR ${PROJECT_SOURCE_DIR}/3rdparty/googletest)
ADD_SUBDIRECTORY (${gtest_SOURCE_DIR})
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

################################
# Mockcpp
################################
INCLUDE_DIRECTORIES(BEFORE ${PROJECT_SOURCE_DIR}/3rdparty/mockcpp/include)
link_directories(${PROJECT_SOURCE_DIR}/3rdparty/mockcpp/lib)

################################
# Unit Tests
################################
# Add test cpp file
add_executable( runUnitTests testgtest.cpp )
# Link test executable against gtest & gtest_main
target_link_libraries(runUnitTests gtest gtest_main mockcpp)
add_test( runUnitTests runUnitTests )
