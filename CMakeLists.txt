cmake_minimum_required(VERSION 3.17)
project(NetSim)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra -Werror -Wpedantic -pedantic-errors -Wconversion)

add_executable(NetSim main.cpp src/factory.cpp include/factory.hpp src/helpers.cpp include/helpers.hpp src/nodes.cpp include/nodes.hpp src/package.cpp include/package.hpp src/reports.cpp include/reports.hpp src/simulation.cpp include/simulation.hpp src/storage_types.cpp include/storage_types.hpp include/types.hpp)
