cmake_minimum_required(VERSION 3.12.0)
project(tensile_frag)

find_package(Akantu REQUIRED)
find_package(Boost REQUIRED COMPONENTS graph)

add_subdirectory(src)

