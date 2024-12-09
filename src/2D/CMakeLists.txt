# Add the include directory for common
include_directories(${CMAKE_SOURCE_DIR}/src/common)

add_akantu_simulation(main2D main.cc parse_arguments_2d.cc)

target_include_directories(main2D PRIVATE ${CMAKE_SOURCE_DIR}/libs/argparse/include)