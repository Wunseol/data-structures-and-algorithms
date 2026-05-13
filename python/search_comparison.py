"""
搜索算法性能比较
比较线性搜索、二分搜索、插值搜索、斐波那契搜索在不同规模下的表现
"""

import random
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

from algorithms.searching.binary_search import binary_search
from algorithms.searching.fibonacci_search import fibonacci_search
from algorithms.searching.interpolation_search import interpolation_search
from algorithms.searching.linear_search import linear_search


SEARCH_ALGORITHMS: list[tuple[str, object]] = [
    ("Linear Search", linear_search),
    ("Binary Search", binary_search),
    ("Interpolation Search", interpolation_search),
    ("Fibonacci Search", fibonacci_search),
]

SIZES = [100, 1000, 10000, 100000]


def generate_sorted_array(size: int) -> list[int]:
    arr = sorted(random.sample(range(size * 10), size))
    return arr


def time_search(func, arr: list[int], targets: list[int]) -> float:
    start = time.perf_counter()
    for t in targets:
        func(arr, t)
    end = time.perf_counter()
    return end - start


def run_comparison():
    print("=" * 100)
    print("搜索算法性能比较")
    print("=" * 100)

    for size in SIZES:
        arr = generate_sorted_array(size)
        existing_targets = random.choices(arr, k=100)
        non_existing_targets = [size * 10 + i for i in range(100)]
        all_targets = existing_targets + non_existing_targets

        print(f"\n{'─' * 100}")
        print(f"数组大小: {size}  |  搜索次数: 200 (100 存在 + 100 不存在)")
        print(f"{'─' * 100}")
        print(f"{'算法':<24} {'存在(s)':<16} {'不存在(s)':<16} {'平均(s)':<16} {'正确性':<10}")
        print(f"{'─' * 100}")

        for name, func in SEARCH_ALGORITHMS:
            t_exist = time_search(func, arr, existing_targets)
            t_not_exist = time_search(func, arr, non_existing_targets)
            t_avg = (t_exist + t_not_exist) / 2

            correct = True
            for t in existing_targets[:10]:
                if func(arr, t) == -1:
                    correct = False
                    break
            for t in non_existing_targets[:10]:
                if func(arr, t) != -1:
                    correct = False
                    break

            status = "✓ 通过" if correct else "✗ 失败"
            print(f"{name:<24} {t_exist:<16.6f} {t_not_exist:<16.6f} {t_avg:<16.6f} {status:<10}")

    print(f"\n{'=' * 100}")
    print("说明:")
    print("  - Linear Search: O(n)，对无序数组有效")
    print("  - Binary Search: O(log n)，要求数组有序")
    print("  - Interpolation Search: 平均 O(log log n)，均匀分布时最优，最坏 O(n)")
    print("  - Fibonacci Search: O(log n)，类似二分搜索但只使用加减法")
    print("=" * 100)


if __name__ == "__main__":
    run_comparison()
