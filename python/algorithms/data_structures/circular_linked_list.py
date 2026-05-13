"""循环链表（Circular Linked List）

核心操作复杂度：
  append:   O(n)
  insert:   O(n)
  delete:   O(n)
  traverse: O(n)

对应 C/C++ 源码路径：src/linear_list/circular_linked_list/
"""

from __future__ import annotations
from typing import Any


class CircularLinkedList:
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
            new_node.next = self._head
        else:
            current = self._head
            while current.next is not self._head:
                current = current.next
            current.next = new_node
            new_node.next = self._head
        self._size += 1

    def insert(self, index: int, item: Any) -> None:
        if index < 0 or index > self._size:
            raise IndexError(f"Index {index} out of range")
        new_node = self.Node(item)
        if self._head is None:
            self._head = new_node
            new_node.next = self._head
        elif index == 0:
            tail = self._head
            while tail.next is not self._head:
                tail = tail.next
            new_node.next = self._head
            tail.next = new_node
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
        if self._size == 1:
            removed = self._head.data
            self._head = None
        elif index == 0:
            tail = self._head
            while tail.next is not self._head:
                tail = tail.next
            removed = self._head.data
            tail.next = self._head.next
            self._head = self._head.next
        else:
            current = self._head
            for _ in range(index - 1):
                current = current.next
            removed = current.next.data
            current.next = current.next.next
        self._size -= 1
        return removed

    def traverse(self) -> list[Any]:
        if self._head is None:
            return []
        result: list[Any] = []
        current = self._head
        while True:
            result.append(current.data)
            current = current.next
            if current is self._head:
                break
        return result

    def __len__(self) -> int:
        return self._size

    def __str__(self) -> str:
        elements = [str(x) for x in self.traverse()]
        return "->".join(elements) + "->(head)"


if __name__ == "__main__":
    cll = CircularLinkedList()
    cll.append(1)
    cll.append(2)
    cll.append(3)
    print(f"After append: {cll}")

    cll.insert(1, 10)
    print(f"After insert(1, 10): {cll}")

    cll.delete(1)
    print(f"After delete(1): {cll}")

    print(f"Traverse: {cll.traverse()}")
    print(f"len = {len(cll)}")
