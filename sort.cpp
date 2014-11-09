
#include<iostream>
using namespace std;

#include"sort.h"

/*
** 冒泡排序：非降序
** 基本思路：每次选择一个最大的元放置在数组的最末尾
*/
void bubbleSort ( int *a, const int length ) {

	int i = 0;      // 循环变量
	int j = 0;      // 循环变量
	int temp = 0;   // 交换元素的辅助变量

	for ( i = 1; i < length; i++ ) {         // 对于length的元素的数组，只需要length-1次即可完成排序 
		for ( j = 0; i < length-i; j++ ) {   // 依次比较两个元素
			if ( a[j] < a[j+1] ) {           // 如果前面的元素小于后面的元素，则交换连个元素的位置
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}	
	}

}

/*
** 选择排序：非降序
** 基本思路：每次选择一个最小的元素排在最前面
*/
void selectSort ( int *a, const int length ) {

	int minValue = 0;   // 当前最小元素
	int minIndex = 0;   // 最小元素的下标

	int i = 0;          // 循环变量
	int j = 0;          // 循环变量

	for ( i = 0; i < length-1; i++ ) {
		minValue = a[i];
		minIndex = i;

		for ( j = i+1; j < length; j++ ) {
			if ( a[j] < minValue ) {      // 如果该元素比当前最小元素还小
				minValue = a[j];
				minIndex = j;
			}
		}

		if ( minIndex != i) {             // 如果minIndex不等于i，说明最小元素不是a[i]，则需要交换
			a[minIndex] = a[i];
			a[i] = minValue;
		}
	}

}

/*
** 非降序插入排序
** 基本思路：逐个将元素插入到已经排好序的数组中
** 数组下标从0开始，第一个元素是已经排好序的，每一趟将后续一个元素加入到已经排好序的数组中，一共需要N-1趟
*/
void insertSortInc ( int *a, const int length ) {
	int temp;
	int j;
	for ( int i = 1; i < length; i++) {
		// 先保存该元素的值
		temp = a[i];
		// 用j保存该元素最先遇到的不大于temp元素的位置
		j = i-1;
		// 如果j没有溢出且a[j]的值大于带排序的元素则将该a[j]向后移一个位置，覆盖掉之前的数据
		while ( j >= 0 && a[j] > temp ) {
			a[j+1] = a[j];
			// j继续向前移动
			j--;
		}
		/*
		** while循环结束的条件：（j=-1）或者（j>=0且a[j]比待排序元素小）
		** 如果j=-1，则说明i前面的所有元素都比a[i]大，则a[i]的正确位置是第一个，即a[0] = temp;
		** 否则，a[j]是第一个大于待排序元素的元素，待排序元素的正确位置是j+1，即a[j+1] = temp;
		** 综合两种情况，都可表示为a[j+1] = temp;
		*/
		a[j+1] = temp;
	}
}

/*
** 非升序插入排序
** 基本思路：和非降序的思路一样，只是在比较的时候是小于才交换
*/
void insertSortDec ( int *a, const int length ) {
	int temp;
	int j;
	for ( int i = 1; i < length; i++) {
		temp = a[i];
		j = i-1;
		while ( j >= 0 && a[j] < temp ) {
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = temp;
	}
}


/*
** 归并排序算法（分治法）：对数组array位于start（包含）到end（包含）之间的元素按照非降序进行排列
** array：待排序数组
** start：待排序的首个元素位置（包括）
** end：待排序的最后一个元素位置（包括）
** temp：辅助数组，临时保存合并的元素，再转移到array中
*/ 
void mergeSort ( int *array, const int start, const int end, int *temp ) {
	
	int middle = 0;
	//while ( start < end )
	if ( start < end ) {
		middle = (start+end)/2;
		if ( 0 == (start+end)%2 ) {
			middle = middle - 1;
		}
		mergeSort( array, start, middle, temp );
		mergeSort( array, middle+1, end, temp );
		merge( array, start, middle, end, temp );
	}
	
}

/*
** 将数组array位于[start,end]间的元素进行合并，其中[start, middle]和[middle+1, end]两部分已分别排好序 
*/ 
void merge ( int *array, const int start, const int middle, const int end, int *temp ) {
	
	int count = 0;
	int i = start;
	int j = middle+1;
	/*
	** 逐个比较，直到其中一部分结束 
	*/ 
	while ( i <= middle && j <= end ) {
		if ( array[i] < array[j]) {
			temp[start+count] = array[i++];
			count++; 
		} else {
			temp[start+count] = array[j++];
			count++;
		}
	}
	
	/*
	** 对还没有比较的元素进行复制
	*/
	if ( i > middle) {
		while( j <= end ) {
			temp[start+count] = array[j++];
			count++;
		}
	} else {
		while ( i <= middle ) {
			temp[start+count] = array[i++];
			count++;
		}
	}
	
	/*
	** 将temp的元素复制到原数组中
	*/
	for ( i = 0; i < count; i++ ) {
		array[i+start] = temp[i+start];
	}
	
}


/*
** 非降序归并排序：链接表实现
*/
void mergeSortL ( const int *const array, const int start, const int end, int *link, int *temp ) {
	
	int middle = 0;
	int i = 0;
	if ( start < end ) {
		
		middle = (start+end)/2;
		if ( 0 == (start+end)%2 ) {
			middle = middle - 1;
		}
		mergeSortL( array, start, middle, link, temp );
		mergeSortL( array, middle+1, end, link, temp );
		mergeL( array, start, middle, end, link, temp );
		
	}
	
}

/*
** 非降序归并排序链接表实现的合并子程序
** 思路和merge函数一样，只是每次比较元素大小的时候可能是直接比较，也可能是通过link的下标所指向的元素
*/
void mergeL ( const int *const array, const int start, const int middle, const int end, int *link, int *temp ) {
	
	int count = 0;
	int i = start;
	int j = middle+1;

	while ( i <= middle && j <= end ) {
		// 假设link数组初始的值都为-1，表示没有指向任何元素
		if ( link[i] == -1) {
			if ( link[j] == -1) {
				if ( array[i] < array[j]) {
					temp[start+count] = i++;
				} else {
					temp[start+count] = j++;
				}
			} else {
				if ( array[i] < array[link[j]]) {
					temp[start+count] = i++;
				} else {
					temp[start+count] = link[j++];
				}
			}
		} else {
			if ( link[j] == -1) {
				if ( array[link[i]] < array[j]) {
					temp[start+count] = link[i++];
				} else {
					temp[start+count] = j++;
				}
			} else {
				if ( array[link[i]] < array[link[j]]) {
					temp[start+count] = link[i++]; 
				} else {
					temp[start+count] = link[j++];
					
				}
			}
		}
		count++;
	}
	
	/*
	** 对还没有比较的元素进行复制
	*/
	if ( i > middle) {
		while( j <= end ) {
			if ( link[j] != -1 ) {
				temp[start+count] = link[j];
			} else {
				temp[start+count] = j;
			}
			j++;
			count++;
		}
	} else {
		while ( i <= middle ) {
			if ( link[i] != -1 ) {
				temp[start+count] = link[i];
			} else {
				temp[start+count] = i;
			}
			i++;
			count++;
		}
	}
	
	for ( i = start ; i <= end; i++) {
		link[i] = temp[i];
	}
	
}

/*
 * 快速排序：对数组array位于start（包含）到end（包含）之间的元素按照非降序进行排列
 * 基本思想：以第一个元素为基准元素，从第二个元素开始以此向后查找，直到遇到第一个大于基准元素的元素；
 * 接着，从最后一个元素向前查找，直到遇到第一个小于基准元素的元素，将这两个元素进行交换，指针分别向后
 * (或先前) 移动一个，继续上述动作 
 */
void quickSort ( int *array, int start, int end ) {

	int mid = 0;
	
	if ( start < end ) {
		mid = partition( array, start, end );
		quickSort( array, start, mid-1 );
		quickSort( array, mid+1, end );
	}

}

/*
 * 对array位于[low, high]间的元素进行划分
 * 返回划分后中间元素的位置j，其中j满足：[low, j-1]的元素都小于array[j]，且[j+1,high]的元素都大于array[j] 
 */
int partition ( int *array, int low, int high ) {
	
	int base = array[low];
	
	while (low < high) {

		while ( low < high && array[high] >= base) { 
			high--;
		} 
		array[low] = array[high];
     
		while ( low < high && array[low] <= base) { 
			low++;
		} 
		array[high] = array[low];
     
	}

	array[low] = base;
	
	return low;
	
}