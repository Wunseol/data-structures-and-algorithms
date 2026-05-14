#include "26_bellman_ford.h"
#include <climits>

std::vector<int> bellmanFord(int n, const std::vector<std::tuple<int,int,int>>& edges, int source) {
    std::vector<int> dist(n, INT_MAX);
    dist[source] = 0;

    for (int i = 0; i < n - 1; ++i) {
        bool updated = false;
        for (auto [u, v, w] : edges) {
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                updated = true;
            }
        }
        if (!updated) {
            break;
        }
    }

    for (auto [u, v, w] : edges) {
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            return {};
        }
    }

    return dist;
}
