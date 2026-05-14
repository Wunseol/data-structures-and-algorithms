import sys
import os
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from algorithms.data_structures.L01_sequential_list import SequentialList
from algorithms.data_structures.L04_singly_linked_list import SinglyLinkedList
from algorithms.data_structures.L07_stack import Stack, LinkedStack
from algorithms.data_structures.L08_queue import Queue, CircularQueue, LinkedQueue, Deque, PriorityQueue
from algorithms.data_structures.L10_binary_tree import BinaryTree
from algorithms.data_structures.L11_binary_search_tree import BST
from algorithms.data_structures.L12_avl_tree import AVLTree
from algorithms.data_structures.L14_trie import Trie
from algorithms.data_structures.L20_lru_cache import LRUCache
from algorithms.data_structures.L19_bloom_filter import BloomFilter
from algorithms.data_structures.L16_segment_tree import SegmentTree
from algorithms.data_structures.L17_fenwick_tree import FenwickTree
from algorithms.data_structures.L23_union_find import UnionFind
from algorithms.data_structures.L18_hash_table_chaining import HashTableChaining
from algorithms.data_structures.L15_max_heap import MaxHeap
from algorithms.data_structures.L15_min_heap import MinHeap


class TestSequentialList(unittest.TestCase):
    def test_append_insert_find(self):
        sl = SequentialList()
        sl.append(10)
        sl.append(20)
        sl.append(30)
        self.assertEqual(len(sl), 3)
        self.assertEqual(sl.find(20), 1)
        self.assertEqual(sl.find(99), -1)
        sl.insert(1, 15)
        self.assertEqual(sl.find(15), 1)
        self.assertEqual(sl.find(20), 2)
        self.assertEqual(sl.get(1), 15)

    def test_delete_and_boundary(self):
        sl = SequentialList()
        sl.append(1)
        sl.append(2)
        sl.append(3)
        removed = sl.delete(1)
        self.assertEqual(removed, 2)
        self.assertEqual(len(sl), 2)
        self.assertEqual(sl.find(1), 0)
        self.assertEqual(sl.find(3), 1)
        sl.delete(0)
        sl.delete(0)
        self.assertEqual(len(sl), 0)

    def test_index_error(self):
        sl = SequentialList()
        with self.assertRaises(IndexError):
            sl.insert(5, 10)
        with self.assertRaises(IndexError):
            sl.delete(0)
        with self.assertRaises(IndexError):
            sl.get(0)

    def test_empty_list(self):
        sl = SequentialList()
        self.assertEqual(len(sl), 0)
        self.assertEqual(sl.find(1), -1)


class TestSinglyLinkedList(unittest.TestCase):
    def test_append_and_find(self):
        sll = SinglyLinkedList()
        sll.append(1)
        sll.append(2)
        sll.append(3)
        self.assertEqual(sll.find(1), 0)
        self.assertEqual(sll.find(3), 2)
        self.assertEqual(sll.find(99), -1)
        self.assertEqual(len(sll), 3)

    def test_insert_and_delete(self):
        sll = SinglyLinkedList()
        sll.append(1)
        sll.append(3)
        sll.insert(1, 2)
        self.assertEqual(sll.find(2), 1)
        removed = sll.delete(1)
        self.assertEqual(removed, 2)
        self.assertEqual(len(sll), 2)

    def test_reverse(self):
        sll = SinglyLinkedList()
        sll.append(1)
        sll.append(2)
        sll.append(3)
        sll.reverse()
        self.assertEqual(list(sll), [3, 2, 1])

    def test_index_error(self):
        sll = SinglyLinkedList()
        with self.assertRaises(IndexError):
            sll.insert(5, 10)
        with self.assertRaises(IndexError):
            sll.delete(0)


class TestStack(unittest.TestCase):
    def test_push_pop_peek(self):
        s = Stack()
        s.push(1)
        s.push(2)
        s.push(3)
        self.assertEqual(s.peek(), 3)
        self.assertEqual(s.pop(), 3)
        self.assertEqual(s.pop(), 2)
        self.assertEqual(len(s), 1)

    def test_is_empty(self):
        s = Stack()
        self.assertTrue(s.is_empty())
        s.push(1)
        self.assertFalse(s.is_empty())

    def test_index_error_on_empty_pop(self):
        s = Stack()
        with self.assertRaises(IndexError):
            s.pop()
        with self.assertRaises(IndexError):
            s.peek()


