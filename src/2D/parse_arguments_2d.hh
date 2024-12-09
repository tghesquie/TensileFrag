#ifndef PARSE_ARGUMENTS_2D_HPP
#define PARSE_ARGUMENTS_2D_HPP

#include "common/parse_arguments.hh"

class ParseArguments2D : public ParseArguments {
public:
    SimulationArguments parse(int argc, char** argv) override;
};

#endif // PARSE_ARGUMENTS_2D_HPP