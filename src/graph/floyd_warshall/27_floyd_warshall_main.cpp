#include "27_floyd_warshall.h"
#include <iostream>
#include <climits>

int main() {
    int n = 4;
    const int INF = INT_MAX;
    std::vector<std::vector<int>> dist = {
        {0,   3,   INF, 5},
        {2,   0,   INF, 4},
        {INF, 1,   0,   INF},
        {INF, INF, 2,   0}
    };

    auto result = floydWarshall(n, dist);

    std::cout << "全源最短路径矩阵:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (result[i][j] == INF) {
                std::cout << "INF\t";
            } else {
                std::cout << result[i][j] << "\t";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
