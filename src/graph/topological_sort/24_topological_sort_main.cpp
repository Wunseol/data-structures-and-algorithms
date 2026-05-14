#include "24_topological_sort.h"
#include <iostream>

int main() {
    int n = 6;
    std::vector<std::vector<int>> adj(n);
    adj[0] = {1, 2};
    adj[1] = {3};
    adj[2] = {3};
    adj[3] = {4};
    adj[4] = {5};
    adj[5] = {};

    auto order = topologicalSort(n, adj);
    if (order.empty()) {
        std::cout << "图中存在环，无法拓扑排序" << std::endl;
    } else {
        std::cout << "拓扑排序结果: ";
        for (int v : order) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }

    std::vector<std::vector<int>> cycleAdj(3);
    cycleAdj[0] = {1};
    cycleAdj[1] = {2};
    cycleAdj[2] = {0};

    auto cycleOrder = topologicalSort(3, cycleAdj);
    if (cycleOrder.empty()) {
        std::cout << "环图检测: 图中存在环" << std::endl;
    }

    return 0;
}
