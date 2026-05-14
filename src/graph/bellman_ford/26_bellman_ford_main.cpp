#include "26_bellman_ford.h"
#include <iostream>

int main() {
    int n = 5;
    std::vector<std::tuple<int,int,int>> edges = {
        {0, 1, 6},
        {0, 2, 7},
        {1, 2, 8},
        {1, 3, 5},
        {1, 4, -4},
        {2, 3, -3},
        {2, 4, 9},
        {3, 1, -2},
        {4, 0, 2},
        {4, 3, 7}
    };

    auto dist = bellmanFord(n, edges, 0);

    if (dist.empty()) {
        std::cout << "图中存在负权环" << std::endl;
    } else {
        std::cout << "从顶点 0 出发的最短距离:" << std::endl;
        for (int i = 0; i < n; ++i) {
            if (dist[i] == INT_MAX) {
                std::cout << "  顶点 " << i << ": 不可达" << std::endl;
            } else {
                std::cout << "  顶点 " << i << ": " << dist[i] << std::endl;
            }
        }
    }

    std::vector<std::tuple<int,int,int>> negEdges = {
        {0, 1, 1},
        {1, 2, -1},
        {2, 0, -1}
    };
    auto negDist = bellmanFord(3, negEdges, 0);
    if (negDist.empty()) {
        std::cout << "负权环检测: 图中存在负权环" << std::endl;
    }

    return 0;
}
