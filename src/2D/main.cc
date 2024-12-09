#include "solid_mechanics_model_cohesive.hh"
#include "parse_arguments_2d.hh"
#include <iostream>

int main(int argc, char** argv) {
    ParseArguments2D parser;
    auto args = parser.parse(argc, argv);

    std::cout << "Material file: " << args.material_file << std::endl;
    std::cout << "Mesh file: " << args.mesh_file << std::endl;
    std::cout << "Safety factor: " << args.safety_factor << std::endl;
    std::cout << "Strain rate: " << args.strain_rate << std::endl;
    std::cout << "Damp velocities: " << args.damp_velocities << std::endl;
    std::cout << "Contact: " << args.contact << std::endl;

    return 0;
};