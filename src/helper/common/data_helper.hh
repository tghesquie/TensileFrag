#ifndef DATA_HELPER_HH
#define DATA_HELPER_HH

#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <iostream>


class DataHelper {
public:
    explicit DataHelper(const std::string& basePath) : base_path(base_path) {}

    void saveCS(const std::vector<double>& sigma_c, const std::string& material_file, const std::string& mesh_file);
    std::vector<double> loadCS(const std::string& material_file, const std::string& mesh_file);

private:
    std::string base_path;

    std::string getCSPath(const std::string& material_file, const std::string& mesh_file) const;
};

#endif // DATA_HELPER_HH