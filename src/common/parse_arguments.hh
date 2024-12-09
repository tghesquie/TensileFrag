#ifndef PARSE_ARGUMENTS_HPP
#define PARSE_ARGUMENTS_HPP

#include "argparse.hh"
#include <string>

struct SimulationArguments {
    std::string material_file;
    std::string mesh_file;
    double safety_factor;
    double strain_rate;
    bool damp_velocities;
}

class ParseArguments {
public:
    virtual ~ParseArguments() = default;

    virtual SimulationArguments parse(int argc, char** argv) = 0;

protected:
    // Helper function
    argparse::ArgumentParser getDefaultParser(const std::string& description) const {
        argparse::ArgumentParser parser(description);

        // Add mandatory arguments
        parser.addArgument("--material_file", "-mat")
            .required()
            .help("Name of the material file (mandatory)");

        parser.addArgument("--mesh_file", "-msh")
            .required()
            .help("Name of the mesh file (mandatory)");

        // Add optional arguments
        parser.addArgument("--safety_factor", "-sf")
            .default_value(0.2)
            .scan<"g", double>()

};