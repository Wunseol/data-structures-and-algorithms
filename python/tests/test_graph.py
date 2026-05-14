import sys
import os
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from algorithms.graph.L24_topological_sort import topological_sort
from algorithms.graph.L25_dijkstra import dijkstra
from algorithms.graph.L26_bellman_ford import bellman_ford
from algorithms.graph.L27_floyd_warshall import floyd_warshall
from algorithms.graph.L28_kruskal import kruskal
from algorithms.graph.L29_prim import prim


class TestTopologicalSort(unittest.TestCase):
    def test_dag_returns_valid_order(self):
        adj = [[1, 2], [3], [3], [4], [5], []]
        result = topological_sort(6, adj)
        self.assertEqual(len(result), 6)
        pos = {v: i for i, v in enumerate(result)}
        for u in range(6):
            for v in adj[u]:
                self.assertLess(pos[u], pos[v])

    def test_cyclic_graph_returns_empty(self):
        adj = [[1], [2], [0]]
        result = topological_sort(3, adj)
        self.assertEqual(result, [])

    def test_single_node(self):
        adj = [[]]
        result = topological_sort(1, adj)
        self.assertEqual(result, [0])

    def test_disconnected_graph(self):
        adj = [[], [], []]
        result = topological_sort(3, adj)
        self.assertEqual(len(result), 3)
        self.assertEqual(set(result), {0, 1, 2})


class TestDijkstra(unittest.TestCase):
    def test_shortest_distances(self):
        adj = [
            [(1, 10), (2, 3)],
            [(2, 1), (3, 2)],
            [(1, 4), (3, 8), (4, 2)],
            [(4, 5)],
            [(3, 5)],
        ]
        dist = dijkstra(5, adj, 0)
        self.assertEqual(dist[0], 0)
        self.assertEqual(dist[2], 3)
        self.assertEqual(dist[4], 5)

    def test_unreachable_vertices(self):
        adj = [[(1, 5)], [], []]
        dist = dijkstra(3, adj, 0)
        self.assertEqual(dist[2], float("inf"))

    def test_single_vertex(self):
        adj = [[]]
        dist = dijkstra(1, adj, 0)
        self.assertEqual(dist[0], 0)


class TestBellmanFord(unittest.TestCase):
    def test_negative_weights(self):
        edges = [
            (0, 1, 6), (0, 2, 7), (1, 2, 8), (1, 3, 5),
            (1, 4, -4), (2, 3, -3), (2, 4, 9), (3, 1, -2),
            (4, 0, 2), (4, 3, 7),
        ]
        result = bellman_ford(5, edges, 0)
        self.assertIsNotNone(result)
        self.assertEqual(result[0], 0)

    def test_negative_cycle(self):
        edges = [(0, 1, 1), (1, 2, -1), (2, 0, -1)]
        result = bellman_ford(3, edges, 0)
        self.assertIsNone(result)

    def test_no_edges(self):
        result = bellman_ford(3, [], 0)
        self.assertIsNotNone(result)
        self.assertEqual(result[0], 0)
        self.assertEqual(result[1], float("inf"))


class TestFloydWarshall(unittest.TestCase):
    def test_all_pairs_shortest_paths(self):
        INF = float("inf")
        dist = [
            [0, 3, INF, 5],
            [2, 0, INF, 4],
            [INF, 1, 0, INF],
            [INF, INF, 2, 0],
        ]
        result = floyd_warshall(4, dist)
        self.assertEqual(result[0][2], 7)
        self.assertEqual(result[0][3], 5)
        self.assertEqual(result[2][0], 3)

    def test_single_vertex(self):
        result = floyd_warshall(1, [[0]])
        self.assertEqual(result[0][0], 0)

    def test_original_matrix_unchanged(self):
        INF = float("inf")
        dist = [
            [0, 3, INF],
            [2, 0, 1],
            [INF, 1, 0],
        ]
        original = [row[:] for row in dist]
        floyd_warshall(3, dist)
        self.assertEqual(dist, original)


class TestKruskal(unittest.TestCase):
    def test_mst_total_weight(self):
        edges = [
            (0, 1, 10), (0, 2, 6), (0, 3, 5),
            (1, 3, 15), (2, 3, 4),
        ]
        result = kruskal(4, edges)
        self.assertEqual(result, 19)

    def test_single_edge(self):
        result = kruskal(2, [(0, 1, 7)])
        self.assertEqual(result, 7)

    def test_disconnected_graph(self):
        edges = [(0, 1, 5)]
        result = kruskal(3, edges)
        self.assertEqual(result, 5)


class TestPrim(unittest.TestCase):
    def test_mst_total_weight(self):
        adj = [
            [(1, 10), (2, 6), (3, 5)],
            [(0, 10), (3, 15)],
            [(0, 6), (3, 4)],
            [(0, 5), (1, 15), (2, 4)],
        ]
        result = prim(4, adj, 0)
        self.assertEqual(result, 19)

    def test_matches_kruskal(self):
        edges = [
            (0, 1, 10), (0, 2, 6), (0, 3, 5),
            (1, 3, 15), (2, 3, 4),
        ]
        adj = [[], [], [], []]
        for u, v, w in edges:
            adj[u].append((v, w))
            adj[v].append((u, w))
        kruskal_result = kruskal(4, edges)
        prim_result = prim(4, adj, 0)
        self.assertEqual(kruskal_result, prim_result)

    def test_single_vertex(self):
        result = prim(1, [[]], 0)
        self.assertEqual(result, 0)


if __name__ == "__main__":
    unittest.main()
