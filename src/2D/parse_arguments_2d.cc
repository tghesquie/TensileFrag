#include "parse_arguments_2d.hh"
#include <filesystem>

SimulationArguments ParseArguments2D::parse(int argc, char** argv) {
    auto parser = getDefaultParser("Run 2D simulation");
    // Add 2D specific arguments
    parser->add_argument("--strain_rate", "-sr")
        .default_value(1.0)
        .scan<'g', double>()
        .help("Strain rate (default: 1.0)");
    parser->add_argument("--contact", "-c")
        .default_value(true)
        .implicit_value(false)
        .help("Enable contact (default: true)");

    parser->parse_args(argc, argv);

    SimulationArguments args;
    std::string material_file = parser->get<std::string>("--material_file");
    std::string mesh_file = parser->get<std::string>("--mesh_file");

    // Add base paths for 2D
    std::string base_material_path = "2D/material/";
    std::string base_mesh_path = "2D/mesh/";

    args.material_file = std::filesystem::path(base_material_path) / material_file;
    args.mesh_file = std::filesystem::path(base_mesh_path) / mesh_file;
    args.safety_factor = parser->get<double>("--safety_factor");
    args.strain_rate = parser->get<double>("--strain_rate");

    return args; // Ensure the return of a valid SimulationArguments object 
}