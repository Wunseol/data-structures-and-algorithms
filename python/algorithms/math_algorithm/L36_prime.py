"""素数判定（Prime Testing）

核心操作复杂度：
  is_prime:     O(√n)
  miller_rabin: O(k log³n)

对应 C/C++ 源码路径：src/math/math_algorithms.h
"""

from __future__ import annotations

import random


def is_prime(n: int) -> bool:
    if n < 2:
        return False
    if n < 4:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True


def _mod_pow(base: int, exp: int, mod: int) -> int:
    result = 1
    base %= mod
    while exp > 0:
        if exp & 1:
            result = result * base % mod
        exp >>= 1
        base = base * base % mod
    return result


def _miller_rabin_test(n: int, d: int, a: int) -> bool:
    x = _mod_pow(a, d, n)
    if x == 1 or x == n - 1:
        return True
    while d != n - 1:
        x = x * x % n
        d <<= 1
        if x == 1:
            return False
        if x == n - 1:
            return True
    return False


def miller_rabin(n: int, k: int = 5) -> bool:
    if n < 2:
        return False
    if n < 4:
        return True
    if n % 2 == 0:
        return False

    d = n - 1
    while d % 2 == 0:
        d >>= 1

    rng = random.Random(42)
    for _ in range(k):
        a = 2 + rng.randint(0, n - 4)
        if not _miller_rabin_test(n, d, a):
            return False
    return True


if __name__ == "__main__":
    primes_small = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31]
    non_primes = [0, 1, 4, 6, 8, 9, 10, 12, 14, 15, 16]

    for p in primes_small:
        assert is_prime(p), f"{p} should be prime"
    for np in non_primes:
        assert not is_prime(np), f"{np} should not be prime"
    print("is_prime 测试通过")

    for p in primes_small:
        assert miller_rabin(p), f"{p} should be prime (miller_rabin)"
    for np in non_primes:
        assert not miller_rabin(np), f"{np} should not be prime (miller_rabin)"

    large_prime = 1000000007
    large_composite = 1000000001
    assert miller_rabin(large_prime), f"{large_prime} should be prime"
    assert not miller_rabin(large_composite), f"{large_composite} should not be prime"
    print("miller_rabin 测试通过")

    print("\n所有测试通过！")
