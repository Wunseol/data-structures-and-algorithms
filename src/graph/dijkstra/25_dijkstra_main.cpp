#include "25_dijkstra.h"
#include <iostream>

int main() {
    int n = 5;
    std::vector<std::vector<std::pair<int,int>>> adj(n);
    adj[0] = {{1, 10}, {2, 3}};
    adj[1] = {{2, 1}, {3, 2}};
    adj[2] = {{1, 4}, {3, 8}, {4, 2}};
    adj[3] = {{4, 5}};
    adj[4] = {{3, 5}};

    auto dist = dijkstra(n, adj, 0);

    std::cout << "从顶点 0 出发的最短距离:" << std::endl;
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INT_MAX) {
            std::cout << "  顶点 " << i << ": 不可达" << std::endl;
        } else {
            std::cout << "  顶点 " << i << ": " << dist[i] << std::endl;
        }
    }

    return 0;
}
