#include "Instance.hpp"
#include <iostream>
#include <fstream>
#include <limits>


Instance::Instance(const std::string& directory) {
    std::ifstream entryFile(directory);

    if (!entryFile.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << directory << std::endl;
        // Trate o erro apropriadamente
        return;
    }

    entryFile >> vertices >> edges >> medians;

    costMatrix.resize(vertices, std::vector<int>(vertices, std::numeric_limits<int>::max()));
    // Lê e armazena as linhas subsequentes em uma matriz (vetor de strings)
    int vertice, edge, cost;
    while (entryFile >> vertice >> edge >> cost) {
        costMatrix [vertice - 1][edge - 1] = cost;
        costMatrix [vertice - 1][edge - 1] = cost;
    }

    // Feche o arquivo após a leitura
    entryFile.close();
}


