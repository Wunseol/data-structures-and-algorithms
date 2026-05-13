"""AVL 树（AVL Tree）

核心操作复杂度：
  insert:  O(log n)
  search:  O(log n)
  inorder: O(n)
  height:  O(1)

对应 C/C++ 源码路径：src/tree/avl_tree/
"""

from __future__ import annotations
from typing import Any


class AVLTree:
    class TreeNode:
        def __init__(self, key: int) -> None:
            self.key = key
            self.left: AVLTree.TreeNode | None = None
            self.right: AVLTree.TreeNode | None = None
            self.height: int = 1

    def __init__(self) -> None:
        self._root: TreeNode | None = None

    def _get_height(self, node: TreeNode | None) -> int:
        if node is None:
            return 0
        return node.height

    def _get_balance(self, node: TreeNode | None) -> int:
        if node is None:
            return 0
        return self._get_height(node.left) - self._get_height(node.right)

    def _update_height(self, node: TreeNode) -> None:
        node.height = 1 + max(self._get_height(node.left), self._get_height(node.right))

    def _rotate_right(self, y: TreeNode) -> TreeNode:
        x = y.left
        t2 = x.right
        x.right = y
        y.left = t2
        self._update_height(y)
        self._update_height(x)
        return x

    def _rotate_left(self, x: TreeNode) -> TreeNode:
        y = x.right
        t2 = y.left
        y.left = x
        x.right = t2
        self._update_height(x)
        self._update_height(y)
        return y

    def insert(self, key: int) -> None:
        self._root = self._insert(self._root, key)

    def _insert(self, node: TreeNode | None, key: int) -> TreeNode:
        if node is None:
            return self.TreeNode(key)
        if key < node.key:
            node.left = self._insert(node.left, key)
        elif key > node.key:
            node.right = self._insert(node.right, key)
        else:
            return node
        self._update_height(node)
        balance = self._get_balance(node)
        if balance > 1 and key < node.left.key:
            return self._rotate_right(node)
        if balance < -1 and key > node.right.key:
            return self._rotate_left(node)
        if balance > 1 and key > node.left.key:
            node.left = self._rotate_left(node.left)
            return self._rotate_right(node)
        if balance < -1 and key < node.right.key:
            node.right = self._rotate_right(node.right)
            return self._rotate_left(node)
        return node

    def search(self, key: int) -> bool:
        return self._search(self._root, key)

    def _search(self, node: TreeNode | None, key: int) -> bool:
        if node is None:
            return False
        if key == node.key:
            return True
        if key < node.key:
            return self._search(node.left, key)
        return self._search(node.right, key)

    def inorder(self) -> list[int]:
        result: list[int] = []
        self._inorder(self._root, result)
        return result

    def _inorder(self, node: TreeNode | None, result: list[int]) -> None:
        if node is None:
            return
        self._inorder(node.left, result)
        result.append(node.key)
        self._inorder(node.right, result)

    def height(self) -> int:
        return self._get_height(self._root)


if __name__ == "__main__":
    avl = AVLTree()
    keys = [10, 20, 30, 40, 50, 25]
    for k in keys:
        avl.insert(k)
    print(f"Inorder: {avl.inorder()}")
    print(f"Height: {avl.height()}")
    print(f"search(25) = {avl.search(25)}")
    print(f"search(99) = {avl.search(99)}")

    avl2 = AVLTree()
    for k in [3, 2, 1]:
        avl2.insert(k)
    print(f"LL rotation inorder: {avl2.inorder()}")
    print(f"LL rotation height: {avl2.height()}")
