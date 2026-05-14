#include "25_dijkstra.h"
#include <queue>
#include <climits>
#include <algorithm>

std::vector<int> dijkstra(int n, const std::vector<std::vector<std::pair<int,int>>>& adj, int source) {
    std::vector<int> dist(n, INT_MAX);
    dist[source] = 0;

    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        for (auto [v, w] : adj[u]) {
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}
