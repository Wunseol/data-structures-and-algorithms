"""爬楼梯问题

时间复杂度: O(n)
空间复杂度: O(1)

对应 C++ 源码: src/advanced_algorithm/dynamic_programming/climbing_stairs.cpp
"""


def climb_stairs(n: int) -> int:
    if n <= 2:
        return n
    prev2 = 1
    prev1 = 2
    for _ in range(3, n + 1):
        curr = prev1 + prev2
        prev2 = prev1
        prev1 = curr
    return prev1


if __name__ == "__main__":
    for i in range(1, 8):
        print(f"爬 {i} 阶楼梯的方法数: {climb_stairs(i)}")

    assert climb_stairs(1) == 1
    assert climb_stairs(2) == 2
    assert climb_stairs(3) == 3
    assert climb_stairs(4) == 5
    assert climb_stairs(5) == 8
    assert climb_stairs(10) == 89
