"""完全背包问题

时间复杂度: O(n * capacity) 其中 n 为物品种类数
空间复杂度: O(capacity)

对应 C++ 源码: src/advanced_algorithm/dynamic_programming/knapsack_complete.cpp
"""


def knapsack_complete(weights: list[int], values: list[int], capacity: int) -> int:
    n = len(weights)
    dp: list[int] = [0] * (capacity + 1)

    for i in range(n):
        for w in range(weights[i], capacity + 1):
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i])

    return dp[capacity]


if __name__ == "__main__":
    weights = [2, 3, 4, 5]
    values = [3, 4, 5, 6]
    capacity = 8
    result = knapsack_complete(weights, values, capacity)
    print(f"物品重量: {weights}")
    print(f"物品价值: {values}")
    print(f"背包容量: {capacity}")
    print(f"最大价值: {result}")

    assert knapsack_complete([2, 3, 4, 5], [3, 4, 5, 6], 8) == 12
    assert knapsack_complete([1, 2, 3], [6, 10, 12], 5) == 30
    assert knapsack_complete([], [], 10) == 0
    assert knapsack_complete([1], [5], 10) == 50
