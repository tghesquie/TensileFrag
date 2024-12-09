# Add the include directory for common
include_directories(${CMAKE_SOURCE_DIR}/src/common)

add_akantu_simulation(main3D main.cc)

target_include_directories(main3D PRIVATE ${CMAKE_SOURCE_DIR}/libs/argparse/include)