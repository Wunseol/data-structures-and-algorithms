"""邻接表（Adjacency List）

核心操作复杂度：
  add_edge:    O(1)
  remove_edge: O(degree)
  bfs:         O(V + E)
  dfs:         O(V + E)

对应 C/C++ 源码路径：src/graph/adjacency_list/
"""

from __future__ import annotations
from collections import deque


class AdjacencyList:
    def __init__(self, vertex_count: int, directed: bool = False) -> None:
        self._vertex_count = vertex_count
        self._directed = directed
        self._adj: list[list[tuple[int, float]]] = [[] for _ in range(vertex_count)]

    def add_edge(self, v1: int, v2: int, weight: float = 1.0) -> None:
        if v1 < 0 or v1 >= self._vertex_count or v2 < 0 or v2 >= self._vertex_count:
            raise IndexError("Vertex index out of range")
        self._adj[v1].append((v2, weight))
        if not self._directed:
            self._adj[v2].append((v1, weight))

    def remove_edge(self, v1: int, v2: int) -> None:
        if v1 < 0 or v1 >= self._vertex_count or v2 < 0 or v2 >= self._vertex_count:
            raise IndexError("Vertex index out of range")
        self._adj[v1] = [(v, w) for v, w in self._adj[v1] if v != v2]
        if not self._directed:
            self._adj[v2] = [(v, w) for v, w in self._adj[v2] if v != v1]

    def bfs(self, start: int) -> list[int]:
        if start < 0 or start >= self._vertex_count:
            raise IndexError("Start vertex out of range")
        visited: list[bool] = [False] * self._vertex_count
        result: list[int] = []
        q: deque[int] = deque()
        q.append(start)
        visited[start] = True
        while q:
            v = q.popleft()
            result.append(v)
            for neighbor, _ in self._adj[v]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    q.append(neighbor)
        return result

    def dfs(self, start: int) -> list[int]:
        if start < 0 or start >= self._vertex_count:
            raise IndexError("Start vertex out of range")
        visited: list[bool] = [False] * self._vertex_count
        result: list[int] = []
        self._dfs(start, visited, result)
        return result

    def _dfs(self, v: int, visited: list[bool], result: list[int]) -> None:
        visited[v] = True
        result.append(v)
        for neighbor, _ in self._adj[v]:
            if not visited[neighbor]:
                self._dfs(neighbor, visited, result)

    def __str__(self) -> str:
        lines: list[str] = []
        for i in range(self._vertex_count):
            edges = ", ".join(f"{v}(w={w})" for v, w in self._adj[i])
            lines.append(f"{i}: [{edges}]")
        return "\n".join(lines)


if __name__ == "__main__":
    g = AdjacencyList(5)
    g.add_edge(0, 1)
    g.add_edge(0, 2)
    g.add_edge(1, 3)
    g.add_edge(2, 4)
    g.add_edge(3, 4)

    print("Adjacency List:")
    print(g)
    print(f"\nBFS from 0: {g.bfs(0)}")
    print(f"DFS from 0: {g.dfs(0)}")

    g.remove_edge(0, 2)
    print(f"\nAfter remove edge (0,2), DFS from 0: {g.dfs(0)}")
