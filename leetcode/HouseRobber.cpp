
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

/*
int maxMoney ( int *nums, int numsSize, int startIndex) {
    if ( startIndex >= numsSize ) {
        return 0;
    } else if ( startIndex == numsSize - 1) {
        return *(nums+startIndex);
    }
    int first = *(nums+startIndex) + maxMoney(nums, numsSize, startIndex+2);
    int second = *(nums+startIndex+1) + maxMoney(nums, numsSize, startIndex+3);
    return first>second?first:second;
}

int rob(int* nums, int numsSize) {
    if ( numsSize == 0) {
        return 0;
    } else if ( numsSize == 1 ) {
        return *nums;
    } else if ( numsSize == 2 ) {
        return *nums > *(nums+1)? *nums : *(nums+1);
    }
    int first = *nums + maxMoney(nums, numsSize, 2);
    int second = *(nums+1) + maxMoney(nums, numsSize, 3);
    return first>second?first:second;
}
*/

/*
 *		ѡ�������1��ʾѡ��0��ʾ��ѡ��	ʣ��������ʼ�±�i
 *	0	1	2		...			numsSize-1
 *	^                               ^
 *	|                               |
 *	---------------------------------
 *									1			numsSize-1
 *								1	0			numsSize-2
 *							1	0	1			numsSize-3
 *						1	0	1	0			numsSize-4
 * 						1	0	0	1			numsSize-4
 *					1	0	1	0	1			numsSize-5						
 *					1	0	0	1	0			numsSize-5
 *				1	0	1	0	1	0			numsSize-6
 *				1	0	1	0	0	1			numsSize-6
 *				1	0	0	1	0	1			numsSize-6
 *			1	0	1	0	1	0	1			numsSize-7						
 *			1	0	1	0	0	1	0			numsSize-7
 *			1	0	0	1	0	1	0			numsSize-7
 *			1	0	0	1	0	0	1			numsSize-7
 *			......								......
 */
int rob(int* nums, int numsSize) {
	if ( numsSize <= 0 ) {return 0;}
	if ( numsSize == 1 ) {return nums[0];}

	int temp1 = 0, temp2 = 0;
	if ( numsSize == 2 ) {
		temp1 = nums[1];
		temp2 = nums[0];
		return temp1 > temp2 ? temp1 : temp2;
	} else if ( numsSize == 3) {
		temp1 = nums[2] + nums[0];
		temp2 = nums[1];
		return temp1 > temp2 ? temp1 : temp2;
	} else {
		// maxValue[i] ��ʾѡ���i�������ֵ
		int *maxValue = (int*)malloc(numsSize * sizeof(int));
		maxValue[numsSize-1] = nums[numsSize-1];
		maxValue[numsSize-2] = nums[numsSize-2];
		maxValue[numsSize-3] = nums[numsSize-1] + nums[numsSize-3];
		for ( int i = numsSize-4; i >= 0; i--) {
			temp1 = nums[i] + maxValue[i+2];
			temp2 = nums[i] + maxValue[i+3];
			maxValue[i] = temp1 > temp2 ? temp1 : temp2;
		}
		// maxValue[0]��Ӧ��һ�����±�Ϊ0��ѡ������ֵ��maxValue[1]��Ӧ��1����ѡ������ֵ
		return maxValue[0] > maxValue[1] ? maxValue[0] : maxValue[1];
	}
}

int main () {

}