class TestLinkedStack(unittest.TestCase):
    def test_push_pop_peek(self):
        ls = LinkedStack()
        ls.push(1)
        ls.push(2)
        ls.push(3)
        self.assertEqual(ls.peek(), 3)
        self.assertEqual(ls.pop(), 3)
        self.assertEqual(ls.pop(), 2)
        self.assertEqual(len(ls), 1)

    def test_is_empty(self):
        ls = LinkedStack()
        self.assertTrue(ls.is_empty())
        ls.push(1)
        self.assertFalse(ls.is_empty())

    def test_index_error_on_empty_pop(self):
        ls = LinkedStack()
        with self.assertRaises(IndexError):
            ls.pop()
        with self.assertRaises(IndexError):
            ls.peek()


class TestQueue(unittest.TestCase):
    def test_enqueue_dequeue_front(self):
        q = Queue()
        q.enqueue(1)
        q.enqueue(2)
        q.enqueue(3)
        self.assertEqual(q.front(), 1)
        self.assertEqual(q.dequeue(), 1)
        self.assertEqual(q.dequeue(), 2)
        self.assertEqual(len(q), 1)

    def test_is_empty(self):
        q = Queue()
        self.assertTrue(q.is_empty())
        q.enqueue(1)
        self.assertFalse(q.is_empty())

    def test_index_error_on_empty_dequeue(self):
        q = Queue()
        with self.assertRaises(IndexError):
            q.dequeue()
        with self.assertRaises(IndexError):
            q.front()


class TestCircularQueue(unittest.TestCase):
    def test_enqueue_dequeue_front(self):
        cq = CircularQueue(3)
        cq.enqueue(1)
        cq.enqueue(2)
        cq.enqueue(3)
        self.assertTrue(cq.is_full())
        self.assertEqual(cq.front(), 1)
        self.assertEqual(cq.dequeue(), 1)
        self.assertFalse(cq.is_full())

    def test_is_full_and_empty(self):
        cq = CircularQueue(2)
        self.assertTrue(cq.is_empty())
        cq.enqueue(1)
        cq.enqueue(2)
        self.assertTrue(cq.is_full())

    def test_full_queue_rejection(self):
        cq = CircularQueue(2)
        cq.enqueue(1)
        cq.enqueue(2)
        with self.assertRaises(IndexError):
            cq.enqueue(3)

    def test_empty_dequeue_error(self):
        cq = CircularQueue(2)
        with self.assertRaises(IndexError):
            cq.dequeue()
        with self.assertRaises(IndexError):
            cq.front()


class TestLinkedQueue(unittest.TestCase):
    def test_enqueue_dequeue_front(self):
        lq = LinkedQueue()
        lq.enqueue(1)
        lq.enqueue(2)
        lq.enqueue(3)
        self.assertEqual(lq.front(), 1)
        self.assertEqual(lq.dequeue(), 1)
        self.assertEqual(lq.dequeue(), 2)
        self.assertEqual(len(lq), 1)

    def test_is_empty(self):
        lq = LinkedQueue()
        self.assertTrue(lq.is_empty())
        lq.enqueue(1)
        self.assertFalse(lq.is_empty())

    def test_index_error_on_empty(self):
        lq = LinkedQueue()
        with self.assertRaises(IndexError):
            lq.dequeue()
        with self.assertRaises(IndexError):
            lq.front()


class TestDeque(unittest.TestCase):
    def test_add_and_remove(self):
        d = Deque()
        d.add_front(2)
        d.add_rear(3)
        d.add_front(1)
        self.assertEqual(d.front(), 1)
        self.assertEqual(d.rear(), 3)
        self.assertEqual(d.remove_front(), 1)
        self.assertEqual(d.remove_rear(), 3)
        self.assertEqual(len(d), 1)

    def test_single_element(self):
        d = Deque()
        d.add_rear(42)
        self.assertEqual(d.front(), 42)
        self.assertEqual(d.rear(), 42)
        self.assertEqual(d.remove_front(), 42)
        self.assertTrue(d.is_empty())

    def test_index_error_on_empty(self):
        d = Deque()
        with self.assertRaises(IndexError):
            d.remove_front()
        with self.assertRaises(IndexError):
            d.remove_rear()
        with self.assertRaises(IndexError):
            d.front()
        with self.assertRaises(IndexError):
            d.rear()


