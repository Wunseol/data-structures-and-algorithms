"""二叉树（Binary Tree）

核心操作复杂度：
  preorder:     O(n)
  inorder:      O(n)
  postorder:    O(n)
  level_order:  O(n)
  count_leaves: O(n)
  height:       O(n)

对应 C/C++ 源码路径：src/tree/binary_tree/
"""

from __future__ import annotations
from collections import deque
from typing import Any


class BinaryTree:
    class TreeNode:
        def __init__(self, data: Any, left: TreeNode | None = None, right: TreeNode | None = None) -> None:
            self.data = data
            self.left = left
            self.right = right

    def __init__(self, root: TreeNode | None = None) -> None:
        self._root = root

    def preorder(self) -> list[Any]:
        result: list[Any] = []
        self._preorder(self._root, result)
        return result

    def _preorder(self, node: TreeNode | None, result: list[Any]) -> None:
        if node is None:
            return
        result.append(node.data)
        self._preorder(node.left, result)
        self._preorder(node.right, result)

    def inorder(self) -> list[Any]:
        result: list[Any] = []
        self._inorder(self._root, result)
        return result

    def _inorder(self, node: TreeNode | None, result: list[Any]) -> None:
        if node is None:
            return
        self._inorder(node.left, result)
        result.append(node.data)
        self._inorder(node.right, result)

    def postorder(self) -> list[Any]:
        result: list[Any] = []
        self._postorder(self._root, result)
        return result

    def _postorder(self, node: TreeNode | None, result: list[Any]) -> None:
        if node is None:
            return
        self._postorder(node.left, result)
        self._postorder(node.right, result)
        result.append(node.data)

    def level_order(self) -> list[Any]:
        if self._root is None:
            return []
        result: list[Any] = []
        q: deque[BinaryTree.TreeNode] = deque()
        q.append(self._root)
        while q:
            node = q.popleft()
            result.append(node.data)
            if node.left is not None:
                q.append(node.left)
            if node.right is not None:
                q.append(node.right)
        return result

    def count_leaves(self) -> int:
        return self._count_leaves(self._root)

    def _count_leaves(self, node: TreeNode | None) -> int:
        if node is None:
            return 0
        if node.left is None and node.right is None:
            return 1
        return self._count_leaves(node.left) + self._count_leaves(node.right)

    def height(self) -> int:
        return self._height(self._root)

    def _height(self, node: TreeNode | None) -> int:
        if node is None:
            return 0
        return 1 + max(self._height(node.left), self._height(node.right))


if __name__ == "__main__":
    root = BinaryTree.TreeNode(1)
    root.left = BinaryTree.TreeNode(2)
    root.right = BinaryTree.TreeNode(3)
    root.left.left = BinaryTree.TreeNode(4)
    root.left.right = BinaryTree.TreeNode(5)

    bt = BinaryTree(root)
    print(f"Preorder: {bt.preorder()}")
    print(f"Inorder: {bt.inorder()}")
    print(f"Postorder: {bt.postorder()}")
    print(f"Level order: {bt.level_order()}")
    print(f"Leaves: {bt.count_leaves()}")
    print(f"Height: {bt.height()}")
