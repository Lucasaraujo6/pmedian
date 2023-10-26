#include "Instance.hpp"
#include <iostream>
#include <fstream>
#include <limits>


Instance::Instance(const std::string& directory, bool isFromOrLib) {
    std::ifstream entryFile(directory);

    if (!entryFile.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << directory << std::endl;
        // Trate o erro apropriadamente
        return;
    }

    entryFile >> vertices >> edges >> medians;

    costMatrix.resize(vertices, std::vector<int>(vertices, std::numeric_limits<int>::max()));
    prev.resize(vertices, std::vector<int>(vertices, -1));

    // Lê e armazena as linhas subsequentes em uma matriz (vetor de strings)
    int vertice, edge, cost;
    while (entryFile >> vertice >> edge >> cost) {
        costMatrix [vertice - 1][edge - 1] = cost;
        prev[vertice - 1][edge - 1] = vertice - 1;
        if(isFromOrLib){
            costMatrix [edge - 1][vertice - 1] = cost;
            prev[edge - 1][vertice - 1] = edge - 1;
        }
    }


    floydWarshall(isFromOrLib);
    // Feche o arquivo após a leitura
    entryFile.close();
}

void Instance::floydWarshall(bool isFromOrLib ) {
    int V = vertices;
    if(isFromOrLib){
        for (int i = 0; i < V; i++) {
            costMatrix[i][i] = 0;
            prev[i][i] = i;
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (costMatrix[i][k] != std::numeric_limits<int>::max() &&
                    costMatrix[k][j] != std::numeric_limits<int>::max() &&
                    costMatrix[i][k] + costMatrix[k][j] < costMatrix[i][j]) {
                    costMatrix[i][j] = costMatrix[i][k] + costMatrix[k][j];
                    prev[i][j] = prev[k][j]; // Atualiza o predecessor
                }
            }
        }
    }
}
