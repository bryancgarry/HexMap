cmake_minimum_required(VERSION 3.10)
project(MySFMLProject)

set(CMAKE_CXX_STANDARD 17)

# Tell CMake where SFML is
set(SFML_DIR "${CMAKE_SOURCE_DIR}/external/SFML")

include_directories(${SFML_DIR}/include)
link_directories(${SFML_DIR}/lib)

add_executable(MySFMLProject src/main.cpp)

target_link_libraries(MySFMLProject
    sfml-graphics
    sfml-window
    sfml-system
)