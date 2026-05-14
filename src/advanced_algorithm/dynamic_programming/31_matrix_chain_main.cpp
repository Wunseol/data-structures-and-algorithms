#include "31_matrix_chain.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<int> dims = {10, 30, 5, 60};
    std::cout << "Matrix Chain {10,30,5,60}: " << matrixChainOrder(dims) << "\n";
    dims = {40, 20, 30, 10, 30};
    std::cout << "Matrix Chain {40,20,30,10,30}: " << matrixChainOrder(dims) << "\n";
    return 0;
}
