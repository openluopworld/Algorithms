/*
 * Problem : Remove Element
 *
 * Given an array and a value, remove all instances of that value in place and return the new length.
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 */
int removeElement(int* nums, int numsSize, int val) {
    int start = 0;
	int end = numsSize-1;
	int temp;
	while ( start < end) {
		while( start < end && *(nums+start) != val ) {
			start++;
		}
		while ( end > start && *(nums+end) == val ) {
			end--;
		}
		if ( start < end) {
			*(nums+start) = *(nums+end);
			*(nums+end) = val;
			start++;
			end--;
		}
	}
	end = numsSize-1;
	while ( end >= 0 && *(nums+end) == val ) {
		end--;
	}
	return end+1;
}