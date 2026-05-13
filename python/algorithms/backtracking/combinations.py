"""
组合 (Combinations)
时间复杂度: O(C(n, k))
空间复杂度: O(k) (递归栈 + 当前组合)
对应 C++ 源码: src/advanced_algorithm/backtracking/combinations.cpp
"""

from __future__ import annotations


def combine(n: int, k: int) -> list[list[int]]:
    results: list[list[int]] = []
    current: list[int] = []

    def backtrack(start: int) -> None:
        if len(current) == k:
            results.append(current[:])
            return
        for i in range(start, n - (k - len(current)) + 2):
            current.append(i)
            backtrack(i + 1)
            current.pop()

    backtrack(1)
    return results


if __name__ == "__main__":
    n, k = 4, 2
    result = combine(n, k)
    print(f"C({n},{k}) = {len(result)}")
    for c in result:
        print(f"  {c}")
