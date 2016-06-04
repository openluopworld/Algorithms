
#include <stdio.h>
#include <stdbool.h>

bool isPowerOfFour(int num) {
	return ( (num!=0) && (num&0xaaaaaaaa) == 0) && ( (num&(num-1)) == 0);
}

int main (void) {

	printf("%d\n", isPowerOfFour(0x80000000));

}
