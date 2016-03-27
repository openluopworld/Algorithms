/*
 * Problem : Move Zeroes
 * 
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 * For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
 */
void moveZeroes(int* nums, int numsSize) {
   int zeroIndex, noZeroIndex;
   int tempValue = 0;
   for ( zeroIndex = 0; zeroIndex < numsSize; zeroIndex++) {
	   if ( *(nums+zeroIndex) == 0 ) {
		   break;
	   }
   }
   for ( noZeroIndex = zeroIndex+1; noZeroIndex < numsSize; noZeroIndex++ ) {
	   if ( *(nums+noZeroIndex) != 0 ) {
		   tempValue = *(nums+zeroIndex);
		   *(nums+zeroIndex) = *(nums+noZeroIndex);
		   *(nums+noZeroIndex) = tempValue;
		   zeroIndex++;
	   }
   }
}