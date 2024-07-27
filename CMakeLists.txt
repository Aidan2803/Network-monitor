cmake_minimum_required(VERSION 3.10)

project(Network-Monitor) 
set(CMAKE_BUILD_TYPE Debug)

find_package(PkgConfig REQUIRED)
pkg_check_modules(PCAP REQUIRED libpcap)

include_directories(${PCAP_INCLUDE_DIRS})

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCES
    src/main.cpp
    src/user-menu.cpp
    src/state.cpp
    src/user-menu-handler.cpp
    src/network-interface-handler.cpp
)

# Add an executable target to build from the source files
add_executable(network-monitor ${SOURCES})

target_link_libraries(network-monitor ${PCAP_LIBRARIES})
