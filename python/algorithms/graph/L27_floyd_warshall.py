"""Floyd-Warshall 全源最短路径算法

核心操作复杂度：O(V³)

对应 C/C++ 源码路径：src/graph/floyd_warshall/
"""
from __future__ import annotations
from typing import List


def floyd_warshall(n: int, dist: List[List[int]]) -> List[List[int]]:
    d = [row[:] for row in dist]

    for k in range(n):
        for i in range(n):
            for j in range(n):
                if d[i][k] + d[k][j] < d[i][j]:
                    d[i][j] = d[i][k] + d[k][j]

    return d


if __name__ == "__main__":
    INF = float("inf")
    dist: List[List[int]] = [
        [0, 3, INF, 5],
        [2, 0, INF, 4],
        [INF, 1, 0, INF],
        [INF, INF, 2, 0],
    ]
    result = floyd_warshall(4, dist)
    print("全源最短路径矩阵:")
    for row in result:
        print([x if x != INF else "INF" for x in row])

    assert result[0][2] == 7
    assert result[0][3] == 5
