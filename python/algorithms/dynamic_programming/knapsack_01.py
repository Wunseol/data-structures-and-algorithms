"""0-1 背包问题

时间复杂度: O(n * capacity) 其中 n 为物品数量
空间复杂度: O(n * capacity)

对应 C++ 源码: src/advanced_algorithm/dynamic_programming/knapsack_01.cpp
"""


def knapsack_01(weights: list[int], values: list[int], capacity: int) -> int:
    n = len(weights)
    dp: list[list[int]] = [[0] * (capacity + 1) for _ in range(n + 1)]

    for i in range(1, n + 1):
        for w in range(capacity + 1):
            dp[i][w] = dp[i - 1][w]
            if w >= weights[i - 1]:
                dp[i][w] = max(dp[i][w], dp[i - 1][w - weights[i - 1]] + values[i - 1])

    return dp[n][capacity]


if __name__ == "__main__":
    weights = [2, 3, 4, 5]
    values = [3, 4, 5, 6]
    capacity = 8
    result = knapsack_01(weights, values, capacity)
    print(f"物品重量: {weights}")
    print(f"物品价值: {values}")
    print(f"背包容量: {capacity}")
    print(f"最大价值: {result}")

    assert knapsack_01([2, 3, 4, 5], [3, 4, 5, 6], 8) == 10
    assert knapsack_01([1, 2, 3], [6, 10, 12], 5) == 22
    assert knapsack_01([], [], 10) == 0
    assert knapsack_01([5], [10], 3) == 0
