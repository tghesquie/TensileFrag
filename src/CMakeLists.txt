add_subdirectory(helper)

# Add 1D simulation
add_akantu_simulation(main1D main1D.cc)
target_link_libraries(main1D PRIVATE common_helpers helper_1D)
target_include_directories(main1D PRIVATE ${CMAKE_SOURCE_DIR}/libs/argparse/include)

# Add 2D simulation
add_akantu_simulation(main2D main2D.cc)
target_link_libraries(main2D PRIVATE common_helpers helper_2D)
target_include_directories(main2D PRIVATE ${CMAKE_SOURCE_DIR}/libs/argparse/include)

# Add 3D simulation
add_akantu_simulation(main3D main3D.cc)
target_link_libraries(main3D PRIVATE common_helpers helper_3D)
target_include_directories(main3D PRIVATE ${CMAKE_SOURCE_DIR}/libs/argparse/include)