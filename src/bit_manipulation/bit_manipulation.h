#ifndef BIT_MANIPULATION_H
#define BIT_MANIPULATION_H

#include <cstdint>

bool isOdd(int n);
bool isPowerOfTwo(int n);
int countBits(int n);
int getBit(int n, int i);
int setBit(int n, int i);
int clearBit(int n, int i);
int toggleBit(int n, int i);
void swapXor(int &a, int &b);
int hammingDistance(int a, int b);
uint32_t reverseBits(uint32_t n);

#endif
