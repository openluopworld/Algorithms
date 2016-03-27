
#include "basic.h"

/*
 * Count 1-bits in a word. (Compute the HanmingWeight)
 *
 * A good way to count the number of 1-bits is to first set each 2-bit field equal to the
 * sum of the two single bits that were originally in the field, and then sum adjacent 
 * 2-bit fields, putting the results in each 4-bit field, and so on.
 *
 * This is an example of the “divide and conquer” strategy, in which the original
 * problem (summing 32 bits) is divided into two problems (summing 16 bits), which are
 * solved separately, and the results are combined (added, in this case). The strategy is
 * applied recursively, breaking the 16-bit fields into 8-bit fields, and so on.
 *
 * In the case at hand, the ultimate small problems (summing adjacent bits) can all be
 * done in parallel, and combining adjacent sums can also be done in parallel in a fixed
 * number of steps at each stage. The result is an algorithm that can be executed in
 * log 2 (32) = 5 steps.
 */
BYTE countBit (WORD x) {
	/*
	 * x = (x & 0x55555555) + ((x>>1) & 0x55555555);
	 * x = (x & 0x33333333) + ((x>>2) & 0x33333333);
	 * x = (x & 0x0f0f0f0f) + ((x>>4) & 0x0f0f0f0f);
	 * x = (x & 0x00ff00ff) + ((x>>8) & 0x00ff00ff);
	 * x = (x & 0x0000ffff) + ((x>>16) & 0x0000ffff);
	 * return (uint8_t)x;
	 *
	 * the following implementation is more efficient.
	 */
	x = x - ((x>>1) & 0x55555555);
	x = (x & 0x33333333) + ((x>>2) & 0x33333333);
	x = (x + (x>>4)) & 0x0f0f0f0f;
	x = x + (x>>8);
	x = x + (x>>16);
	return x&0x3f;
}

/*
 * Another efficient method from <<Beauty of Programming>>.
 * 
 * Suppose that there is only one bit whose value is 1 in x. Take 0000 0100 as an example.
 * So x-1 is equal to 0000 0011, and the result of x&(x-1) is just 0.
 * The least significant bit whose value is 1 will be clear to 0 after x&(x-1).
 *
 */
static BYTE countBit ( BYTE x ) {
	BYTE num = 0;
	while ( x ) {
		x &= x-1;
		num++;
	}
	return num;
}

/*
 * The “parity” of a string refers to whether it contains an odd or an even number of 1-
 * bits. The string has “odd parity” if it contains an odd number of 1-bits; otherwise, it
 * has “even parity.”
 */
BYTE parity (WORD x) {
	x = x ^ (x>>1);
	x = x ^ (x>>2);
	x = x ^ (x>>4);
	x = x ^ (x>>8);
	x = x ^ (x>>16);
	return x&0x1;
