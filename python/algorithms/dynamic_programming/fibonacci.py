"""Fibonacci 数列

时间复杂度:
  - fib_recursive: O(2^n)
  - fib_memo: O(n)
  - fib_dp: O(n)
空间复杂度:
  - fib_recursive: O(n) (递归栈)
  - fib_memo: O(n)
  - fib_dp: O(n)

对应 C++ 源码: src/advanced_algorithm/dynamic_programming/fibonacci.cpp
"""

from functools import lru_cache


def fib_recursive(n: int) -> int:
    if n <= 1:
        return n
    return fib_recursive(n - 1) + fib_recursive(n - 2)


@lru_cache(maxsize=None)
def fib_memo(n: int) -> int:
    if n <= 1:
        return n
    return fib_memo(n - 1) + fib_memo(n - 2)


def fib_dp(n: int) -> int:
    if n <= 1:
        return n
    dp: list[int] = [0] * (n + 1)
    dp[0] = 0
    dp[1] = 1
    for i in range(2, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]
    return dp[n]


if __name__ == "__main__":
    for n in range(10):
        r1 = fib_recursive(n)
        r2 = fib_memo(n)
        r3 = fib_dp(n)
        assert r1 == r2 == r3
        print(f"F({n}) = {r3}")

    assert fib_dp(0) == 0
    assert fib_dp(1) == 1
    assert fib_dp(10) == 55
    assert fib_dp(20) == 6765
