"""素数筛法（Sieve of Eratosthenes）

核心操作复杂度：
  sieve_of_eratosthenes: O(n log log n)

对应 C/C++ 源码路径：src/math/math_algorithms.h
"""

from __future__ import annotations


def sieve_of_eratosthenes(n: int) -> list[int]:
    if n < 2:
        return []
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False
    i = 2
    while i * i <= n:
        if is_prime[i]:
            for j in range(i * i, n + 1, i):
                is_prime[j] = False
        i += 1
    return [i for i in range(2, n + 1) if is_prime[i]]


if __name__ == "__main__":
    assert sieve_of_eratosthenes(-1) == []
    assert sieve_of_eratosthenes(1) == []
    assert sieve_of_eratosthenes(2) == [2]
    assert sieve_of_eratosthenes(10) == [2, 3, 5, 7]
    assert sieve_of_eratosthenes(30) == [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]

    primes_100 = sieve_of_eratosthenes(100)
    assert len(primes_100) == 25
    assert primes_100[-1] == 97

    print(f"30 以内的素数: {sieve_of_eratosthenes(30)}")
    print(f"100 以内共有 {len(primes_100)} 个素数")

    print("\n所有测试通过！")
