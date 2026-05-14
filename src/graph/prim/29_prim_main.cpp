#include "29_prim.h"
#include <iostream>

int main() {
    int n = 4;
    std::vector<std::vector<std::pair<int,int>>> adj(n);
    adj[0] = {{1, 10}, {2, 6}, {3, 5}};
    adj[1] = {{0, 10}, {3, 15}};
    adj[2] = {{0, 6}, {3, 4}};
    adj[3] = {{0, 5}, {1, 15}, {2, 4}};

    int mstWeight = prim(n, adj, 0);
    std::cout << "最小生成树总权重: " << mstWeight << std::endl;

    return 0;
}
