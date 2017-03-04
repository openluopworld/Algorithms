# 蛇形矩阵打印
2016.09.02

```C
#include <stdio.h>
#include <stdlib.h>

int main ( int argc, char *argv[]) {

	int n = 0;
	scanf("%d", &n);

	if ( n <= 0 ) { return -1; }

	// get memory
	int i, j;
	int **nums = (int**)malloc(sizeof(int*)*n);
	if ( NULL == nums ) {
		return -1;
	}

	for ( i = 0; i < n; ++i ) {
		nums[i] = (int*)malloc(sizeof(int)*n);
		if ( NULL == nums[i] ) {
			return -1;
		}
	}

	// set values
	int count;
	int value = 0;
	for ( i = 0; i < n/2; ++i ) {
		count = n-2*i-1;
		// --->
		for ( j = 0; j < count; ++j) {
			nums[i][i+j] = ++value;
		}
		// down
		for ( j = 0; j < count; ++j) {
			nums[i+j][n-i-1] = ++value;
		}		
		// <---
		for ( j = count-1; j >= 0; --j) {
			nums[n-i-1][i+j+1] = ++value;
		}
		// up
		for ( j = count-1; j >= 0; --j) {
			nums[i+j+1][i] = ++value;
		}
	}
	if ( n%2 ) {
		nums[n/2][n/2] = ++value;
	}

	// printf
	for ( i = 0; i < n; ++i ) {
		for ( j = 0; j < n; ++j ) {
			printf("%3d", nums[i][j]);
		}
		printf("\n");
	}

	// free
	for ( i = 0; i < n; ++i ) {
		free(nums[i]);
		nums[i] = NULL;
	}
	free(nums);
	nums = NULL;

	return 0;

}
```

![results](http://1.lpxq.sinaapp.com/images/201609/2016-09-02-results.png)
