"""跳表（Skip List）

核心操作复杂度：
  insert:  O(log n) 期望
  search:  O(log n) 期望
  delete:  O(log n) 期望

对应 C/C++ 源码路径：src/linear_list/skip_list/
"""

from __future__ import annotations
import random
from typing import Any


class SkipList:
    MAX_LEVEL = 16
    PROBABILITY = 0.5

    class SkipNode:
        def __init__(self, key: int, value: Any, level: int) -> None:
            self.key = key
            self.value = value
            self.forward: list[SkipList.SkipNode | None] = [None] * level

    def __init__(self) -> None:
        self._header = self.SkipNode(0, None, self.MAX_LEVEL)
        self._level = 1
        self._size = 0

    def _random_level(self) -> int:
        level = 1
        while random.random() < self.PROBABILITY and level < self.MAX_LEVEL:
            level += 1
        return level

    def insert(self, key: int, value: Any) -> None:
        update: list[SkipList.SkipNode | None] = [None] * self.MAX_LEVEL
        current = self._header
        for i in range(self._level - 1, -1, -1):
            while current.forward[i] is not None and current.forward[i].key < key:
                current = current.forward[i]
            update[i] = current
        current = current.forward[0]
        if current is not None and current.key == key:
            current.value = value
            return
        new_level = self._random_level()
        if new_level > self._level:
            for i in range(self._level, new_level):
                update[i] = self._header
            self._level = new_level
        new_node = self.SkipNode(key, value, new_level)
        for i in range(new_level):
            new_node.forward[i] = update[i].forward[i]
            update[i].forward[i] = new_node
        self._size += 1

    def search(self, key: int) -> Any | None:
        current = self._header
        for i in range(self._level - 1, -1, -1):
            while current.forward[i] is not None and current.forward[i].key < key:
                current = current.forward[i]
        current = current.forward[0]
        if current is not None and current.key == key:
            return current.value
        return None

    def delete(self, key: int) -> bool:
        update: list[SkipList.SkipNode | None] = [None] * self.MAX_LEVEL
        current = self._header
        for i in range(self._level - 1, -1, -1):
            while current.forward[i] is not None and current.forward[i].key < key:
                current = current.forward[i]
            update[i] = current
        current = current.forward[0]
        if current is None or current.key != key:
            return False
        for i in range(self._level):
            if update[i].forward[i] is not current:
                break
            update[i].forward[i] = current.forward[i]
        while self._level > 1 and self._header.forward[self._level - 1] is None:
            self._level -= 1
        self._size -= 1
        return True

    def __len__(self) -> int:
        return self._size

    def __str__(self) -> str:
        result: list[str] = []
        current = self._header.forward[0]
        while current is not None:
            result.append(f"{current.key}:{current.value}")
            current = current.forward[0]
        return "{" + ", ".join(result) + "}"


if __name__ == "__main__":
    sl = SkipList()
    sl.insert(3, "three")
    sl.insert(1, "one")
    sl.insert(4, "four")
    sl.insert(2, "two")
    print(f"After insert: {sl}")

    print(f"search(2) = {sl.search(2)}")
    print(f"search(5) = {sl.search(5)}")

    sl.delete(3)
    print(f"After delete(3): {sl}")

    sl.insert(2, "TWO")
    print(f"After update key=2: {sl}")

    print(f"len = {len(sl)}")
