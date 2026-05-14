"""栈（Stack / LinkedStack）

Stack：基于列表的顺序栈
LinkedStack：基于单链表的链式栈

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


class LinkedStack:
    class Node:
        def __init__(self, data: Any, next: Node | None = None) -> None:
            self.data = data
            self.next = next

    def __init__(self) -> None:
        self._head: Node | None = None
        self._size: int = 0

    def push(self, item: Any) -> None:
        self._head = self.Node(item, self._head)
        self._size += 1

    def pop(self) -> Any:
        if self.is_empty():
            raise IndexError("Pop from empty stack")
        removed = self._head.data
        self._head = self._head.next
        self._size -= 1
        return removed

    def peek(self) -> Any:
        if self.is_empty():
            raise IndexError("Peek from empty stack")
        return self._head.data

    def is_empty(self) -> bool:
        return self._size == 0

    def __len__(self) -> int:
        return self._size

    def __str__(self) -> str:
        elements: list[str] = []
        current = self._head
        while current is not None:
            elements.append(str(current.data))
            current = current.next
        return f"LinkedStack([{', '.join(elements)}])"


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

    print()

    ls = LinkedStack()
    ls.push(1)
    ls.push(2)
    ls.push(3)
    print(f"After push: {ls}")

    print(f"peek = {ls.peek()}")
    print(f"pop = {ls.pop()}")
    print(f"After pop: {ls}")

    print(f"is_empty = {ls.is_empty()}")
    print(f"len = {len(ls)}")
