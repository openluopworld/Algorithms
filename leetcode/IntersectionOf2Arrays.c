
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * @purpose		sort the array, the element with the same value is computed only once.
 * @para[in] nums	an array with unorder elements, some may have the same value
 * @para[in] numsSize	the number of size in the array
 *
 * @return		the number of elements without the duplicate values
 * @example
 *	input {1, 2, 8, 7, 3, 2, 2, 8}
 *	output {1, 2, 3, 7, 8, 2, 2, 8}, the order of last three elements is not important
 *	return 5
 */
int insertSort( int *nums, int numsSize) {

	int tempMini;
	int indexMini;
	int i, j;
	int resultIndex;

	indexMini = 0;
	i = 1;
	// find the smallest value for the first position
	while ( i < numsSize ) {
		if ( *(nums+i) < *(nums+indexMini) ) {
			indexMini = i;
		}
		i++;
	}
	tempMini = *(nums+indexMini);
	if ( 0 != indexMini) {
		*nums ^= *(nums+indexMini);
		*(nums+indexMini) ^= *nums;
		*nums ^= *(nums+indexMini);
	}
	resultIndex = 1;
	
	// the other values
	for ( i = 1; i < numsSize; ++i ) {
		if ( tempMini >= *(nums+i) ) {
			continue;
		}

		indexMini = i;		
		for ( j = i+1; j < numsSize; ++j ) {
			if ( (*(nums+j) > tempMini) &&
				(*(nums+j) < *(nums+indexMini)) ) {
				indexMini = j;
			}
		}
		if ( indexMini != i ) { 
			i--;
		}
		if ( resultIndex != indexMini) {
			*(nums+resultIndex) ^= *(nums+indexMini);
			*(nums+indexMini) ^= *(nums+resultIndex);
			*(nums+resultIndex) ^= *(nums+indexMini);
		}
		tempMini = *(nums+resultIndex);
		resultIndex++;

	}

	return resultIndex;

}

/**
 * @Return	an array of size *returnSize.
 * @Note	The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {

	int diffSize1, diffSize2;
	int *section = NULL;
	int size;
	int i, j;

	if ( (!nums1Size) || (!nums2Size) ) {
		*returnSize = 0;
		return NULL;
	}

	diffSize1 = insertSort(nums1, nums1Size);
	diffSize2 = insertSort(nums2, nums2Size);
	size = 0;
	i = j = 0;
	while ( (i < diffSize1) && (j < diffSize2) ) {
		if ( *(nums1+i) == *(nums2+j)) {
			size++;
			i++;
			j++;
		} else if ( *(nums1+i) < *(nums2+j) ) {
			i++;
		} else {
			j++;
		}
	}


	if ( !size ) {
		*returnSize = 0;
		return NULL;
	}

	// the size of int is sizeof(int)
	// section = (int*)malloc(size);
	section = (int*)malloc(sizeof(int)*size);
	*returnSize = size;

	i = j = 0;
	size = 0;
	while ( (i < diffSize1) && (j < diffSize2) ) {
		if ( *(nums1+i) == *(nums2+j)) {
			*(section + size++ ) = *(nums1 + i++);
			j++;
		} else if ( *(nums1+i) < *(nums2+j) ) {
			i++;
		} else {
			j++;
		}
	}

	return section;

}

int main (void) {


//	int nums1[] = {1, 2, 2, 0};  
//	int nums2[] = {2, 2};

//int nums1[] = {43,85,49,2,83,2,39,99,15,70,39,27,71,3,88,5,19,5,68,34,7,41,84,2,13,85,12,54,7,9,13,19,92};
//int nums2[] = {10,8,53,63,58,83,26,10,58,3,61,56,55,38,81,29,69,55,86,23,91,44,9,98,41,48,41,16,42,72,6,4,2,81,42,84,4,13};


	int nums1[] = {61,24,20,58,95,53,17,32,45,85,70,20,83,62,35,89,5,95,12,86,58,77,
			30,64,46,13,5,92,67,40,20,38,31,18,89,85,7,30,67,34,62,35,47,98,3,
			41,53,26,66,40,54,44,57,46,70,60,4,63,82,42,65,59,17,98,29,72,1,96,
			82,66,98,6,92,31,43,81,88,60,10,55,66,82,0,79,11,81};
	int nums2[] = {5,25,4,39,57,49,93,79,7,8,49,89,2,7,73,88,45,15,34,92,84,38,85,34,
			16,6,99,0,2,36,68,52,73,50,77,44,61,48};

	int i = 0;
	int result1 = insertSort(nums1, sizeof(nums1)/4);
	printf("%d\n", result1);
	for ( i = 0; i < sizeof(nums1)/4; ++i ) {
		printf("%3d", *(nums1+i));
	}
	printf("\n\n");

	int result2 = insertSort(nums2, sizeof(nums2)/4);
	printf("%d\n", result2);
	for ( i = 0; i < sizeof(nums2)/4; ++i ) {
		printf("%3d", *(nums2+i));
	}
	printf("\n\n");


	int result;
	int *section = intersection(nums1, sizeof(nums1)/4, nums2, sizeof(nums2)/4, &result);

	printf("%d\n", result);
	for ( i = 0; i < result; ++i ) {
		printf("%3d", *(section+i));
	}

	free(section);
	
	return 0;

}
