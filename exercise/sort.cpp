
#include<iostream>
using namespace std;

#include"sort.h"

/*
** ð�����򣺷ǽ���
** ����˼·��ÿ��ѡ��һ������Ԫ�������������ĩβ
*/
void bubbleSort ( int *a, const int length ) {

	int i = 0;      // ѭ������
	int j = 0;      // ѭ������
	int temp = 0;   // ����Ԫ�صĸ�������

	for ( i = 1; i < length; i++ ) {         // ����length��Ԫ�ص����飬ֻ��Ҫlength-1�μ���������� 
		for ( j = 0; i < length-i; j++ ) {   // ���αȽ�����Ԫ��
			if ( a[j] < a[j+1] ) {           // ���ǰ���Ԫ��С�ں����Ԫ�أ��򽻻�����Ԫ�ص�λ��
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}	
	}

}

/*
** ѡ�����򣺷ǽ���
** ����˼·��ÿ��ѡ��һ����С��Ԫ��������ǰ��
*/
void selectSort ( int *a, const int length ) {

	int minValue = 0;   // ��ǰ��СԪ��
	int minIndex = 0;   // ��СԪ�ص��±�

	int i = 0;          // ѭ������
	int j = 0;          // ѭ������

	for ( i = 0; i < length-1; i++ ) {
		minValue = a[i];
		minIndex = i;

		for ( j = i+1; j < length; j++ ) {
			if ( a[j] < minValue ) {      // �����Ԫ�رȵ�ǰ��СԪ�ػ�С
				minValue = a[j];
				minIndex = j;
			}
		}

		if ( minIndex != i) {             // ���minIndex������i��˵����СԪ�ز���a[i]������Ҫ����
			a[minIndex] = a[i];
			a[i] = minValue;
		}
	}

}

/*
** �ǽ����������
** ����˼·�������Ԫ�ز��뵽�Ѿ��ź����������
** �����±��0��ʼ����һ��Ԫ�����Ѿ��ź���ģ�ÿһ�˽�����һ��Ԫ�ؼ��뵽�Ѿ��ź���������У�һ����ҪN-1��
*/
void insertSortInc ( int *a, const int length ) {
	int temp;
	int j;
	for ( int i = 1; i < length; i++) {
		// �ȱ����Ԫ�ص�ֵ
		temp = a[i];
		// ��j�����Ԫ�����������Ĳ�����tempԪ�ص�λ��
		j = i-1;
		// ���jû�������a[j]��ֵ���ڴ������Ԫ���򽫸�a[j]�����һ��λ�ã����ǵ�֮ǰ������
		while ( j >= 0 && a[j] > temp ) {
			a[j+1] = a[j];
			// j������ǰ�ƶ�
			j--;
		}
		/*
		** whileѭ����������������j=-1�����ߣ�j>=0��a[j]�ȴ�����Ԫ��С��
		** ���j=-1����˵��iǰ�������Ԫ�ض���a[i]����a[i]����ȷλ���ǵ�һ������a[0] = temp;
		** ����a[j]�ǵ�һ�����ڴ�����Ԫ�ص�Ԫ�أ�������Ԫ�ص���ȷλ����j+1����a[j+1] = temp;
		** �ۺ�������������ɱ�ʾΪa[j+1] = temp;
		*/
		a[j+1] = temp;
	}
}

/*
** �������������
** ����˼·���ͷǽ����˼·һ����ֻ���ڱȽϵ�ʱ����С�ڲŽ���
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
** �鲢�����㷨�����η�����������arrayλ��start����������end��������֮���Ԫ�ذ��շǽ����������
** array������������
** start����������׸�Ԫ��λ�ã�������
** end������������һ��Ԫ��λ�ã�������
** temp���������飬��ʱ����ϲ���Ԫ�أ���ת�Ƶ�array��
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
** ������arrayλ��[start,end]���Ԫ�ؽ��кϲ�������[start, middle]��[middle+1, end]�������ѷֱ��ź��� 
*/ 
void merge ( int *array, const int start, const int middle, const int end, int *temp ) {
	
	int count = 0;
	int i = start;
	int j = middle+1;
	/*
	** ����Ƚϣ�ֱ������һ���ֽ��� 
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
	** �Ի�û�бȽϵ�Ԫ�ؽ��и���
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
	** ��temp��Ԫ�ظ��Ƶ�ԭ������
	*/
	for ( i = 0; i < count; i++ ) {
		array[i+start] = temp[i+start];
	}
	
}


/*
** �ǽ���鲢�������ӱ�ʵ��
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
** �ǽ���鲢�������ӱ�ʵ�ֵĺϲ��ӳ���
** ˼·��merge����һ����ֻ��ÿ�αȽ�Ԫ�ش�С��ʱ�������ֱ�ӱȽϣ�Ҳ������ͨ��link���±���ָ���Ԫ��
*/
void mergeL ( const int *const array, const int start, const int middle, const int end, int *link, int *temp ) {
	
	int count = 0;
	int i = start;
	int j = middle+1;

	while ( i <= middle && j <= end ) {
		// ����link�����ʼ��ֵ��Ϊ-1����ʾû��ָ���κ�Ԫ��
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
	** �Ի�û�бȽϵ�Ԫ�ؽ��и���
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
 * �������򣺶�����arrayλ��start����������end��������֮���Ԫ�ذ��շǽ����������
 * ����˼�룺�Ե�һ��Ԫ��Ϊ��׼Ԫ�أ��ӵڶ���Ԫ�ؿ�ʼ�Դ������ң�ֱ��������һ�����ڻ�׼Ԫ�ص�Ԫ�أ�
 * ���ţ������һ��Ԫ����ǰ���ң�ֱ��������һ��С�ڻ�׼Ԫ�ص�Ԫ�أ���������Ԫ�ؽ��н�����ָ��ֱ����
 * (����ǰ) �ƶ�һ���������������� 
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
 * ��arrayλ��[low, high]���Ԫ�ؽ��л���
 * ���ػ��ֺ��м�Ԫ�ص�λ��j������j���㣺[low, j-1]��Ԫ�ض�С��array[j]����[j+1,high]��Ԫ�ض�����array[j] 
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