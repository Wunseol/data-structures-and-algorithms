"""堆排序 (Heap Sort)

时间复杂度: 平均 O(n log n), 最坏 O(n log n), 最好 O(n log n)
空间复杂度: O(1)
稳定性: 不稳定
对应 C++ 源码: src/sorting/sequential_list_sorting.cpp -> HeapSort()
"""


def _sift_down(arr: list[int], start: int, end: int) -> None:
    root = start
    while True:
        child = 2 * root + 1
        if child > end:
            break
        if child + 1 <= end and arr[child] < arr[child + 1]:
            child += 1
        if arr[root] >= arr[child]:
            break
        arr[root], arr[child] = arr[child], arr[root]
        root = child


def heap_sort(arr: list[int]) -> list[int]:
    a = arr[:]
    n = len(a)
    if n <= 1:
        return a

    for i in range(n // 2 - 1, -1, -1):
        _sift_down(a, i, n - 1)

    for i in range(n - 1, 0, -1):
        a[0], a[i] = a[i], a[0]
        _sift_down(a, 0, i - 1)

    return a


if __name__ == "__main__":
    test = [64, 34, 25, 12, 22, 11, 90]
    print(f"排序前: {test}")
    result = heap_sort(test)
    print(f"排序后: {result}")
    assert result == sorted(test), "测试失败"
    print("堆排序测试通过 ✓")
