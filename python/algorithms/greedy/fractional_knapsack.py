"""
分数背包问题 (Fractional Knapsack Problem)
时间复杂度: O(n log n) (排序) + O(n) (选择) = O(n log n)
空间复杂度: O(n) (存储物品信息)
对应 C++ 源码: src/advanced_algorithm/greedy/fractional_knapsack.cpp
"""

from __future__ import annotations


def fractional_knapsack(weights: list[float], values: list[float], capacity: float) -> float:
    items = sorted(
        zip(weights, values),
        key=lambda x: x[1] / x[0],
        reverse=True,
    )
    total_value = 0.0
    remaining = capacity
    for w, v in items:
        if remaining <= 0:
            break
        take = min(w, remaining)
        total_value += take * (v / w)
        remaining -= take
    return total_value


if __name__ == "__main__":
    weights = [10.0, 20.0, 30.0]
    values = [60.0, 100.0, 120.0]
    capacity = 50.0
    result = fractional_knapsack(weights, values, capacity)
    print(f"最大价值: {result:.2f}")
