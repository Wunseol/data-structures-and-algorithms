"""矩阵连乘（Matrix Chain Multiplication）— 动态规划

核心操作复杂度：O(n³)

对应 C/C++ 源码路径：src/advanced_algorithm/dynamic_programming/matrix_chain.cpp
"""
from __future__ import annotations
from typing import List


def matrix_chain_order(dims: List[int]) -> int:
    n = len(dims) - 1
    if n <= 0:
        return 0
    dp: List[List[int]] = [[0] * n for _ in range(n)]
    for length in range(2, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1
            dp[i][j] = float("inf")
            for k in range(i, j):
                cost = dp[i][k] + dp[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1]
                if cost < dp[i][j]:
                    dp[i][j] = cost
    return dp[0][n - 1]


if __name__ == "__main__":
    test_cases: list[tuple[list[int], int]] = [
        ([10, 30, 5, 60], 4500),
        ([40, 20, 30, 10, 30], 26000),
        ([1, 2, 3, 4], 18),
        ([10, 20], 0),
    ]
    for dims, expected in test_cases:
        result = matrix_chain_order(dims)
        print(f"matrix_chain_order({dims}) = {result}")
        assert result == expected, f"Expected {expected}, got {result}"
