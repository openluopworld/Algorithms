
/*
 * Problem 172: Rotate Array
 * 
 * Rotate an array of n elements to the right by k steps.
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
 */
#include<stdio.h>
#include<stdlib.h>

/*
 * Time: O(n)
 * Space: O(k)
 */
void rotate(int* nums, int numsSize, int k) {
	if ( numsSize > 0 && k > 0) {
		k = k % numsSize;
		int *store = (int*)malloc(k * sizeof(int));
		int i;
		int *temp = store;
		for ( i = numsSize-k; i < numsSize; i++) {
			*temp++ = *(nums+i);
		}
		for ( i = numsSize-k-1; i >= 0; i--) {
			nums[i+k] = nums[i];
		}
		for ( i = 0; i < k; i++) {
			nums[i] = store[i];
		}
		free(store);
	}
	return;
}

int main () {
	int nums[] = {1,2,3,4, 5, 6};
	rotate(nums, 6, 2);
	int i;
	for (i = 0; i < 6; i++) {
		printf("%d, ", nums[i]);
	}
	return 0;
}