#pragma once  // Isso evita inclusões múltiplas do cabeçalho

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Instance {
public:
    explicit Instance(const std::string& directory);
    int vertices;
    int medians;
    int edges;
    std::vector<std::vector<int>> costMatrix;
    // Outros métodos da classe podem ser adicionados conforme necessário

private:

};

