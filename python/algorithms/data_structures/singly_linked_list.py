"""单链表（Singly Linked List）

核心操作复杂度：
  append:  O(n)
  insert:  O(n)
  delete:  O(n)
  find:    O(n)
  reverse: O(n)

对应 C/C++ 源码路径：src/linear_list/singly_linked_list/
"""

from __future__ import annotations
from typing import Any, Iterator


class SinglyLinkedList:
    class Node:
        def __init__(self, data: Any, next: Node | None = None) -> None:
            self.data = data
            self.next = next

    def __init__(self) -> None:
        self._head: Node | None = None
        self._size: int = 0

    def append(self, item: Any) -> None:
        new_node = self.Node(item)
        if self._head is None:
            self._head = new_node
        else:
            current = self._head
            while current.next is not None:
                current = current.next
            current.next = new_node
        self._size += 1

    def insert(self, index: int, item: Any) -> None:
        if index < 0 or index > self._size:
            raise IndexError(f"Index {index} out of range")
        new_node = self.Node(item)
        if index == 0:
            new_node.next = self._head
            self._head = new_node
        else:
            current = self._head
            for _ in range(index - 1):
                current = current.next
            new_node.next = current.next
            current.next = new_node
        self._size += 1

    def delete(self, index: int) -> Any:
        if index < 0 or index >= self._size:
            raise IndexError(f"Index {index} out of range")
        if index == 0:
            removed = self._head.data
            self._head = self._head.next
        else:
            current = self._head
            for _ in range(index - 1):
                current = current.next
            removed = current.next.data
            current.next = current.next.next
        self._size -= 1
        return removed

    def find(self, item: Any) -> int:
        current = self._head
        index = 0
        while current is not None:
            if current.data == item:
                return index
            current = current.next
            index += 1
        return -1

    def reverse(self) -> None:
        prev = None
        current = self._head
        while current is not None:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node
        self._head = prev

    def __iter__(self) -> Iterator[Any]:
        current = self._head
        while current is not None:
            yield current.data
            current = current.next

    def __len__(self) -> int:
        return self._size

    def __str__(self) -> str:
        elements = [str(data) for data in self]
        return "->".join(elements)


if __name__ == "__main__":
    sll = SinglyLinkedList()
    sll.append(1)
    sll.append(2)
    sll.append(3)
    print(f"After append: {sll}")

    sll.insert(1, 10)
    print(f"After insert(1, 10): {sll}")

    print(f"find(10) = {sll.find(10)}")
    print(f"find(99) = {sll.find(99)}")

    sll.delete(1)
    print(f"After delete(1): {sll}")

    sll.reverse()
    print(f"After reverse: {sll}")

    print(f"Iteration: {[x for x in sll]}")
    print(f"len = {len(sll)}")
