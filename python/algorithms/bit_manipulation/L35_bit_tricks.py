"""
位运算技巧 (Bit Manipulation Tricks)
时间复杂度: 各函数见下方标注
空间复杂度: O(1)
对应 C++ 源码: src/bit_manipulation/bit_manipulation.cpp
"""

from __future__ import annotations


def is_even(n: int) -> bool:
    return (n & 1) == 0


def swap_xor(a: int, b: int) -> tuple[int, int]:
    if a is b:
        return a, b
    a ^= b
    b ^= a
    a ^= b
    return a, b


def count_ones(n: int) -> int:
    count = 0
    while n:
        n &= n - 1
        count += 1
    return count


def is_power_of_two(n: int) -> bool:
    return n > 0 and (n & (n - 1)) == 0


def reverse_bits(n: int, bit_size: int = 32) -> int:
    result = 0
    for _ in range(bit_size):
        result <<= 1
        result |= n & 1
        n >>= 1
    return result


if __name__ == "__main__":
    print(f"is_even(4): {is_even(4)}")
    print(f"is_even(7): {is_even(7)}")

    a, b = swap_xor(10, 20)
    print(f"swap_xor(10, 20): ({a}, {b})")

    print(f"count_ones(13): {count_ones(13)}")
    print(f"count_ones(255): {count_ones(255)}")

    print(f"is_power_of_two(16): {is_power_of_two(16)}")
    print(f"is_power_of_two(18): {is_power_of_two(18)}")

    print(f"reverse_bits(0b00000010100101000001111010011100, 32): {bin(reverse_bits(0b00000010100101000001111010011100, 32))}")
