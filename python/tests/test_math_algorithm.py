import sys
import os
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from algorithms.math_algorithm.L36_prime import is_prime, miller_rabin
from algorithms.math_algorithm.L36_number_theory import gcd, lcm, fast_pow, mod_inverse, binomial, catalan, fibonacci_matrix
from algorithms.math_algorithm.L36_sieve import sieve_of_eratosthenes


class TestIsPrime(unittest.TestCase):
    def test_small_primes(self):
        for p in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31]:
            self.assertTrue(is_prime(p), f"{p} should be prime")

    def test_composites(self):
        for n in [4, 6, 8, 9, 10, 12, 14, 15, 16, 18, 20]:
            self.assertFalse(is_prime(n), f"{n} should not be prime")

    def test_edge_cases(self):
        self.assertFalse(is_prime(0))
        self.assertFalse(is_prime(1))
        self.assertFalse(is_prime(-5))

    def test_large_prime(self):
        self.assertTrue(is_prime(997))


class TestMillerRabin(unittest.TestCase):
    def test_small_primes(self):
        for p in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31]:
            self.assertTrue(miller_rabin(p), f"{p} should be prime")

    def test_composites(self):
        for n in [4, 6, 8, 9, 10, 12, 14, 15, 16]:
            self.assertFalse(miller_rabin(n), f"{n} should not be prime")

    def test_large_prime(self):
        self.assertTrue(miller_rabin(1000000007))

    def test_large_composite(self):
        self.assertFalse(miller_rabin(1000000001))


class TestGCD(unittest.TestCase):
    def test_basic(self):
        self.assertEqual(gcd(12, 8), 4)
        self.assertEqual(gcd(7, 13), 1)

    def test_with_zero(self):
        self.assertEqual(gcd(0, 5), 5)
        self.assertEqual(gcd(5, 0), 5)

    def test_same_number(self):
        self.assertEqual(gcd(6, 6), 6)


class TestLCM(unittest.TestCase):
    def test_basic(self):
        self.assertEqual(lcm(4, 6), 12)
        self.assertEqual(lcm(7, 13), 91)

    def test_with_zero(self):
        self.assertEqual(lcm(0, 5), 0)
        self.assertEqual(lcm(5, 0), 0)


class TestFastPow(unittest.TestCase):
    def test_basic(self):
        self.assertEqual(fast_pow(2, 10, 1000000007), 1024)
        self.assertEqual(fast_pow(3, 0, 1000000007), 1)

    def test_large_exponent(self):
        self.assertEqual(fast_pow(2, 30, 1000000007), 73741817)


class TestModInverse(unittest.TestCase):
    def test_existing_inverse(self):
        inv = mod_inverse(3, 7)
        self.assertNotEqual(inv, -1)
        self.assertEqual((3 * inv) % 7, 1)

    def test_no_inverse(self):
        self.assertEqual(mod_inverse(2, 4), -1)

    def test_another_case(self):
        inv = mod_inverse(2, 5)
        self.assertEqual(inv, 3)
        self.assertEqual((2 * inv) % 5, 1)


class TestBinomial(unittest.TestCase):
    def test_basic(self):
        self.assertEqual(binomial(5, 2), 10)
        self.assertEqual(binomial(10, 3), 120)

    def test_edge_cases(self):
        self.assertEqual(binomial(10, 0), 1)
        self.assertEqual(binomial(10, 10), 1)
        self.assertEqual(binomial(5, 6), 0)

    def test_symmetry(self):
        self.assertEqual(binomial(10, 3), binomial(10, 7))


class TestCatalan(unittest.TestCase):
    def test_known_values(self):
        self.assertEqual(catalan(0), 1)
        self.assertEqual(catalan(1), 1)
        self.assertEqual(catalan(2), 2)
        self.assertEqual(catalan(3), 5)
        self.assertEqual(catalan(4), 14)
        self.assertEqual(catalan(5), 42)

    def test_negative(self):
        self.assertEqual(catalan(-1), 0)


class TestFibonacciMatrix(unittest.TestCase):
    def test_base_cases(self):
        self.assertEqual(fibonacci_matrix(0), 0)
        self.assertEqual(fibonacci_matrix(1), 1)
        self.assertEqual(fibonacci_matrix(2), 1)

    def test_known_values(self):
        self.assertEqual(fibonacci_matrix(10), 55)
        self.assertEqual(fibonacci_matrix(3), 2)

    def test_large_n(self):
        self.assertEqual(fibonacci_matrix(50), 12586269025 % 1000000007)


class TestSieveOfEratosthenes(unittest.TestCase):
    def test_small_n(self):
        self.assertEqual(sieve_of_eratosthenes(10), [2, 3, 5, 7])
        self.assertEqual(sieve_of_eratosthenes(2), [2])

    def test_negative_and_zero(self):
        self.assertEqual(sieve_of_eratosthenes(-1), [])
        self.assertEqual(sieve_of_eratosthenes(1), [])

    def test_primes_up_to_30(self):
        self.assertEqual(sieve_of_eratosthenes(30), [2, 3, 5, 7, 11, 13, 17, 19, 23, 29])

    def test_primes_up_to_100(self):
        primes = sieve_of_eratosthenes(100)
        self.assertEqual(len(primes), 25)
        self.assertEqual(primes[-1], 97)


if __name__ == "__main__":
    unittest.main()
