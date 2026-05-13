"""
排序算法性能比较
比较不同排序算法在不同规模和输入特征下的运行时间
"""

import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

import random
import time
from copy import deepcopy

from algorithms.sorting import (
    bubble_sort,
    bucket_sort,
    counting_sort,
    heap_sort,
    insertion_sort,
    merge_sort,
    quick_sort,
    radix_sort,
    selection_sort,
    shell_sort,
)


def builtin_sorted(arr: list[int]) -> list[int]:
    return sorted(arr)


ALGORITHMS: list[tuple[str, object]] = [
    ("Bubble Sort", bubble_sort),
    ("Selection Sort", selection_sort),
    ("Insertion Sort", insertion_sort),
    ("Shell Sort", shell_sort),
    ("Merge Sort", merge_sort),
    ("Quick Sort", quick_sort),
    ("Heap Sort", heap_sort),
    ("Counting Sort", counting_sort),
    ("Radix Sort", radix_sort),
    ("Bucket Sort", bucket_sort),
    ("Python sorted()", builtin_sorted),
]

SIZES = [100, 1000, 10000]

SLOW_ALGORITHMS = {"Bubble Sort", "Selection Sort", "Insertion Sort"}


def generate_arrays(size: int) -> dict[str, list[int]]:
    random_arr = [random.randint(0, size * 10) for _ in range(size)]
    sorted_arr = sorted(random_arr)
    reverse_arr = sorted_arr[::-1]
    return {
        "random": random_arr,
        "sorted": sorted_arr,
        "reverse": reverse_arr,
    }


def time_algorithm(func, arr: list[int]) -> float:
    start = time.perf_counter()
    func(arr)
    end = time.perf_counter()
    return end - start


def run_comparison():
    print("=" * 90)
    print("排序算法性能比较")
    print("=" * 90)

    for size in SIZES:
        arrays = generate_arrays(size)
        print(f"\n{'─' * 90}")
        print(f"数组大小: {size}")
        print(f"{'─' * 90}")
        print(f"{'算法':<20} {'随机(s)':<14} {'已排序(s)':<14} {'逆序(s)':<14}")
        print(f"{'─' * 90}")

        for name, func in ALGORITHMS:
            if size >= 10000 and name in SLOW_ALGORITHMS:
                print(f"{name:<20} {'(跳过)':<14} {'(跳过)':<14} {'(跳过)':<14}")
                continue

            times = []
            for key in ("random", "sorted", "reverse"):
                t = time_algorithm(func, arrays[key])
                times.append(t)

            print(f"{name:<20} {times[0]:<14.6f} {times[1]:<14.6f} {times[2]:<14.6f}")

    print(f"\n{'=' * 90}")
    print("说明:")
    print("  - O(n²) 算法在 n=10000 时自动跳过，避免长时间等待")
    print("  - 时间使用 time.perf_counter() 测量")
    print("  - Counting/Radix/Bucket Sort 仅适用于非负整数")
    print("=" * 90)


if __name__ == "__main__":
    run_comparison()
