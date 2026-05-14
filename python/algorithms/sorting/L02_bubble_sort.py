"""冒泡排序 (Bubble Sort)

时间复杂度: 平均 O(n²), 最坏 O(n²), 最好 O(n)
空间复杂度: O(1)
稳定性: 稳定
对应 C++ 源码: src/sorting/sequential_list_sorting.cpp -> BubbleSort()
"""


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


if __name__ == "__main__":
    test = [64, 34, 25, 12, 22, 11, 90]
    print(f"排序前: {test}")
    result = bubble_sort(test)
    print(f"排序后: {result}")
    assert result == sorted(test), "测试失败"
    print("冒泡排序测试通过 ✓")
