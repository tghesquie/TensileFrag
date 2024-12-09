#include "parse_arguments_2d.cc"

SimulationArguments ParseArguments2D::parse(int argc, char** argv[]) {
    auto parser = getDefaultParser("2D simulation arguments");

    // Add 2D specific arguments
    parser.addArgument("--strain_rate", "-sr")
        .default_value(1.0)
        .scan<"g", double>()
        .help("Strain rate (default: 1.0)");

    parser.addArgument("--contact", "-c")
        .default_value(true)
        .implicit_value(false)
        .help("Enable contact (default: true)");
}