class TestPriorityQueue(unittest.TestCase):
    def test_priority_order(self):
        pq = PriorityQueue()
        pq.enqueue("c", 3)
        pq.enqueue("a", 1)
        pq.enqueue("b", 2)
        self.assertEqual(pq.dequeue(), "a")
        self.assertEqual(pq.dequeue(), "b")
        self.assertEqual(pq.dequeue(), "c")

    def test_peek(self):
        pq = PriorityQueue()
        pq.enqueue("low", 5)
        pq.enqueue("high", 1)
        self.assertEqual(pq.peek(), "high")

    def test_empty_dequeue(self):
        pq = PriorityQueue()
        with self.assertRaises(IndexError):
            pq.dequeue()
        with self.assertRaises(IndexError):
            pq.peek()


class TestBinaryTree(unittest.TestCase):
    def _build_tree(self):
        root = BinaryTree.TreeNode(1)
        root.left = BinaryTree.TreeNode(2)
        root.right = BinaryTree.TreeNode(3)
        root.left.left = BinaryTree.TreeNode(4)
        root.left.right = BinaryTree.TreeNode(5)
        return BinaryTree(root)

    def test_traversals(self):
        bt = self._build_tree()
        self.assertEqual(bt.preorder(), [1, 2, 4, 5, 3])
        self.assertEqual(bt.inorder(), [4, 2, 5, 1, 3])
        self.assertEqual(bt.postorder(), [4, 5, 2, 3, 1])
        self.assertEqual(bt.level_order(), [1, 2, 3, 4, 5])

    def test_count_leaves_and_height(self):
        bt = self._build_tree()
        self.assertEqual(bt.count_leaves(), 3)
        self.assertEqual(bt.height(), 3)

    def test_empty_tree(self):
        bt = BinaryTree()
        self.assertEqual(bt.preorder(), [])
        self.assertEqual(bt.inorder(), [])
        self.assertEqual(bt.postorder(), [])
        self.assertEqual(bt.level_order(), [])
        self.assertEqual(bt.count_leaves(), 0)
        self.assertEqual(bt.height(), 0)


class TestBST(unittest.TestCase):
    def test_insert_and_search(self):
        bst = BST()
        bst.insert(5)
        bst.insert(3)
        bst.insert(7)
        bst.insert(1)
        bst.insert(4)
        self.assertTrue(bst.search(5))
        self.assertTrue(bst.search(1))
        self.assertFalse(bst.search(6))

    def test_delete(self):
        bst = BST()
        for k in [5, 3, 7, 1, 4]:
            bst.insert(k)
        bst.delete(3)
        self.assertFalse(bst.search(3))
        self.assertEqual(bst.inorder(), [1, 4, 5, 7])

    def test_inorder(self):
        bst = BST()
        for k in [5, 3, 7, 1, 4]:
            bst.insert(k)
        self.assertEqual(bst.inorder(), [1, 3, 4, 5, 7])

    def test_empty_bst(self):
        bst = BST()
        self.assertFalse(bst.search(1))
        self.assertEqual(bst.inorder(), [])


class TestAVLTree(unittest.TestCase):
    def test_insert_and_search(self):
        avl = AVLTree()
        for k in [10, 20, 30, 40, 50, 25]:
            avl.insert(k)
        self.assertTrue(avl.search(25))
        self.assertTrue(avl.search(10))
        self.assertFalse(avl.search(99))

    def test_inorder(self):
        avl = AVLTree()
        for k in [10, 20, 30, 40, 50, 25]:
            avl.insert(k)
        self.assertEqual(avl.inorder(), [10, 20, 25, 30, 40, 50])

    def test_balance_after_insert(self):
        avl = AVLTree()
        for k in [3, 2, 1]:
            avl.insert(k)
        self.assertLessEqual(avl.height(), 2)
        self.assertEqual(avl.inorder(), [1, 2, 3])

    def test_sequential_insert_balance(self):
        avl = AVLTree()
        for k in range(1, 16):
            avl.insert(k)
        import math
        self.assertLessEqual(avl.height(), 1.44 * math.log2(16))


