"""队列（Queue / CircularQueue / LinkedQueue / Deque / PriorityQueue）

Queue：基于 collections.deque 的链式队列
CircularQueue：基于数组的循环队列
LinkedQueue：基于单链表的链式队列
Deque：双端队列
PriorityQueue：基于最小堆的优先队列

核心操作复杂度：
  enqueue / dequeue:  O(1)   (Queue, CircularQueue, LinkedQueue, Deque)
  enqueue / dequeue:  O(log n) (PriorityQueue)
  front / peek:       O(1)

对应 C/C++ 源码路径：src/queue/
"""

from __future__ import annotations
import heapq
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


class CircularQueue:
    def __init__(self, capacity: int) -> None:
        self._capacity: int = capacity
        self._data: list[Any] = [None] * capacity
        self._front: int = 0
        self._rear: int = 0
        self._size: int = 0

    def enqueue(self, item: Any) -> None:
        if self.is_full():
            raise IndexError("Enqueue to full circular queue")
        self._data[self._rear] = item
        self._rear = (self._rear + 1) % self._capacity
        self._size += 1

    def dequeue(self) -> Any:
        if self.is_empty():
            raise IndexError("Dequeue from empty circular queue")
        removed = self._data[self._front]
        self._data[self._front] = None
        self._front = (self._front + 1) % self._capacity
        self._size -= 1
        return removed

    def front(self) -> Any:
        if self.is_empty():
            raise IndexError("Front from empty circular queue")
        return self._data[self._front]

    def is_empty(self) -> bool:
        return self._size == 0

    def is_full(self) -> bool:
        return self._size == self._capacity

    def __len__(self) -> int:
        return self._size

    def __str__(self) -> str:
        elements: list[Any] = []
        for i in range(self._size):
            elements.append(self._data[(self._front + i) % self._capacity])
        return f"CircularQueue({elements})"


class LinkedQueue:
    class Node:
        def __init__(self, data: Any, next: Node | None = None) -> None:
            self.data = data
            self.next = next

    def __init__(self) -> None:
        self._head: Node | None = None
        self._tail: Node | None = None
        self._size: int = 0

    def enqueue(self, item: Any) -> None:
        new_node = self.Node(item)
        if self.is_empty():
            self._head = new_node
            self._tail = new_node
        else:
            self._tail.next = new_node
            self._tail = new_node
        self._size += 1

    def dequeue(self) -> Any:
        if self.is_empty():
            raise IndexError("Dequeue from empty linked queue")
        removed = self._head.data
        self._head = self._head.next
        if self._head is None:
            self._tail = None
        self._size -= 1
        return removed

    def front(self) -> Any:
        if self.is_empty():
            raise IndexError("Front from empty linked queue")
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
        return f"LinkedQueue([{', '.join(elements)}])"


class Deque:
    def __init__(self) -> None:
        self._data: deque[Any] = deque()

    def add_front(self, item: Any) -> None:
        self._data.appendleft(item)

    def add_rear(self, item: Any) -> None:
        self._data.append(item)

    def remove_front(self) -> Any:
        if self.is_empty():
            raise IndexError("Remove front from empty deque")
        return self._data.popleft()

    def remove_rear(self) -> Any:
        if self.is_empty():
            raise IndexError("Remove rear from empty deque")
        return self._data.pop()

    def front(self) -> Any:
        if self.is_empty():
            raise IndexError("Front from empty deque")
        return self._data[0]

    def rear(self) -> Any:
        if self.is_empty():
            raise IndexError("Rear from empty deque")
        return self._data[-1]

    def is_empty(self) -> bool:
        return len(self._data) == 0

    def __len__(self) -> int:
        return len(self._data)

    def __str__(self) -> str:
        return f"Deque({list(self._data)})"


class PriorityQueue:
    def __init__(self) -> None:
        self._data: list[tuple[int, int, Any]] = []
        self._counter: int = 0

    def enqueue(self, item: Any, priority: int) -> None:
        entry = (priority, self._counter, item)
        self._counter += 1
        heapq.heappush(self._data, entry)

    def dequeue(self) -> Any:
        if self.is_empty():
            raise IndexError("Dequeue from empty priority queue")
        return heapq.heappop(self._data)[2]

    def peek(self) -> Any:
        if self.is_empty():
            raise IndexError("Peek from empty priority queue")
        return self._data[0][2]

    def is_empty(self) -> bool:
        return len(self._data) == 0

    def __len__(self) -> int:
        return len(self._data)

    def __str__(self) -> str:
        items = [(entry[0], entry[2]) for entry in self._data]
        return f"PriorityQueue({items})"


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

    print()

    cq = CircularQueue(5)
    cq.enqueue(1)
    cq.enqueue(2)
    cq.enqueue(3)
    print(f"After enqueue: {cq}")

    print(f"front = {cq.front()}")
    print(f"dequeue = {cq.dequeue()}")
    print(f"After dequeue: {cq}")
    print(f"is_full = {cq.is_full()}")
    print(f"is_empty = {cq.is_empty()}")
    print(f"len = {len(cq)}")

    print()

    lq = LinkedQueue()
    lq.enqueue(1)
    lq.enqueue(2)
    lq.enqueue(3)
    print(f"After enqueue: {lq}")

    print(f"front = {lq.front()}")
    print(f"dequeue = {lq.dequeue()}")
    print(f"After dequeue: {lq}")

    print(f"is_empty = {lq.is_empty()}")
    print(f"len = {len(lq)}")

    print()

    dq = Deque()
    dq.add_rear(1)
    dq.add_rear(2)
    dq.add_front(0)
    print(f"After add: {dq}")

    print(f"front = {dq.front()}")
    print(f"rear = {dq.rear()}")
    print(f"remove_front = {dq.remove_front()}")
    print(f"remove_rear = {dq.remove_rear()}")
    print(f"After remove: {dq}")

    print(f"is_empty = {dq.is_empty()}")
    print(f"len = {len(dq)}")

    print()

    pq = PriorityQueue()
    pq.enqueue("task_c", 3)
    pq.enqueue("task_a", 1)
    pq.enqueue("task_b", 2)
    print(f"After enqueue: {pq}")

    print(f"peek = {pq.peek()}")
    print(f"dequeue = {pq.dequeue()}")
    print(f"dequeue = {pq.dequeue()}")
    print(f"After dequeue: {pq}")

    print(f"is_empty = {pq.is_empty()}")
    print(f"len = {len(pq)}")
