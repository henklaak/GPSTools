add_library(GPSTools SHARED)

target_sources(GPSTools
    PRIVATE
    gps_tools.cpp
    ${PROJECT_SOURCE_DIR}/include/gps_tools/gps_tools.h
)

target_include_directories(GPSTools
    PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)

