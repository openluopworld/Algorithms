
/*
 * Problem: Happy Number
 * 
 * Write an algorithm to determine if a number is "happy".
 * A happy number is a number defined by the following process: Starting with any positive integer, 
 * replace the number by the sum of the squares of its digits, 
 * and repeat the process until the number equals 1 (where it will stay), 
 * or it loops endlessly in a cycle which does not include 1. 
 * Those numbers for which this process ends in 1 are happy numbers.
 */
#include<stdio.h>
#include<math.h>

bool isHappy(int n) {
    int temp = 10;
	/*
	 * If n is smaller than 10, you can get than only 1 or 7 will be true by computing.
	 * There is a problem: will every number be smaller than 10 some time later?
	 */
	while ( temp >= 10) {
		temp = 0;
		while ( n != 0 ) {
			temp += (n%10)*(n%10);
			n = n/10;
		}
		n = temp;
		// printf("%d\n", temp);
	}
	return temp==7 || temp==1;
}

int main () {
	for ( int i = 0; i < 100; i++ ) {
		printf("%d, %s\n", i, (isHappy(i)==false)?"false":"true");
	}
	return 0;
}