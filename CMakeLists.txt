cmake_minimum_required(VERSION 3.10)  # Minimum required CMake version

project(Network-Monitor)  # Name of the project
set(CMAKE_BUILD_TYPE Debug)

include_directories(${CURSES_INCLUDE_DIR})
link_libraries(${CURSES_LIBRARIES})

# Add include directory to search path for header files
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add source files
set(SOURCES
    src/main.cpp
    src/user-menu.cpp
)

# Add an executable target to build from the source files
add_executable(network-monitor ${SOURCES})
