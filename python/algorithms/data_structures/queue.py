"""队列（Queue）

核心操作复杂度：
  enqueue:  O(1)
  dequeue:  O(1)
  front:    O(1)
  is_empty: O(1)

对应 C/C++ 源码路径：src/queue/
"""

from __future__ import annotations
from collections import deque
from typing import Any


class Queue:
    def __init__(self) -> None:
        self._data: deque[Any] = deque()

    def enqueue(self, item: Any) -> None:
        self._data.append(item)

    def dequeue(self) -> Any:
        if self.is_empty():
            raise IndexError("Dequeue from empty queue")
        return self._data.popleft()

    def front(self) -> Any:
        if self.is_empty():
            raise IndexError("Front from empty queue")
        return self._data[0]

    def is_empty(self) -> bool:
        return len(self._data) == 0

    def __len__(self) -> int:
        return len(self._data)

    def __str__(self) -> str:
        return f"Queue({list(self._data)})"


if __name__ == "__main__":
    q = Queue()
    q.enqueue(1)
    q.enqueue(2)
    q.enqueue(3)
    print(f"After enqueue: {q}")

    print(f"front = {q.front()}")
    print(f"dequeue = {q.dequeue()}")
    print(f"After dequeue: {q}")

    print(f"is_empty = {q.is_empty()}")
    print(f"len = {len(q)}")
