"""基数排序 (Radix Sort - LSD)

时间复杂度: O(d * (n + k)), d 为位数, k 为基数
空间复杂度: O(n + k)
稳定性: 稳定
对应 C++ 源码: src/sorting/radix_sort.cpp
"""


def _counting_sort_by_digit(arr: list[int], exp: int) -> list[int]:
    n = len(arr)
    output = [0] * n
    count = [0] * 10

    for i in range(n):
        digit = (arr[i] // exp) % 10
        count[digit] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    for i in range(n - 1, -1, -1):
        digit = (arr[i] // exp) % 10
        output[count[digit] - 1] = arr[i]
        count[digit] -= 1

    return output


def radix_sort(arr: list[int]) -> list[int]:
    if not arr:
        return []

    a = arr[:]
    max_val = max(a)

    exp = 1
    while max_val // exp > 0:
        a = _counting_sort_by_digit(a, exp)
        exp *= 10

    return a


if __name__ == "__main__":
    test = [170, 45, 75, 90, 802, 24, 2, 66]
    print(f"排序前: {test}")
    result = radix_sort(test)
    print(f"排序后: {result}")
    assert result == sorted(test), "测试失败"
    print("基数排序测试通过 ✓")
