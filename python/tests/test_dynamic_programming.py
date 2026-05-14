import sys
import os
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from algorithms.dynamic_programming.L31_fibonacci import fib_recursive, fib_memo, fib_dp
from algorithms.dynamic_programming.L31_climbing_stairs import climb_stairs
from algorithms.dynamic_programming.L31_coin_change import coin_change
from algorithms.dynamic_programming.L31_edit_distance import edit_distance
from algorithms.dynamic_programming.L31_house_robber import rob
from algorithms.dynamic_programming.L31_knapsack_01 import knapsack_01
from algorithms.dynamic_programming.L31_knapsack_complete import knapsack_complete
from algorithms.dynamic_programming.L31_lis import lis_length, lis_sequence
from algorithms.dynamic_programming.L31_max_subarray import max_subarray
from algorithms.dynamic_programming.L31_lcs_dp import lcs_dp, lcs_dp_with_sequence
from algorithms.dynamic_programming.L31_matrix_chain import matrix_chain_order


class TestFibonacci(unittest.TestCase):
    def test_base_cases(self):
        self.assertEqual(fib_dp(0), 0)
        self.assertEqual(fib_dp(1), 1)

    def test_known_values(self):
        self.assertEqual(fib_dp(10), 55)
        self.assertEqual(fib_dp(20), 6765)

    def test_all_implementations_agree(self):
        for n in range(15):
            self.assertEqual(fib_recursive(n), fib_dp(n))
            self.assertEqual(fib_memo(n), fib_dp(n))


class TestClimbingStairs(unittest.TestCase):
    def test_small_values(self):
        self.assertEqual(climb_stairs(1), 1)
        self.assertEqual(climb_stairs(2), 2)
        self.assertEqual(climb_stairs(5), 8)

    def test_larger_value(self):
        self.assertEqual(climb_stairs(10), 89)

    def test_relationship_with_fibonacci(self):
        for n in range(1, 10):
            self.assertEqual(climb_stairs(n), fib_dp(n + 1))


class TestCoinChange(unittest.TestCase):
    def test_basic(self):
        self.assertEqual(coin_change([1, 2, 5], 11), 3)

    def test_impossible(self):
        self.assertEqual(coin_change([2], 3), -1)

    def test_zero_amount(self):
        self.assertEqual(coin_change([1, 2, 5], 0), 0)

    def test_single_coin_type(self):
        self.assertEqual(coin_change([1], 100), 100)


class TestEditDistance(unittest.TestCase):
    def test_known_cases(self):
        self.assertEqual(edit_distance("horse", "ros"), 3)
        self.assertEqual(edit_distance("intention", "execution"), 5)

    def test_same_strings(self):
        self.assertEqual(edit_distance("abc", "abc"), 0)

    def test_empty_strings(self):
        self.assertEqual(edit_distance("", ""), 0)
        self.assertEqual(edit_distance("abc", ""), 3)
        self.assertEqual(edit_distance("", "abc"), 3)


class TestHouseRobber(unittest.TestCase):
    def test_basic(self):
        self.assertEqual(rob([1, 2, 3, 1]), 4)
        self.assertEqual(rob([2, 7, 9, 3, 1]), 12)

    def test_edge_cases(self):
        self.assertEqual(rob([]), 0)
        self.assertEqual(rob([5]), 5)
        self.assertEqual(rob([1, 2]), 2)

    def test_all_same(self):
        self.assertEqual(rob([2, 2, 2, 2]), 4)


class TestKnapsack01(unittest.TestCase):
    def test_basic(self):
        self.assertEqual(knapsack_01([2, 3, 4, 5], [3, 4, 5, 6], 8), 10)

    def test_another_case(self):
        self.assertEqual(knapsack_01([1, 2, 3], [6, 10, 12], 5), 22)

    def test_empty_items(self):
        self.assertEqual(knapsack_01([], [], 10), 0)

    def test_item_too_heavy(self):
        self.assertEqual(knapsack_01([5], [10], 3), 0)


class TestKnapsackComplete(unittest.TestCase):
    def test_basic(self):
        self.assertEqual(knapsack_complete([2, 3, 4, 5], [3, 4, 5, 6], 8), 12)

    def test_unlimited_items(self):
        self.assertEqual(knapsack_complete([1, 2, 3], [6, 10, 12], 5), 30)

    def test_empty_items(self):
        self.assertEqual(knapsack_complete([], [], 10), 0)

    def test_single_item_type(self):
        self.assertEqual(knapsack_complete([1], [5], 10), 50)


class TestLIS(unittest.TestCase):
    def test_lis_length(self):
        self.assertEqual(lis_length([10, 9, 2, 5, 3, 7, 101, 18]), 4)
        self.assertEqual(lis_length([0, 1, 0, 3, 2, 3]), 4)

    def test_all_same(self):
        self.assertEqual(lis_length([7, 7, 7, 7]), 1)

    def test_empty(self):
        self.assertEqual(lis_length([]), 0)

    def test_lis_sequence(self):
        seq = lis_sequence([10, 9, 2, 5, 3, 7, 101, 18])
        self.assertEqual(len(seq), 4)
        for i in range(1, len(seq)):
            self.assertLess(seq[i - 1], seq[i])


class TestMaxSubarray(unittest.TestCase):
    def test_basic(self):
        self.assertEqual(max_subarray([-2, 1, -3, 4, -1, 2, 1, -5, 4]), 6)

    def test_all_negative(self):
        self.assertEqual(max_subarray([-1]), -1)
        self.assertEqual(max_subarray([-2, -1]), -1)

    def test_all_positive(self):
        self.assertEqual(max_subarray([5, 4, -1, 7, 8]), 23)

    def test_empty(self):
        self.assertEqual(max_subarray([]), 0)


class TestLCSDP(unittest.TestCase):
    def test_lcs_length(self):
        self.assertEqual(lcs_dp("ABCBDAB", "BDCAB"), 4)
        self.assertEqual(lcs_dp("abc", "abc"), 3)
        self.assertEqual(lcs_dp("abc", "def"), 0)

    def test_lcs_with_sequence(self):
        length, seq = lcs_dp_with_sequence("ABCBDAB", "BDCAB")
        self.assertEqual(length, 4)
        self.assertEqual(len(seq), 4)

    def test_empty_strings(self):
        self.assertEqual(lcs_dp("", ""), 0)


class TestMatrixChainOrder(unittest.TestCase):
    def test_basic(self):
        self.assertEqual(matrix_chain_order([10, 30, 5, 60]), 4500)

    def test_another_case(self):
        self.assertEqual(matrix_chain_order([40, 20, 30, 10, 30]), 26000)

    def test_small_chain(self):
        self.assertEqual(matrix_chain_order([1, 2, 3, 4]), 18)

    def test_single_matrix(self):
        self.assertEqual(matrix_chain_order([10, 20]), 0)


if __name__ == "__main__":
    unittest.main()
