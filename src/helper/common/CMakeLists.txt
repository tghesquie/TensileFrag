# Add common library
add_library(common 
    data_helper.cc
)

target_include_directories(common PUBLIC ${CMAKE_SOURCE_DIR})