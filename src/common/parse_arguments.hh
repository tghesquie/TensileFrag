#ifndef PARSE_ARGUMENTS_HPP
#define PARSE_ARGUMENTS_HPP

#include "argparse/argparse.hpp"
#include <string>
#include <memory>

struct SimulationArguments {
    std::string material_file;
    std::string mesh_file;
    double safety_factor;
    double strain_rate;
    bool damp_velocities;
    bool contact;
};

class ParseArguments {
public:
    virtual ~ParseArguments() = default;

    virtual SimulationArguments parse(int argc, char** argv) = 0;

protected:
    // Helper function
    std::unique_ptr<argparse::ArgumentParser> getDefaultParser(const std::string& description) const {
        auto parser = std::make_unique<argparse::ArgumentParser>(description);

        // Add mandatory arguments
        parser->add_argument("--material_file", "-mat")
            .required()
            .help("Name of the material file (mandatory)");

        parser->add_argument("--mesh_file", "-msh")
            .required()
            .help("Name of the mesh file (mandatory)");

        // Add optional arguments
        parser->add_argument("--safety_factor", "-sf")
            .default_value(0.2)
            .scan<'g', double>();

        parser->add_argument("--damp_velocities", "-dv")
            .default_value(false)
            .implicit_value(true)
            .help("Damp velocities (default: false)");

        return parser;

    }
};


#endif // PARSE_ARGUMENTS_HPP