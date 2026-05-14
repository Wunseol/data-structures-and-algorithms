#include "28_kruskal.h"
#include <iostream>

int main() {
    int n = 4;
    std::vector<std::tuple<int,int,int>> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    int mstWeight = kruskal(n, edges);
    std::cout << "最小生成树总权重: " << mstWeight << std::endl;

    return 0;
}
