"""Bellman-Ford 最短路径算法

核心操作复杂度：O(V * E)

对应 C/C++ 源码路径：src/graph/bellman_ford/
"""
from __future__ import annotations
from typing import List, Tuple, Optional


def bellman_ford(n: int, edges: List[Tuple[int, int, int]], source: int = 0) -> Optional[List[int]]:
    dist: List[int] = [float("inf")] * n
    dist[source] = 0

    for _ in range(n - 1):
        updated = False
        for u, v, w in edges:
            if dist[u] != float("inf") and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                updated = True
        if not updated:
            break

    for u, v, w in edges:
        if dist[u] != float("inf") and dist[u] + w < dist[v]:
            return None

    return dist


if __name__ == "__main__":
    edges: List[Tuple[int, int, int]] = [
        (0, 1, 6), (0, 2, 7), (1, 2, 8), (1, 3, 5),
        (1, 4, -4), (2, 3, -3), (2, 4, 9), (3, 1, -2),
        (4, 0, 2), (4, 3, 7),
    ]
    result = bellman_ford(5, edges, 0)
    print(f"从顶点 0 出发的最短距离: {result}")

    neg_edges: List[Tuple[int, int, int]] = [(0, 1, 1), (1, 2, -1), (2, 0, -1)]
    neg_result = bellman_ford(3, neg_edges, 0)
    print(f"负权环检测结果: {neg_result}")

    assert result is not None
    assert result[0] == 0
    assert neg_result is None
