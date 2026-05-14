"""双向链表（Doubly Linked List）

核心操作复杂度：
  append:   O(n)
  insert:   O(n)
  delete:   O(n)
  forward:  O(n)
  backward: O(n)

对应 C/C++ 源码路径：src/linear_list/doubly_linked_list/
"""

from __future__ import annotations
from typing import Any


class DoublyLinkedList:
    class Node:
        def __init__(self, data: Any, prev: Node | None = None, next: Node | None = None) -> None:
            self.data = data
            self.prev = prev
            self.next = next

    def __init__(self) -> None:
        self._head: Node | None = None
        self._tail: Node | None = None
        self._size: int = 0

    def append(self, item: Any) -> None:
        new_node = self.Node(item, self._tail, None)
        if self._head is None:
            self._head = new_node
            self._tail = new_node
        else:
            self._tail.next = new_node
            self._tail = new_node
        self._size += 1

    def insert(self, index: int, item: Any) -> None:
        if index < 0 or index > self._size:
            raise IndexError(f"Index {index} out of range")
        if index == self._size:
            self.append(item)
            return
        new_node = self.Node(item)
        if index == 0:
            new_node.next = self._head
            self._head.prev = new_node
            self._head = new_node
        else:
            current = self._head
            for _ in range(index):
                current = current.next
            new_node.prev = current.prev
            new_node.next = current
            current.prev.next = new_node
            current.prev = new_node
        self._size += 1

    def delete(self, index: int) -> Any:
        if index < 0 or index >= self._size:
            raise IndexError(f"Index {index} out of range")
        current = self._head
        for _ in range(index):
            current = current.next
        if current.prev is not None:
            current.prev.next = current.next
        else:
            self._head = current.next
        if current.next is not None:
            current.next.prev = current.prev
        else:
            self._tail = current.prev
        self._size -= 1
        return current.data

    def forward(self) -> list[Any]:
        result: list[Any] = []
        current = self._head
        while current is not None:
            result.append(current.data)
            current = current.next
        return result

    def backward(self) -> list[Any]:
        result: list[Any] = []
        current = self._tail
        while current is not None:
            result.append(current.data)
            current = current.prev
        return result

    def __len__(self) -> int:
        return self._size

    def __str__(self) -> str:
        elements = [str(x) for x in self.forward()]
        return "<->".join(elements)


if __name__ == "__main__":
    dll = DoublyLinkedList()
    dll.append(1)
    dll.append(2)
    dll.append(3)
    print(f"After append: {dll}")

    dll.insert(1, 10)
    print(f"After insert(1, 10): {dll}")

    dll.delete(2)
    print(f"After delete(2): {dll}")

    print(f"Forward: {dll.forward()}")
    print(f"Backward: {dll.backward()}")
    print(f"len = {len(dll)}")
