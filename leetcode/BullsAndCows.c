
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * 299. Bulls and Cows
 *
 * the solution is so complex...
 *
 */
char* getHint(char* secret, char* guess) {
	int i;
	int count[10] = {0};
	int A = 0, B = 0;
	for ( i = 0; '\0' != *(secret+i); i++ ) {
		if ( *(secret+i) == *(guess+i) ) {
			A++;
		} else {
			if ( count[*(secret+i)-'0']++ < 0 ) B++;
			if ( count[*(guess+i)-'0']-- > 0 ) B++;
		}
	}

	// computer length of return array
	int length = 0;
	i = A;
	// the loop execute at least one time for A may be 0
	do {
		length++;
		i /= 10;
	} while ( i );
	i = B;
	do {
		length++;
		i /= 10;
	} while ( i );

	// record in reverse
	char *result = (char*)malloc(length+3);
	*result = 'B';
	i = 1;
	do {
		*(result + i++) = B%10 + '0';
		B /= 10;
	} while ( B );
	*(result + i++) = 'A';
	do {
		*(result + i++) = A%10 + '0';
		A /= 10;
	} while ( A ) ;
	*(result+i) = '\0';

	// reverse
	for ( i = 0; i < length/2+1; i++ ) {
		*(result+i) ^= *(result+length+1-i);
		*(result+length+1-i) ^= *(result+i);
		*(result+i) ^= *(result+length+1-i);
	}

	return result;
}

int main ( void ) {

	char *secret = "11111111111111";
	char *guess =  "11111111111111";
	char *result = getHint(secret, guess);
	printf("%s\n", result);
	free(result);

	return 0;
}
















