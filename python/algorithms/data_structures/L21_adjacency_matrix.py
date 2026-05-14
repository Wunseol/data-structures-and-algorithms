"""邻接矩阵（Adjacency Matrix）

核心操作复杂度：
  add_edge:    O(1)
  remove_edge: O(1)
  bfs:         O(V^2)
  dfs:         O(V^2)

对应 C/C++ 源码路径：src/graph/adjacency_matrix/
"""

from __future__ import annotations
from collections import deque


class AdjacencyMatrix:
    def __init__(self, vertex_count: int, directed: bool = False) -> None:
        self._vertex_count = vertex_count
        self._directed = directed
        self._matrix: list[list[float]] = [[0.0] * vertex_count for _ in range(vertex_count)]

    def add_edge(self, v1: int, v2: int, weight: float = 1.0) -> None:
        if v1 < 0 or v1 >= self._vertex_count or v2 < 0 or v2 >= self._vertex_count:
            raise IndexError("Vertex index out of range")
        self._matrix[v1][v2] = weight
        if not self._directed:
            self._matrix[v2][v1] = weight

    def remove_edge(self, v1: int, v2: int) -> None:
        if v1 < 0 or v1 >= self._vertex_count or v2 < 0 or v2 >= self._vertex_count:
            raise IndexError("Vertex index out of range")
        self._matrix[v1][v2] = 0.0
        if not self._directed:
            self._matrix[v2][v1] = 0.0

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
            for neighbor in range(self._vertex_count):
                if self._matrix[v][neighbor] != 0.0 and not visited[neighbor]:
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
        for neighbor in range(self._vertex_count):
            if self._matrix[v][neighbor] != 0.0 and not visited[neighbor]:
                self._dfs(neighbor, visited, result)

    def __str__(self) -> str:
        lines: list[str] = []
        for row in self._matrix:
            lines.append("  ".join(f"{x:.0f}" if x == int(x) else f"{x}" for x in row))
        return "\n".join(lines)


if __name__ == "__main__":
    g = AdjacencyMatrix(5)
    g.add_edge(0, 1)
    g.add_edge(0, 2)
    g.add_edge(1, 3)
    g.add_edge(2, 4)
    g.add_edge(3, 4)

    print("Adjacency Matrix:")
    print(g)
    print(f"BFS from 0: {g.bfs(0)}")
    print(f"DFS from 0: {g.dfs(0)}")

    g.remove_edge(0, 2)
    print(f"\nAfter remove edge (0,2), BFS from 0: {g.bfs(0)}")
