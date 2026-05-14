"""字典树 / 前缀树（Trie）

核心操作复杂度：
  insert:      O(m)  m 为字符串长度
  search:      O(m)
  starts_with: O(m)

对应 C/C++ 源码路径：src/tree/trie/
"""

from __future__ import annotations


class Trie:
    class TrieNode:
        def __init__(self) -> None:
            self.children: dict[str, Trie.TrieNode] = {}
            self.is_end: bool = False

    def __init__(self) -> None:
        self._root = self.TrieNode()

    def insert(self, word: str) -> None:
        node = self._root
        for ch in word:
            if ch not in node.children:
                node.children[ch] = self.TrieNode()
            node = node.children[ch]
        node.is_end = True

    def search(self, word: str) -> bool:
        node = self._find(word)
        return node is not None and node.is_end

    def starts_with(self, prefix: str) -> bool:
        return self._find(prefix) is not None

    def _find(self, prefix: str) -> TrieNode | None:
        node = self._root
        for ch in prefix:
            if ch not in node.children:
                return None
            node = node.children[ch]
        return node


if __name__ == "__main__":
    trie = Trie()
    trie.insert("apple")
    trie.insert("app")
    trie.insert("application")

    print(f"search('apple') = {trie.search('apple')}")
    print(f"search('app') = {trie.search('app')}")
    print(f"search('appl') = {trie.search('appl')}")
    print(f"starts_with('app') = {trie.starts_with('app')}")
    print(f"starts_with('ban') = {trie.starts_with('ban')}")
