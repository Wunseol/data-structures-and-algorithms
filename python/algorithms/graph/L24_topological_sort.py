"""拓扑排序（Topological Sort）— Kahn 算法

核心操作复杂度：O(V + E)

对应 C/C++ 源码路径：src/graph/topological_sort/
"""
from __future__ import annotations
from typing import List
from collections import deque


def topological_sort(n: int, adj: List[List[int]]) -> List[int]:
    in_degree: List[int] = [0] * n
    for u in range(n):
        for v in adj[u]:
            in_degree[v] += 1

    q: deque[int] = deque()
    for i in range(n):
        if in_degree[i] == 0:
            q.append(i)

    order: List[int] = []
    while q:
        u = q.popleft()
        order.append(u)
        for v in adj[u]:
            in_degree[v] -= 1
            if in_degree[v] == 0:
                q.append(v)

    if len(order) != n:
        return []
    return order


if __name__ == "__main__":
    adj: List[List[int]] = [[1, 2], [3], [3], [4], [5], []]
    result = topological_sort(6, adj)
    print(f"拓扑排序结果: {result}")

    cycle_adj: List[List[int]] = [[1], [2], [0]]
    cycle_result = topological_sort(3, cycle_adj)
    print(f"环图检测结果: {cycle_result}")

    assert result == [0, 1, 2, 3, 4, 5] or len(result) == 6
    assert cycle_result == []
