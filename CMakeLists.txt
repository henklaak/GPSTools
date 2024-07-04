cmake_minimum_required(VERSION 3.27)

project(GPSTools
        VERSION 2024.07.03.0
        DESCRIPTION "GPSTools"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CXX_STANDARD_REQUIRED ON)

#

include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0)
FetchContent_MakeAvailable(googletest)

#

add_subdirectory(src)
add_subdirectory(tst)
