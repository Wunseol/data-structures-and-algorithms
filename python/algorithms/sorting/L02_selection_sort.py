"""简单选择排序 (Selection Sort)

时间复杂度: 平均 O(n²), 最坏 O(n²), 最好 O(n²)
空间复杂度: O(1)
稳定性: 不稳定
对应 C++ 源码: src/sorting/sequential_list_sorting.cpp -> SelectSort()
"""


def selection_sort(arr: list[int]) -> list[int]:
    a = arr[:]
    n = len(a)
    for i in range(n - 1):
        k = i
        for j in range(i + 1, n):
            if a[j] < a[k]:
                k = j
        if k != i:
            a[i], a[k] = a[k], a[i]
    return a


if __name__ == "__main__":
    test = [64, 34, 25, 12, 22, 11, 90]
    print(f"排序前: {test}")
    result = selection_sort(test)
    print(f"排序后: {result}")
    assert result == sorted(test), "测试失败"
    print("简单选择排序测试通过 ✓")
