cmake_minimum_required(VERSION 3.10)
project(HexMap)

set(CMAKE_CXX_STANDARD 17)

# Tell CMake where SFML is
set(SFML_DIR "${CMAKE_SOURCE_DIR}/external/SFML")

include_directories(${SFML_DIR}/include)

if(WIN32)
    link_directories(${SFML_DIR}/lib/Windows)
else()
    link_directories(${SFML_DIR}/lib/MacOS)
endif()

add_executable(HexMap 
    src/main.cpp
    src/HexMap.cpp
)

target_link_libraries(HexMap
    sfml-graphics
    sfml-window
    sfml-system
)