"""快速排序 (Quick Sort)

时间复杂度: 平均 O(n log n), 最坏 O(n²), 最好 O(n log n)
空间复杂度: O(log n)
稳定性: 不稳定
对应 C++ 源码: src/sorting/sequential_list_sorting.cpp -> QuickSort()
"""


def _partition(arr: list[int], low: int, high: int) -> int:
    mid = (low + high) // 2
    arr[low], arr[mid] = arr[mid], arr[low]
    pivot = arr[low]
    i = low
    for j in range(low + 1, high + 1):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[low], arr[i] = arr[i], arr[low]
    return i


def quick_sort_inplace(arr: list[int], low: int, high: int) -> None:
    if low < high:
        pivot_loc = _partition(arr, low, high)
        quick_sort_inplace(arr, low, pivot_loc - 1)
        quick_sort_inplace(arr, pivot_loc + 1, high)


def quick_sort(arr: list[int]) -> list[int]:
    a = arr[:]
    if len(a) <= 1:
        return a
    quick_sort_inplace(a, 0, len(a) - 1)
    return a


if __name__ == "__main__":
    test = [64, 34, 25, 12, 22, 11, 90]
    print(f"排序前: {test}")
    result = quick_sort(test)
    print(f"排序后: {result}")
    assert result == sorted(test), "测试失败"

    a = [3, 1, 4, 1, 5, 9, 2, 6]
    quick_sort_inplace(a, 0, len(a) - 1)
    assert a == sorted([3, 1, 4, 1, 5, 9, 2, 6]), "原地排序测试失败"
    print("快速排序测试通过 ✓")
