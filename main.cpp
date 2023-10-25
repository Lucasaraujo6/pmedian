#include <iostream>
#include <filesystem>
#include "Instance.hpp"

namespace fs = std::filesystem;

int main() {
    // Diretório que você deseja listar os arquivos
    // std::string diretorio = "/home/prod/Documentos/Lucas/2 sem 2023/Heurísticas e Metaheurísticas/Trabalho em grupo/pmedian/instances/optimals";
    std::string origin = "orlib";

    std::string directory =
            std::string(std::filesystem::current_path().parent_path())
            +  "/pmedian/instances/"
            + origin;




    // Itera sobre os arquivos no diretório
    for (const auto &entry : fs::directory_iterator(directory)) {

        Instance test(entry.path());
        std::cout << entry.path() << "\n";
        std::cout << test.costMatrix[0][1];
        exit(0);

    }

    return 0;
}
