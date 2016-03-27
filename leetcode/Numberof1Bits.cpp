
/*
 * Problem: Number of 1 Bits
 * 
 * Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
 * For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
 */
#include<stdio.h>
#include<stdint.h>
 
int hammingWeight(uint32_t n) {
    int bits = 0;
	int count = 0;
	while ( n != 0 && count < 32) {
		bits += n & 0x1;
		n = n>>1;
		count++;
	}
	return bits;
}

int main () {
	int result = hammingWeight(0xf0000077);
	printf("%d\n", result);
}