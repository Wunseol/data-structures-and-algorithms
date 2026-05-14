import sys
import os
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from algorithms.string_algorithm.L30_brute_force import brute_force_search
from algorithms.string_algorithm.L30_kmp import kmp_search, compute_next
from algorithms.string_algorithm.L30_rabin_karp import rabin_karp_search
from algorithms.string_algorithm.L30_boyer_moore import boyer_moore_search
from algorithms.string_algorithm.L30_manacher import manacher
from algorithms.string_algorithm.L30_lcs import lcs_length, lcs_string
from algorithms.string_algorithm.L30_rolling_hash import RollingHash
from algorithms.string_algorithm.L30_z_algorithm import z_function, z_search


class TestBruteForce(unittest.TestCase):
    def test_match(self):
        self.assertEqual(brute_force_search("hello world", "world"), [6])
        self.assertEqual(brute_force_search("ABABCABCABABABD", "ABAB"), [0, 8, 10])

    def test_no_match(self):
        self.assertEqual(brute_force_search("abc", "d"), [])

    def test_multiple_matches(self):
        self.assertEqual(brute_force_search("aaaaa", "aa"), [0, 1, 2, 3])

    def test_empty_pattern(self):
        self.assertEqual(brute_force_search("abc", ""), [])


class TestKMP(unittest.TestCase):
    def test_match(self):
        self.assertEqual(kmp_search("hello world", "world"), [6])
        self.assertEqual(kmp_search("ABABCABCABABABD", "ABAB"), [0, 8, 10])

    def test_no_match(self):
        self.assertEqual(kmp_search("abc", "d"), [])

    def test_pattern_at_end(self):
        self.assertEqual(kmp_search("abcdef", "def"), [3])

    def test_overlapping_matches(self):
        self.assertEqual(kmp_search("aaaaa", "aa"), [0, 1, 2, 3])

    def test_compute_next(self):
        next_arr = compute_next("ABAB")
        self.assertEqual(len(next_arr), 5)
        self.assertEqual(next_arr[0], -1)

    def test_pattern_longer_than_text(self):
        self.assertEqual(kmp_search("ab", "abc"), [])


class TestRabinKarp(unittest.TestCase):
    def test_match(self):
        self.assertEqual(rabin_karp_search("hello world", "world"), [6])
        self.assertEqual(rabin_karp_search("ABABCABCABABABD", "ABAB"), [0, 8, 10])

    def test_no_match(self):
        self.assertEqual(rabin_karp_search("abc", "d"), [])

    def test_overlapping_matches(self):
        self.assertEqual(rabin_karp_search("aaaaa", "aa"), [0, 1, 2, 3])

    def test_multiple_separated_matches(self):
        self.assertEqual(rabin_karp_search("GEEKS FOR GEEKS", "GEEK"), [0, 10])


class TestBoyerMoore(unittest.TestCase):
    def test_match(self):
        self.assertEqual(boyer_moore_search("hello world", "world"), [6])
        self.assertEqual(boyer_moore_search("ABCABCABC", "ABC"), [0, 3, 6])

    def test_no_match(self):
        self.assertEqual(boyer_moore_search("abc", "d"), [])

    def test_overlapping_matches(self):
        self.assertEqual(boyer_moore_search("aaaaa", "aa"), [0, 1, 2, 3])

    def test_single_char_pattern(self):
        self.assertEqual(boyer_moore_search("abcabc", "a"), [0, 3])


class TestManacher(unittest.TestCase):
    def test_longest_palindromic_substring(self):
        self.assertIn(manacher("babad"), ("bab", "aba"))
        self.assertEqual(manacher("cbbd"), "bb")
        self.assertEqual(manacher("racecar"), "racecar")

    def test_edge_cases(self):
        self.assertEqual(manacher("a"), "a")
        self.assertEqual(manacher(""), "")
        self.assertEqual(manacher("ac"), "a")

    def test_full_palindrome(self):
        self.assertEqual(manacher("abaaba"), "abaaba")


class TestLCS(unittest.TestCase):
    def test_lcs_length(self):
        self.assertEqual(lcs_length("ABCBDAB", "BDCABA"), 4)
        self.assertEqual(lcs_length("abc", "abc"), 3)
        self.assertEqual(lcs_length("abc", "def"), 0)

    def test_lcs_string(self):
        result = lcs_string("ABCBDAB", "BDCABA")
        self.assertIn(result, ("BCBA", "BDAB", "BCAB"))
        self.assertEqual(lcs_string("abc", "abc"), "abc")
        self.assertEqual(lcs_string("abc", "def"), "")

    def test_empty_strings(self):
        self.assertEqual(lcs_length("", ""), 0)
        self.assertEqual(lcs_string("", ""), "")


class TestRollingHash(unittest.TestCase):
    def test_compute_hash(self):
        rh = RollingHash()
        h = rh.compute_hash("hello")
        self.assertIsInstance(h, int)

    def test_slide(self):
        rh1 = RollingHash()
        rh1.compute_hash("abc")
        rh1.slide("a", "d")
        rh2 = RollingHash()
        rh2.compute_hash("bcd")
        self.assertEqual(rh1.hash_value, rh2.hash_value)

    def test_append_consistency(self):
        rh1 = RollingHash()
        rh1.compute_hash("hello")
        rh2 = RollingHash()
        for ch in "hello":
            rh2.append(ch)
        self.assertEqual(rh1.hash_value, rh2.hash_value)

    def test_skip(self):
        rh1 = RollingHash()
        rh1.compute_hash("abcd")
        rh1.skip("a")
        rh2 = RollingHash()
        rh2.compute_hash("bcd")
        self.assertEqual(rh1.hash_value, rh2.hash_value)


class TestZAlgorithm(unittest.TestCase):
    def test_z_function(self):
        z = z_function("aabcaab")
        self.assertEqual(z[0], 7)
        self.assertEqual(z[1], 1)
        self.assertEqual(z[4], 3)

    def test_z_function_simple(self):
        z = z_function("aaaa")
        self.assertEqual(z, [4, 3, 2, 1])

    def test_z_search(self):
        self.assertEqual(z_search("hello world", "world"), [6])
        self.assertEqual(z_search("aaaaa", "aa"), [0, 1, 2, 3])
        self.assertEqual(z_search("abc", "d"), [])

    def test_z_search_multiple_matches(self):
        self.assertEqual(z_search("AABAACAADAABAABA", "AABA"), [0, 9, 12])

    def test_z_search_empty_pattern(self):
        self.assertEqual(z_search("abc", ""), [])


if __name__ == "__main__":
    unittest.main()
