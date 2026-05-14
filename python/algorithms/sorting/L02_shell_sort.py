"""希尔排序 (Shell Sort)

时间复杂度: 平均 O(n^1.3), 最坏 O(n²), 最好 O(n)
空间复杂度: O(1)
稳定性: 不稳定
对应 C++ 源码: src/sorting/sequential_list_sorting.cpp -> ShellSort()
"""


def shell_sort(arr: list[int], gaps: list[int] | None = None) -> list[int]:
    a = arr[:]
    n = len(a)
    if n <= 1:
        return a
    if gaps is None:
        gaps = []
        g = n // 2
        while g > 0:
            gaps.append(g)
            g //= 2
    for dk in gaps:
        for i in range(dk, n):
            if a[i] < a[i - dk]:
                temp = a[i]
                j = i - dk
                while j >= 0 and a[j] > temp:
                    a[j + dk] = a[j]
                    j -= dk
                a[j + dk] = temp
    return a


if __name__ == "__main__":
    test = [64, 34, 25, 12, 22, 11, 90]
    print(f"排序前: {test}")
    result = shell_sort(test)
    print(f"排序后: {result}")
    assert result == sorted(test), "测试失败"

    result2 = shell_sort(test, gaps=[5, 3, 1])
    assert result2 == sorted(test), "自定义增量测试失败"
    print("希尔排序测试通过 ✓")
