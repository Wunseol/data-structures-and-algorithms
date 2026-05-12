"""
排序算法性能比较
比较不同排序算法在不同规模和输入特征下的运行时间
"""

import random
import time
from copy import deepcopy


def bubble_sort(arr: list[int]) -> list[int]:
    a = arr[:]
    n = len(a)
    for i in range(n - 1):
        swapped = False
        for j in range(n - 1 - i):
            if a[j] > a[j + 1]:
                a[j], a[j + 1] = a[j + 1], a[j]
                swapped = True
        if not swapped:
            break
    return a


def selection_sort(arr: list[int]) -> list[int]:
    a = arr[:]
    n = len(a)
    for i in range(n - 1):
        min_idx = i
        for j in range(i + 1, n):
            if a[j] < a[min_idx]:
                min_idx = j
        a[i], a[min_idx] = a[min_idx], a[i]
    return a


def insertion_sort(arr: list[int]) -> list[int]:
    a = arr[:]
    for i in range(1, len(a)):
        key = a[i]
        j = i - 1
        while j >= 0 and a[j] > key:
            a[j + 1] = a[j]
            j -= 1
        a[j + 1] = key
    return a


def shell_sort(arr: list[int]) -> list[int]:
    a = arr[:]
    n = len(a)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = a[i]
            j = i
            while j >= gap and a[j - gap] > temp:
                a[j] = a[j - gap]
                j -= gap
            a[j] = temp
        gap //= 2
    return a


def merge_sort(arr: list[int]) -> list[int]:
    a = arr[:]

    def _merge(left: int, mid: int, right: int):
        temp = a[left:right + 1]
        i, j, k = left, mid + 1, 0
        while i <= mid and j <= right:
            if a[i] <= a[j]:
                temp[k] = a[i]
                i += 1
            else:
                temp[k] = a[j]
                j += 1
            k += 1
        while i <= mid:
            temp[k] = a[i]
            i += 1
            k += 1
        while j <= right:
            temp[k] = a[j]
            j += 1
            k += 1
        a[left:right + 1] = temp

    def _sort(left: int, right: int):
        if left >= right:
            return
        mid = (left + right) // 2
        _sort(left, mid)
        _sort(mid + 1, right)
        _merge(left, mid, right)

    _sort(0, len(a) - 1)
    return a


def quick_sort(arr: list[int]) -> list[int]:
    a = arr[:]

    def _sort(lo: int, hi: int):
        if lo >= hi:
            return
        pivot = a[(lo + hi) // 2]
        i, j = lo, hi
        while i <= j:
            while a[i] < pivot:
                i += 1
            while a[j] > pivot:
                j -= 1
            if i <= j:
                a[i], a[j] = a[j], a[i]
                i += 1
                j -= 1
        _sort(lo, j)
        _sort(i, hi)

    _sort(0, len(a) - 1)
    return a


def heap_sort(arr: list[int]) -> list[int]:
    a = arr[:]
    n = len(a)

    def _heapify(size: int, root: int):
        largest = root
        left = 2 * root + 1
        right = 2 * root + 2
        if left < size and a[left] > a[largest]:
            largest = left
        if right < size and a[right] > a[largest]:
            largest = right
        if largest != root:
            a[root], a[largest] = a[largest], a[root]
            _heapify(size, largest)

    for i in range(n // 2 - 1, -1, -1):
        _heapify(n, i)
    for i in range(n - 1, 0, -1):
        a[0], a[i] = a[i], a[0]
        _heapify(i, 0)
    return a


def counting_sort(arr: list[int]) -> list[int]:
    if not arr:
        return []
    a = arr[:]
    min_val, max_val = min(a), max(a)
    range_size = max_val - min_val + 1
    count = [0] * range_size
    for x in a:
        count[x - min_val] += 1
    result = []
    for i, c in enumerate(count):
        result.extend([i + min_val] * c)
    return result


def radix_sort(arr: list[int]) -> list[int]:
    if not arr:
        return []
    a = arr[:]
    min_val = min(a)
    if min_val < 0:
        a = [x - min_val for x in a]
    max_val = max(a)
    exp = 1
    while max_val // exp > 0:
        buckets: list[list[int]] = [[] for _ in range(10)]
        for x in a:
            buckets[(x // exp) % 10].append(x)
        a = [x for bucket in buckets for x in bucket]
        exp *= 10
    if min_val < 0:
        a = [x + min_val for x in a]
    return a


def bucket_sort(arr: list[int]) -> list[int]:
    if not arr:
        return []
    a = arr[:]
    min_val, max_val = min(a), max(a)
    if min_val == max_val:
        return a
    bucket_count = max(1, len(a) // 10)
    buckets: list[list[int]] = [[] for _ in range(bucket_count)]
    for x in a:
        idx = min(int((x - min_val) / (max_val - min_val + 1) * bucket_count), bucket_count - 1)
        buckets[idx].append(x)
    result = []
    for bucket in buckets:
        result.extend(sorted(bucket))
    return result


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
