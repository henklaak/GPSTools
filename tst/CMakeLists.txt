include(GoogleTest)

add_executable(test_GPSTools)

target_sources(test_GPSTools
    PRIVATE
    test_gps_tools.cpp
)

target_link_libraries(test_GPSTools
    PRIVATE
    GPSTools
    gtest_main
)

add_test(
    NAME test_GPSTools
    COMMAND test_GPSTools
)
