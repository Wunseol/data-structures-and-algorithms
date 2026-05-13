"""栈（Stack）

核心操作复杂度：
  push:     O(1)
  pop:      O(1)
  peek:     O(1)
  is_empty: O(1)

对应 C/C++ 源码路径：src/stack/
"""

from __future__ import annotations
from typing import Any


class Stack:
    def __init__(self) -> None:
        self._data: list[Any] = []

    def push(self, item: Any) -> None:
        self._data.append(item)

    def pop(self) -> Any:
        if self.is_empty():
            raise IndexError("Pop from empty stack")
        return self._data.pop()

    def peek(self) -> Any:
        if self.is_empty():
            raise IndexError("Peek from empty stack")
        return self._data[-1]

    def is_empty(self) -> bool:
        return len(self._data) == 0

    def __len__(self) -> int:
        return len(self._data)

    def __str__(self) -> str:
        return f"Stack({self._data})"


if __name__ == "__main__":
    s = Stack()
    s.push(1)
    s.push(2)
    s.push(3)
    print(f"After push: {s}")

    print(f"peek = {s.peek()}")
    print(f"pop = {s.pop()}")
    print(f"After pop: {s}")

    print(f"is_empty = {s.is_empty()}")
    print(f"len = {len(s)}")
