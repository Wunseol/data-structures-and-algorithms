#ifndef MATH_ALGORITHMS_H
#define MATH_ALGORITHMS_H

#include <vector>
#include <cstdint>

bool isPrime(int n);
bool millerRabin(int64_t n, int k);
int gcd(int a, int b);
int lcm(int a, int b);
std::vector<int> sieveOfEratosthenes(int n);
int64_t fastPow(int64_t base, int64_t exp, int64_t mod);
int64_t fibonacciMatrix(int n);
int modInverse(int a, int m);
int64_t catalan(int n);
int64_t binomial(int n, int k);

#endif
