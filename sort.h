
/*
** 非降序插入排序
*/
void insertSortInc ( int *a, const int length );

/*
** 非升序插入排序
*/
void insertSortDec ( int *a, const int length );

/*
** 归并排序：非降序
*/
void mergeSort ( int *array, const int start, const int end, int *temp );

/*
** 归并排序的链接表实现：非降序
*/
void mergeSortL ( const int *const array, const int start, const int end, int *link, int *temp );

/*
** 快速排序：非降序
*/
void quickSort ( int *array, int start, int end );