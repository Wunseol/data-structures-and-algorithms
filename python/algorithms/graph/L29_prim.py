"""Prim 最小生成树算法

核心操作复杂度：O((V + E) log V)

对应 C/C++ 源码路径：src/graph/prim/
"""
from __future__ import annotations
from typing import List, Tuple
import heapq


def prim(n: int, adj: List[List[Tuple[int, int]]], start: int = 0) -> int:
    visited: List[bool] = [False] * n
    pq: List[Tuple[int, int]] = []

    visited[start] = True
    for v, w in adj[start]:
        heapq.heappush(pq, (w, v))

    total_weight = 0
    edge_count = 0

    while pq and edge_count < n - 1:
        w, u = heapq.heappop(pq)
        if visited[u]:
            continue
        visited[u] = True
        total_weight += w
        edge_count += 1
        for v, weight in adj[u]:
            if not visited[v]:
                heapq.heappush(pq, (weight, v))

    return total_weight


if __name__ == "__main__":
    adj: List[List[Tuple[int, int]]] = [
        [(1, 10), (2, 6), (3, 5)],
        [(0, 10), (3, 15)],
        [(0, 6), (3, 4)],
        [(0, 5), (1, 15), (2, 4)],
    ]
    result = prim(4, adj, 0)
    print(f"最小生成树总权重: {result}")

    assert result == 19
