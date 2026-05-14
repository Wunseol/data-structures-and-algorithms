"""二叉搜索树（Binary Search Tree）

核心操作复杂度：
  insert:  O(h) 平均 O(log n)，最坏 O(n)
  search:  O(h) 平均 O(log n)，最坏 O(n)
  delete:  O(h) 平均 O(log n)，最坏 O(n)
  inorder: O(n)

对应 C/C++ 源码路径：src/tree/binary_search_tree/
"""

from __future__ import annotations
from typing import Any


class BST:
    class TreeNode:
        def __init__(self, key: int) -> None:
            self.key = key
            self.left: BST.TreeNode | None = None
            self.right: BST.TreeNode | None = None

    def __init__(self) -> None:
        self._root: TreeNode | None = None

    def insert(self, key: int) -> None:
        self._root = self._insert(self._root, key)

    def _insert(self, node: TreeNode | None, key: int) -> TreeNode:
        if node is None:
            return self.TreeNode(key)
        if key < node.key:
            node.left = self._insert(node.left, key)
        elif key > node.key:
            node.right = self._insert(node.right, key)
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

    def delete(self, key: int) -> None:
        self._root = self._delete(self._root, key)

    def _delete(self, node: TreeNode | None, key: int) -> TreeNode | None:
        if node is None:
            return None
        if key < node.key:
            node.left = self._delete(node.left, key)
        elif key > node.key:
            node.right = self._delete(node.right, key)
        else:
            if node.left is None:
                return node.right
            if node.right is None:
                return node.left
            successor = node.right
            while successor.left is not None:
                successor = successor.left
            node.key = successor.key
            node.right = self._delete(node.right, successor.key)
        return node

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


if __name__ == "__main__":
    bst = BST()
    bst.insert(5)
    bst.insert(3)
    bst.insert(7)
    bst.insert(1)
    bst.insert(4)
    print(f"Inorder: {bst.inorder()}")

    print(f"search(3) = {bst.search(3)}")
    print(f"search(6) = {bst.search(6)}")

    bst.delete(3)
    print(f"After delete(3): {bst.inorder()}")

    bst.delete(5)
    print(f"After delete(5): {bst.inorder()}")
