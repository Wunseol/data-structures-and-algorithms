#include "29_prim.h"
#include <queue>
#include <vector>

int prim(int n, const std::vector<std::vector<std::pair<int,int>>>& adj, int start) {
    std::vector<bool> visited(n, false);
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<>> pq;

    visited[start] = true;
    for (auto [v, w] : adj[start]) {
        pq.push({w, v});
    }

    int totalWeight = 0;
    int edgeCount = 0;

    while (!pq.empty() && edgeCount < n - 1) {
        auto [w, u] = pq.top();
        pq.pop();

        if (visited[u]) {
            continue;
        }

        visited[u] = true;
        totalWeight += w;
        ++edgeCount;

        for (auto [v, weight] : adj[u]) {
            if (!visited[v]) {
                pq.push({weight, v});
            }
        }
    }

    return totalWeight;
}
