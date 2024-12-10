#include "solid_mechanics_model_cohesive.hh"
#include "parse_arguments_2d.hh"
#include <iostream>


using namespace akantu;


int main(int argc, char** argv) {
    // Parse arguments
    ParseArguments2D parser;
    auto args = parser.parse(argc, argv);

    // Initialize material, mesh and model
    const Int dim = 2;
    initialize(args.material_file, argc, argv);

    Mesh mesh(dim);
    mesh.read(args.mesh_file);

    SolidMechanicsModelCohesive model(mesh);
    model.initFull(_analysis_method = _explicit_lumped_mass, _is_extrinsic = true);

    
    return 0;
};