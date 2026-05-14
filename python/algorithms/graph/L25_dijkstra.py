"""Dijkstra 最短路径算法

核心操作复杂度：O((V + E) log V)

对应 C/C++ 源码路径：src/graph/dijkstra/
"""
from __future__ import annotations
from typing import List, Tuple
import heapq


def dijkstra(n: int, adj: List[List[Tuple[int, int]]], source: int = 0) -> List[int]:
    dist: List[int] = [float("inf")] * n
    dist[source] = 0
    pq: List[Tuple[int, int]] = [(0, source)]

    while pq:
        d, u = heapq.heappop(pq)
        if d > dist[u]:
            continue
        for v, w in adj[u]:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                heapq.heappush(pq, (dist[v], v))

    return dist


if __name__ == "__main__":
    adj: List[List[Tuple[int, int]]] = [
        [(1, 10), (2, 3)],
        [(2, 1), (3, 2)],
        [(1, 4), (3, 8), (4, 2)],
        [(4, 5)],
        [(3, 5)],
    ]
    result = dijkstra(5, adj, 0)
    print(f"从顶点 0 出发的最短距离: {result}")

    assert result[0] == 0
    assert result[2] == 3
    assert result[4] == 5
