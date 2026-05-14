#include "35_bit_manipulation.h"

bool isOdd(int n)
{
    return (n & 1) == 1;
}

bool isPowerOfTwo(int n)
{
    return n > 0 && (n & (n - 1)) == 0;
}

int countBits(int n)
{
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

int getBit(int n, int i)
{
    return (n >> i) & 1;
}

int setBit(int n, int i)
{
    return n | (1 << i);
}

int clearBit(int n, int i)
{
    return n & ~(1 << i);
}

int toggleBit(int n, int i)
{
    return n ^ (1 << i);
}

void swapXor(int &a, int &b)
{
    if (&a == &b)
        return;
    a ^= b;
    b ^= a;
    a ^= b;
}

int hammingDistance(int a, int b)
{
    return countBits(a ^ b);
}

uint32_t reverseBits(uint32_t n)
{
    uint32_t result = 0;
    for (int i = 0; i < 32; i++) {
        result <<= 1;
        result |= (n & 1);
        n >>= 1;
    }
    return result;
}
