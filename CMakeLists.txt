cmake_minimum_required(VERSION 3.12.0)
project(tensile_frag)

find_package(Akantu REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/libs/argparse/include)

add_subdirectory(src)