# Add common helper library
add_library(common_helpers
    common/data_helper.cc
)

target_include_directories(common_helpers PUBLIC ${CMAKE_SOURCE_DIR}/common)

# Add 1D helper library
add_library(helper_1D
    1D/placeholder.cc
)

target_include_directories(helper_1D PUBLIC
    ${CMAKE_SOURCE_DIR}/libs/argparse/include
    ${CMAKE_CURRENT_SOURCE_DIR}/1D
    ${CMAKE_CURRENT_SOURCE_DIR}/common
)

# Add 2D helper library
add_library(helper_2D
    2D/parse_arguments_2d.cc
)

target_include_directories(helper_2D PUBLIC
    ${CMAKE_SOURCE_DIR}/libs/argparse/include
    ${CMAKE_CURRENT_SOURCE_DIR}/2D
    ${CMAKE_CURRENT_SOURCE_DIR}/common
)

# Add 3D helper library
add_library(helper_3D
    3D/placeholder.cc
)

target_include_directories(helper_3D PUBLIC
    ${CMAKE_SOURCE_DIR}/libs/argparse/include
    ${CMAKE_CURRENT_SOURCE_DIR}/3D
    ${CMAKE_CURRENT_SOURCE_DIR}/common
)
