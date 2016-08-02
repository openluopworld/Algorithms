#include <stdio.h>
#include <stdlib.h>

int main() {
	int iw, in;
	int *w, *v, *d;
	int notAddThis, addThis;
	int i,j;

	scanf("%d %d", &iw, &in);//while(scanf("%d %d", &n, &C) != EOF){
	w = (int*)malloc(sizeof(int)*in);
	v = (int*)malloc(sizeof(int)*iw);
	d = (int*)malloc(sizeof(int)*(in+1)*(iw+1));

	if ( NULL == w || NULL == v || NULL == d) { return -1; }

	for(i = 0; i < in; ++i) { scanf("%d %d", v+i, w+i); }

	for(i = 0; i <= in; ++i) {
		for(j = 0; j <= iw; ++j ) {
			//d[i][j] = (i==0)?0:d[i-1][j];
			*(d+i*(iw+1)+j) = (i==0)?0:*(d+(i-1)*(iw+1)+j);
			if( i > 0 && j >= v[i-1] ) {
				//notAddThis = d[i-1][j];
				notAddThis = *(d+(i-1)*(iw+1)+j);
				//addThis = d[i-1][j-V[i-1]]+W[i-1];
				addThis = *(d+(i-1)*(iw+1)+(j-v[i-1]))+w[i-1];
				*(d+i*(iw+1)+j) = notAddThis > addThis ? notAddThis : addThis;
			}
		}
	}

	printf("%d\n", *(d+in*(iw+1)+iw));
	free(d);
	free(v);
	free(w);

	return 0;
}













