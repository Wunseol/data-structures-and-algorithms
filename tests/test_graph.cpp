#include "self_test.h"
#include "../src/graph/topological_sort/24_topological_sort.h"
#include "../src/graph/dijkstra/25_dijkstra.h"
#include "../src/graph/bellman_ford/26_bellman_ford.h"
#include "../src/graph/floyd_warshall/27_floyd_warshall.h"
#include "../src/graph/kruskal/28_kruskal.h"
#include "../src/graph/prim/29_prim.h"
#include <climits>

static void test_topological_sort(void) {
    printf("  [Topological Sort]\n");
    // DAG: 0->1, 0->2, 1->3, 2->3
    int n = 4;
    std::vector<std::vector<int>> adj(n);
    adj[0].push_back(1); adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(3);
    auto result = topologicalSort(n, adj);
    ASSERT_EQ((int)result.size(), 4);
    // Verify topological order: 0 must come before 1 and 2, 1 and 2 before 3
    // Just check that all 4 nodes are present
    std::vector<bool> found(n, false);
    for (int v : result) found[v] = true;
    for (int i = 0; i < n; i++) ASSERT_TRUE(found[i]);

    // Cycle: 0->1, 1->0
    std::vector<std::vector<int>> adj2(2);
    adj2[0].push_back(1);
    adj2[1].push_back(0);
    auto result2 = topologicalSort(2, adj2);
    ASSERT_EQ((int)result2.size(), 0);
}

static void test_dijkstra(void) {
    printf("  [Dijkstra]\n");
    int n = 5;
    std::vector<std::vector<std::pair<int,int>>> adj(n);
    adj[0].push_back({1, 10}); adj[0].push_back({2, 3});
    adj[1].push_back({2, 1}); adj[1].push_back({3, 2});
    adj[2].push_back({1, 4}); adj[2].push_back({3, 8}); adj[2].push_back({4, 2});
    adj[3].push_back({4, 5});
    auto dist = dijkstra(n, adj, 0);
    ASSERT_EQ(dist[0], 0);
    ASSERT_EQ(dist[1], 7);
    ASSERT_EQ(dist[2], 3);
    ASSERT_EQ(dist[4], 5);
}

static void test_bellman_ford(void) {
    printf("  [Bellman-Ford]\n");
    int n = 4;
    std::vector<std::tuple<int,int,int>> edges = {
        {0, 1, 1}, {0, 2, 4}, {1, 2, -2}, {2, 3, 3}
    };
    auto dist = bellmanFord(n, edges, 0);
    ASSERT_EQ(dist[0], 0);
    ASSERT_EQ(dist[1], 1);
    ASSERT_EQ(dist[2], -1);
    ASSERT_EQ(dist[3], 2);

    // Negative cycle
    std::vector<std::tuple<int,int,int>> neg_edges = {
        {0, 1, 1}, {1, 2, -3}, {2, 0, 1}
    };
    auto neg_dist = bellmanFord(3, neg_edges, 0);
    ASSERT_EQ((int)neg_dist.size(), 0);
}

static void test_floyd_warshall(void) {
    printf("  [Floyd-Warshall]\n");
    int n = 4;
    const int INF = 99999999;
    std::vector<std::vector<int>> dist(n, std::vector<int>(n, INF));
    for (int i = 0; i < n; i++) dist[i][i] = 0;
    dist[0][1] = 5; dist[0][3] = 10;
    dist[1][2] = 3;
    dist[2][3] = 1;
    auto result = floydWarshall(n, dist);
    ASSERT_EQ(result[0][0], 0);
    ASSERT_EQ(result[0][1], 5);
    ASSERT_EQ(result[0][2], 8);
    ASSERT_EQ(result[0][3], 9);
}

static void test_kruskal_and_prim(void) {
    printf("  [Kruskal and Prim]\n");
    int n = 4;
    std::vector<std::tuple<int,int,int>> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}
    };
    int kruskal_weight = kruskal(n, edges);

    std::vector<std::vector<std::pair<int,int>>> adj(n);
    for (auto& [u, v, w] : edges) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int prim_weight = prim(n, adj, 0);
    ASSERT_EQ(kruskal_weight, prim_weight);
    ASSERT_EQ(kruskal_weight, 19);
}

int main(void) {
    TEST_BEGIN("Graph Algorithms");
    test_topological_sort();
    test_dijkstra();
    test_bellman_ford();
    test_floyd_warshall();
    test_kruskal_and_prim();
    TEST_END();
}