class TestTrie(unittest.TestCase):
    def test_insert_and_search(self):
        t = Trie()
        t.insert("apple")
        t.insert("app")
        self.assertTrue(t.search("apple"))
        self.assertTrue(t.search("app"))
        self.assertFalse(t.search("appl"))

    def test_starts_with(self):
        t = Trie()
        t.insert("apple")
        t.insert("application")
        self.assertTrue(t.starts_with("app"))
        self.assertFalse(t.starts_with("ban"))

    def test_empty_string(self):
        t = Trie()
        self.assertFalse(t.search(""))
        self.assertTrue(t.starts_with(""))


class TestLRUCache(unittest.TestCase):
    def test_get_and_put(self):
        cache = LRUCache(2)
        cache.put(1, 10)
        cache.put(2, 20)
        self.assertEqual(cache.get(1), 10)
        self.assertEqual(cache.get(2), 20)
        self.assertEqual(len(cache), 2)

    def test_eviction(self):
        cache = LRUCache(2)
        cache.put(1, 10)
        cache.put(2, 20)
        cache.get(1)
        cache.put(3, 30)
        self.assertIsNone(cache.get(2))
        self.assertEqual(cache.get(1), 10)
        self.assertEqual(cache.get(3), 30)

    def test_update_existing_key(self):
        cache = LRUCache(2)
        cache.put(1, 10)
        cache.put(2, 20)
        cache.put(1, 100)
        self.assertEqual(cache.get(1), 100)
        self.assertEqual(len(cache), 2)

    def test_nonexistent_key(self):
        cache = LRUCache(2)
        self.assertIsNone(cache.get(99))


class TestBloomFilter(unittest.TestCase):
    def test_add_and_contains(self):
        bf = BloomFilter(1000, 0.01)
        items = ["apple", "banana", "cherry"]
        for item in items:
            bf.add(item)
        for item in items:
            self.assertTrue(bf.contains(item))

    def test_absent_items(self):
        bf = BloomFilter(1000, 0.01)
        bf.add("hello")
        self.assertFalse(bf.contains("world"))

    def test_no_false_negatives(self):
        bf = BloomFilter(100, 0.01)
        items = [f"item_{i}" for i in range(50)]
        for item in items:
            bf.add(item)
        for item in items:
            self.assertTrue(bf.contains(item))

    def test_false_positive_rate(self):
        bf = BloomFilter(1000, 0.01)
        for i in range(100):
            bf.add(f"item_{i}")
        false_positives = 0
        test_count = 1000
        for i in range(test_count):
            if bf.contains(f"absent_{i}"):
                false_positives += 1
        self.assertLess(false_positives / test_count, 0.1)


class TestSegmentTree(unittest.TestCase):
    def test_build_and_query(self):
        data = [1, 3, 5, 7, 9, 11]
        st = SegmentTree(data)
        self.assertEqual(st.query(0, 5), 36)
        self.assertEqual(st.query(1, 3), 15)
        self.assertEqual(st.query(2, 4), 21)

    def test_update(self):
        data = [1, 3, 5, 7, 9, 11]
        st = SegmentTree(data)
        st.update(1, 10)
        self.assertEqual(st.query(0, 5), 43)
        self.assertEqual(st.query(1, 3), 22)

    def test_single_element(self):
        st = SegmentTree([42])
        self.assertEqual(st.query(0, 0), 42)
        st.update(0, 100)
        self.assertEqual(st.query(0, 0), 100)

    def test_invalid_query(self):
        st = SegmentTree([1, 2, 3])
        self.assertEqual(st.query(-1, 2), 0)
        self.assertEqual(st.query(2, 1), 0)


class TestFenwickTree(unittest.TestCase):
    def test_update_and_query(self):
        ft = FenwickTree(6)
        data = [1, 3, 5, 7, 9, 11]
        for i, val in enumerate(data):
            ft.update(i + 1, val)
        self.assertEqual(ft.query(1), 1)
        self.assertEqual(ft.query(3), 9)
        self.assertEqual(ft.query(6), 36)

    def test_range_query(self):
        ft = FenwickTree(6)
        data = [1, 3, 5, 7, 9, 11]
        for i, val in enumerate(data):
            ft.update(i + 1, val)
        self.assertEqual(ft.range_query(2, 4), 15)
        self.assertEqual(ft.range_query(1, 6), 36)

    def test_update_changes(self):
        ft = FenwickTree(6)
        data = [1, 3, 5, 7, 9, 11]
        for i, val in enumerate(data):
            ft.update(i + 1, val)
        ft.update(2, 7)
        self.assertEqual(ft.range_query(2, 4), 22)

    def test_invalid_range(self):
        ft = FenwickTree(5)
        self.assertEqual(ft.range_query(3, 2), 0)


