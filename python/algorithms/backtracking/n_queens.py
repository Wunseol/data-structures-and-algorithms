"""
N皇后问题 (N-Queens Problem)
时间复杂度: O(n!)
空间复杂度: O(n) (递归栈 + 皇后位置数组)
对应 C++ 源码: src/advanced_algorithm/backtracking/n_queens.cpp
"""

from __future__ import annotations


def solve_n_queens(n: int) -> list[list[str]]:
    solutions: list[list[str]] = []
    queens: list[int] = [-1] * n

    def is_safe(row: int, col: int) -> bool:
        for i in range(row):
            if queens[i] == col:
                return False
            if abs(queens[i] - col) == abs(i - row):
                return False
        return True

    def backtrack(row: int) -> None:
        if row == n:
            board: list[str] = []
            for i in range(n):
                line = ["."] * n
                line[queens[i]] = "Q"
                board.append("".join(line))
            solutions.append(board)
            return
        for col in range(n):
            if is_safe(row, col):
                queens[row] = col
                backtrack(row + 1)
                queens[row] = -1

    backtrack(0)
    return solutions


if __name__ == "__main__":
    n = 4
    results = solve_n_queens(n)
    print(f"{n}皇后问题共有 {len(results)} 个解:")
    for i, sol in enumerate(results):
        print(f"解 {i + 1}:")
        for row in sol:
            print(f"  {row}")
