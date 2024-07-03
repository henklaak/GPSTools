cmake_minimum_required(VERSION 3.27)

project(GPSTools
        VERSION 2024.07.03.0
        DESCRIPTION "GPSTools"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CXX_STANDARD_REQUIRED ON)

add_library(GPSTools SHARED)
target_sources(GPSTools
    PRIVATE
    src/gps_tools.cpp
    include/gps_tools/gps_tools.h)

target_include_directories(GPSTools
  PUBLIC
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)

#
find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(test_GPSTools)
target_sources(test_GPSTools
    PRIVATE
    src/gps_tools.cpp
    include/gps_tools/gps_tools.h
    tst/test_gps_tools.cpp)

target_include_directories(test_GPSTools
  PRIVATE
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)

target_link_libraries(
  test_GPSTools
  GTest::gtest_main
)


add_test(
    NAME test_GPSTools
    COMMAND test_GPSTools)
