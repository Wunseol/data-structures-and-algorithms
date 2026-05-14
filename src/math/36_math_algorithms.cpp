#include "36_math_algorithms.h"
#include <cmath>
#include <algorithm>
#include <random>

bool isPrime(int n)
{
    if (n < 2) return false;
    if (n < 4) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

static int64_t modPow(int64_t base, int64_t exp, int64_t mod)
{
    int64_t result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1)
            result = result * base % mod;
        exp >>= 1;
        base = base * base % mod;
    }
    return result;
}

static bool millerRabinTest(int64_t n, int64_t d, int64_t a)
{
    int64_t x = modPow(a, d, n);
    if (x == 1 || x == n - 1)
        return true;
    while (d != n - 1) {
        x = x * x % n;
        d <<= 1;
        if (x == 1) return false;
        if (x == n - 1) return true;
    }
    return false;
}

bool millerRabin(int64_t n, int k)
{
    if (n < 2) return false;
    if (n < 4) return true;
    if (n % 2 == 0) return false;

    int64_t d = n - 1;
    while (d % 2 == 0)
        d >>= 1;

    std::mt19937_64 rng(42);
    for (int i = 0; i < k; i++) {
        int64_t a = 2 + rng() % (n - 3);
        if (!millerRabinTest(n, d, a))
            return false;
    }
    return true;
}

int gcd(int a, int b)
{
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int lcm(int a, int b)
{
    if (a == 0 || b == 0) return 0;
    return a / gcd(a, b) * b;
}

std::vector<int> sieveOfEratosthenes(int n)
{
    std::vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    std::vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i])
            primes.push_back(i);
    }
    return primes;
}

int64_t fastPow(int64_t base, int64_t exp, int64_t mod)
{
    return modPow(base, exp, mod);
}

static void matrixMultiply(int64_t A[2][2], int64_t B[2][2], int64_t mod)
{
    int64_t C[2][2] = {};
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j] % mod) % mod;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            A[i][j] = C[i][j];
}

int64_t fibonacciMatrix(int n)
{
    if (n <= 0) return 0;
    if (n == 1) return 1;

    int64_t result[2][2] = {{1, 0}, {0, 1}};
    int64_t base[2][2] = {{1, 1}, {1, 0}};
    int64_t mod = 1000000007;
    int p = n - 1;

    while (p > 0) {
        if (p & 1)
            matrixMultiply(result, base, mod);
        matrixMultiply(base, base, mod);
        p >>= 1;
    }

    return result[0][0];
}

static int extendedGcd(int a, int b, int &x, int &y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int g = extendedGcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

int modInverse(int a, int m)
{
    int x, y;
    int g = extendedGcd(a, m, x, y);
    if (g != 1) return -1;
    return (x % m + m) % m;
}

int64_t catalan(int n)
{
    if (n < 0) return 0;
    std::vector<int64_t> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - 1 - j];
        }
    }
    return dp[n];
}

int64_t binomial(int n, int k)
{
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;
    if (k > n - k) k = n - k;

    std::vector<int64_t> dp(k + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        int j = std::min(i, k);
        while (j > 0) {
            dp[j] = dp[j] + dp[j - 1];
            j--;
        }
    }
    return dp[k];
}
