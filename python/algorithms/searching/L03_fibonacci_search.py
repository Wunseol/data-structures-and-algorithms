"""斐波那契查找 (Fibonacci Search)

时间复杂度: O(log n)
空间复杂度: O(1)
对应 C++ 源码: src/searching/fibonacci_search.cpp
"""


def fibonacci_search(arr: list[int], target: int) -> int:
    n = len(arr)
    if n == 0:
        return -1

    fib2 = 0
    fib1 = 1
    fib_m = fib2 + fib1

    while fib_m < n:
        fib2 = fib1
        fib1 = fib_m
        fib_m = fib2 + fib1

    offset = -1

    while fib_m > 1:
        i = min(offset + fib2, n - 1)

        if arr[i] < target:
            fib_m = fib1
            fib1 = fib2
            fib2 = fib_m - fib1
            offset = i
        elif arr[i] > target:
            fib_m = fib2
            fib1 = fib1 - fib2
            fib2 = fib_m - fib1
        else:
            return i

    if fib1 == 1 and offset + 1 < n and arr[offset + 1] == target:
        return offset + 1

    return -1


if __name__ == "__main__":
    arr = [10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100]
    print(f"数组: {arr}")

    idx = fibonacci_search(arr, 85)
    print(f"斐波那契查找 85: 索引 {idx}")
    assert idx == 8, "测试失败"

    idx = fibonacci_search(arr, 10)
    print(f"斐波那契查找 10: 索引 {idx}")
    assert idx == 0, "首元素测试失败"

    idx = fibonacci_search(arr, 100)
    print(f"斐波那契查找 100: 索引 {idx}")
    assert idx == 10, "末元素测试失败"

    idx = fibonacci_search(arr, 55)
    print(f"斐波那契查找 55: 索引 {idx}")
    assert idx == -1, "未找到测试失败"

    print("斐波那契查找测试通过 ✓")
