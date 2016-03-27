
/*
 * Problem 172: Factorial Trailing Zeroes
 * Given an integer n, return the number of trailing zeroes in n!.
 * Note: Your solution should be in logarithmic time complexity.
 */

 /*
  * Solution 1
  * 对于每一个数字，累计计算因子10、5、2数字出现的个数，结果等于10出现的个数，加上5和2中出现次数较少的
  * 改进：5出现的次数一定大于2出现的次数，因此只需要统计因子10和5出现的次数。进一步衍生为只统计5出现的次数。
  * 改进：讲循环控制的步长改为5
  */
int trailingZeroes(int n) {
    int number10 = 0;
    int number5 = 0;
    int number2 = 0;
	
	int temp;
	for ( int i = n; i >=2; i--) {
		temp = i;
		while (temp >= 2) {
			if ( temp % 10 == 0) {
				number10++;
				temp = temp/10;
			} else if ( temp % 5 == 0) {
				number5++;
				temp = temp/5;
//			} else if (temp % 2 == 0) {
//				number2++;
//				temp = temp/2;
			} else {
				break;
			}
		}
	}
	return (number5>number2?number2:number5)+number10;
}

/*
 * Solution 2
 * 根据上面分析，只需要统计所有数字中因子5出现的次数
 */
int trailingZeroes(int n) {
    int result = 0;
	int temp = n/5;
	while (temp >= 1) {
		result += temp;
		temp = temp/5;
	}
	return result;
}