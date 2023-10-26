#pragma once  // Isso evita inclusões múltiplas do cabeçalho

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Instance {
public:
    Instance(const std::string& directory, bool isFromOrLib);
    int vertices;
    int medians;
    int edges;
    std::vector<std::vector<int>> costMatrix;
    std::vector<std::vector<int>> prev;

    // Outros métodos da classe podem ser adicionados conforme necessário

private:
    void floydWarshall(bool isFromOrLib);
};

