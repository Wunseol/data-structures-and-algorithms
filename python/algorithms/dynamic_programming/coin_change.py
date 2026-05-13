"""零钱兑换 (Coin Change)

时间复杂度: O(amount * n) 其中 n 为硬币种类数
空间复杂度: O(amount)

对应 C++ 源码: src/advanced_algorithm/dynamic_programming/coin_change.cpp
"""


def coin_change(coins: list[int], amount: int) -> int:
    dp: list[int] = [amount + 1] * (amount + 1)
    dp[0] = 0

    for i in range(1, amount + 1):
        for c in coins:
            if c <= i and dp[i - c] != amount + 1:
                dp[i] = min(dp[i], dp[i - c] + 1)

    return dp[amount] if dp[amount] != amount + 1 else -1


if __name__ == "__main__":
    test_cases: list[tuple[list[int], int]] = [([1, 2, 5], 11), ([2], 3), ([1], 0), ([1, 2, 5], 100)]
    for coins, amount in test_cases:
        result = coin_change(coins, amount)
        print(f"硬币: {coins}, 金额: {amount} -> 最少硬币数: {result}")

    assert coin_change([1, 2, 5], 11) == 3
    assert coin_change([2], 3) == -1
    assert coin_change([1], 0) == 0
    assert coin_change([1, 2, 5], 100) == 20
