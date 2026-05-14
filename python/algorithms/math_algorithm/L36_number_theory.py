"""数论算法（Number Theory）

核心操作复杂度：
  gcd:              O(log(min(a,b)))
  lcm:              O(log(min(a,b)))
  fast_pow:         O(log exp)
  mod_inverse:      O(log m)
  binomial:         O(k)
  catalan:          O(n)
  fibonacci_matrix: O(log n)

对应 C/C++ 源码路径：src/math/math_algorithms.h
"""

from __future__ import annotations


def gcd(a: int, b: int) -> int:
    while b != 0:
        a, b = b, a % b
    return a


def lcm(a: int, b: int) -> int:
    if a == 0 or b == 0:
        return 0
    return a // gcd(a, b) * b


def fast_pow(base: int, exp: int, mod: int) -> int:
    result = 1
    base %= mod
    while exp > 0:
        if exp & 1:
            result = result * base % mod
        exp >>= 1
        base = base * base % mod
    return result


def _extended_gcd(a: int, b: int) -> tuple[int, int, int]:
    if b == 0:
        return a, 1, 0
    g, x1, y1 = _extended_gcd(b, a % b)
    return g, y1, x1 - (a // b) * y1


def mod_inverse(a: int, m: int) -> int:
    g, x, _ = _extended_gcd(a, m)
    if g != 1:
        return -1
    return x % m


def binomial(n: int, k: int) -> int:
    if k < 0 or k > n:
        return 0
    if k == 0 or k == n:
        return 1
    if k > n - k:
        k = n - k

    dp = [0] * (k + 1)
    dp[0] = 1
    for i in range(1, n + 1):
        j = min(i, k)
        while j > 0:
            dp[j] = dp[j] + dp[j - 1]
            j -= 1
    return dp[k]


def catalan(n: int) -> int:
    if n < 0:
        return 0
    dp = [0] * (n + 1)
    dp[0] = 1
    for i in range(1, n + 1):
        for j in range(i):
            dp[i] += dp[j] * dp[i - 1 - j]
    return dp[n]


def _matrix_multiply(A: list[list[int]], B: list[list[int]], mod: int) -> list[list[int]]:
    C = [[0, 0], [0, 0]]
    for i in range(2):
        for j in range(2):
            for k in range(2):
                C[i][j] = (C[i][j] + A[i][k] * B[k][j] % mod) % mod
    return C


def fibonacci_matrix(n: int) -> int:
    if n <= 0:
        return 0
    if n == 1:
        return 1

    mod = 1000000007
    result = [[1, 0], [0, 1]]
    base = [[1, 1], [1, 0]]
    p = n - 1

    while p > 0:
        if p & 1:
            result = _matrix_multiply(result, base, mod)
        base = _matrix_multiply(base, base, mod)
        p >>= 1

    return result[0][0]


if __name__ == "__main__":
    assert gcd(12, 8) == 4
    assert gcd(7, 13) == 1
    assert gcd(0, 5) == 5
    print("gcd 测试通过")

    assert lcm(4, 6) == 12
    assert lcm(7, 13) == 91
    assert lcm(0, 5) == 0
    print("lcm 测试通过")

    assert fast_pow(2, 10, 1000000007) == 1024
    assert fast_pow(3, 0, 1000000007) == 1
    assert fast_pow(2, 30, 1000000007) == 73741817
    print("fast_pow 测试通过")

    assert mod_inverse(3, 7) == 5
    assert mod_inverse(2, 5) == 3
    assert mod_inverse(2, 4) == -1
    print("mod_inverse 测试通过")

    assert binomial(5, 2) == 10
    assert binomial(10, 3) == 120
    assert binomial(10, 0) == 1
    assert binomial(10, 10) == 1
    assert binomial(5, 6) == 0
    print("binomial 测试通过")

    assert catalan(0) == 1
    assert catalan(1) == 1
    assert catalan(2) == 2
    assert catalan(3) == 5
    assert catalan(4) == 14
    assert catalan(5) == 42
    print("catalan 测试通过")

    assert fibonacci_matrix(0) == 0
    assert fibonacci_matrix(1) == 1
    assert fibonacci_matrix(2) == 1
    assert fibonacci_matrix(3) == 2
    assert fibonacci_matrix(10) == 55
    assert fibonacci_matrix(50) == 12586269025 % 1000000007
    print("fibonacci_matrix 测试通过")

    print("\n所有测试通过！")
