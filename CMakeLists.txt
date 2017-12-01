cmake_minimum_required(VERSION 3.8)
project(geo_surveying)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp src/point.cpp src/point.hpp src/angle.cpp src/angle.hpp src/horizontal_point.cpp src/horizontal_point.hpp src/traversing.cpp src/traversing.hpp src/traversing_solution.cpp src/traversing_solution.hpp src/sight_height.cpp src/sight_height.hpp src/three_wire_levelling.cpp src/three_wire_levelling.hpp src/three_wire_levelling_solution.cpp src/three_wire_levelling_solution.hpp src/sight_point.cpp src/sight_point.hpp src/printer.cpp src/printer.hpp)
add_executable(geo_surveying ${SOURCE_FILES})
