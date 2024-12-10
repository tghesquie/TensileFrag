#include "data_helper.hh"


/*---------------------------------------------------------------------------*/

std::string DataHelper::getCSPath(const std::string& material_file, const std::string& mesh_file) const {

    std::filesystem::path path = std::filesystem::path(base_path) / "input/cohesive_strength_distrib";
    std::string file_name = std::filesystem::path(material_file).stem().string() + "|" + std::filesystem::path(mesh_file).stem().string() + ".csv";

    return (path / file_name).string();
}

/*---------------------------------------------------------------------------*/

void DataHelper::saveCS(const std::vector<double>& sigma_c, const std::string& material_file, const std::string& mesh_file) {
    std::string path = getCSPath(material_file, mesh_file);
    std::ofstream out_file(path);
    if (!out_file.is_open()) {
        throw std::runtime_error("Could not open file " + path);
    }

    for (const auto& sigma : sigma_c) {
        out_file << sigma << "\n";
    }
    out_file.close();
    std::cout << "Cohesive strength distribution saved to " << path << std::endl;
}

/*---------------------------------------------------------------------------*/

void DataHelper::loadCS(const std::string& material_file, const std::string& mesh_file) {
    std::string path = getCSPath(material_file, mesh_file);
    std::ifstream in_file(path);
    if (!in_file.is_open()) {
        throw std::runtime_error("Could not open file " + path);
    }

    std::vector<double> sigma_c;
    double value;
    while (in_file >> value) {
        sigma_c.push_back(value);
    }
    in_file.close();

    std::cout << "Cohesive strength distribution loaded from " << path << std::endl;
    return sigma_c;
}