class TestUnionFind(unittest.TestCase):
    def test_union_and_find(self):
        uf = UnionFind(5)
        uf.union(0, 1)
        uf.union(2, 3)
        self.assertEqual(uf.find(0), uf.find(1))
        self.assertEqual(uf.find(2), uf.find(3))
        self.assertNotEqual(uf.find(0), uf.find(2))

    def test_connected(self):
        uf = UnionFind(5)
        uf.union(0, 1)
        uf.union(1, 2)
        self.assertTrue(uf.connected(0, 2))
        self.assertFalse(uf.connected(0, 3))

    def test_count(self):
        uf = UnionFind(5)
        self.assertEqual(uf.count(), 5)
        uf.union(0, 1)
        self.assertEqual(uf.count(), 4)
        uf.union(2, 3)
        self.assertEqual(uf.count(), 3)
        uf.union(1, 2)
        self.assertEqual(uf.count(), 2)


class TestHashTableChaining(unittest.TestCase):
    def test_insert_and_search(self):
        ht = HashTableChaining()
        ht.insert("name", "Alice")
        ht.insert("age", 30)
        self.assertEqual(ht.search("name"), "Alice")
        self.assertEqual(ht.search("age"), 30)
        self.assertIsNone(ht.search("email"))

    def test_delete(self):
        ht = HashTableChaining()
        ht.insert("a", 1)
        ht.insert("b", 2)
        self.assertTrue(ht.delete("a"))
        self.assertIsNone(ht.search("a"))
        self.assertFalse(ht.delete("a"))
        self.assertEqual(len(ht), 1)

    def test_update_and_len(self):
        ht = HashTableChaining()
        ht.insert("key", "old")
        ht.insert("key", "new")
        self.assertEqual(ht.search("key"), "new")
        self.assertEqual(len(ht), 1)


class TestMaxHeap(unittest.TestCase):
    def test_insert_and_extract(self):
        h = MaxHeap()
        h.insert(3)
        h.insert(1)
        h.insert(6)
        h.insert(5)
        self.assertEqual(h.peek(), 6)
        self.assertEqual(h.extract_max(), 6)
        self.assertEqual(h.extract_max(), 5)

    def test_heapify(self):
        h = MaxHeap()
        h.heapify([4, 10, 3, 5, 1])
        self.assertEqual(h.peek(), 10)
        self.assertEqual(h.extract_max(), 10)

    def test_empty_heap_error(self):
        h = MaxHeap()
        with self.assertRaises(IndexError):
            h.extract_max()
        with self.assertRaises(IndexError):
            h.peek()

    def test_extract_all_sorted(self):
        h = MaxHeap()
        for v in [3, 1, 4, 1, 5, 9, 2, 6]:
            h.insert(v)
        result = []
        while h:
            result.append(h.extract_max())
        self.assertEqual(result, [9, 6, 5, 4, 3, 2, 1, 1])


class TestMinHeap(unittest.TestCase):
    def test_insert_and_extract(self):
        h = MinHeap()
        h.insert(5)
        h.insert(3)
        h.insert(8)
        h.insert(1)
        self.assertEqual(h.peek(), 1)
        self.assertEqual(h.extract_min(), 1)
        self.assertEqual(h.extract_min(), 3)

    def test_heapify(self):
        h = MinHeap()
        h.heapify([9, 4, 7, 1, 3, 6])
        self.assertEqual(h.peek(), 1)
        self.assertEqual(h.extract_min(), 1)

    def test_empty_heap_error(self):
        h = MinHeap()
        with self.assertRaises(IndexError):
            h.extract_min()
        with self.assertRaises(IndexError):
            h.peek()

    def test_extract_all_sorted(self):
        h = MinHeap()
        for v in [3, 1, 4, 1, 5, 9, 2, 6]:
            h.insert(v)
        result = []
        while h:
            result.append(h.extract_min())
        self.assertEqual(result, [1, 1, 2, 3, 4, 5, 6, 9])


if __name__ == "__main__":
    unittest.main()
