
/*
 * interfaces
 *
 * Author:LuoPeng
 * Time:2016.01.19
 */

#define HackerDelight
#include <stdint.h>

#ifdef HackerDelight

typedef uint8_t BYTE;
typedef uint16_t WORD;
typedef uint32_t DWORD;

/*
 * Count 1-bits in a word. (Compute the HanmingWeight)
 */
BYTE countBit (WORD x);

/*
 * The “parity” of a string refers to whether it contains an odd or an even number of 1-
 * bits. The string has “odd parity” if it contains an odd number of 1-bits; otherwise, it
 * has “even parity.”
 */
BYTE parity (WORD x);
#endif
