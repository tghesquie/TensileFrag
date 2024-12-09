#include "parse_arguments_2d.hh"

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
    args.material_file = parser->get<std::string>("--material_file");
    args.mesh_file = parser->get<std::string>("--mesh_file");
    args.safety_factor = parser->get<double>("--safety_factor");
    args.contact = true; // Add a default value or retrieve from arguments
    return args; // Ensure the return of a valid SimulationArguments object 
}