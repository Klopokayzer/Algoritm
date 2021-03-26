#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int get2dInt(int** array, const int row, const int col){
	return *((*(array + row)) + col);
}

void print2dIntArray(int** array, const int row, const int col, int offset){
	char format[7];
	sprintf(format, "%%%dd", offset);
	for (int i = 0; i < row; ++i){
		for (int j = 0; j < col; ++j){
			printf(format, get2dInt(array, i, j));
		}
	printf("\n");
	}
}

void set2dInt(int** array, const int row, const int col, int value){
	*((*(array + row)) + col) = value;
}

int** init2dIntArray(int** array, const int pow, const int col){
	array = (int**) calloc(sizeof(int*), pow);
	for(int i=0; i < pow; ++i){
		*(array + i) = (int*) calloc(sizeof(int), col);
	}
	return array;
}

void binRec(int n){
	if (n <=0)
		return;
	binRec(n/2);
	printf("%d", n % 2);
}

int recPower(int n, int ex){
	if (ex <= 0){
		return 1;
	}
	return n * recPower(n, ex - 1);
}

int kingRoutes(int x, int y, int** avail){
	if (get2dInt(avail, y, x) == 1)
		return 0;
	if (x == 0 && y == 0)
		return 0;
	else if (x == 0) {
		if(kingRoutes(x, y-1, avail) == 0 && y != 1){
			return 0;
		}
		return 1;
	} else if (y == 0) {
		if (kingRoutes(x-1, y, avail) == 0 && x != 1){
			return 0;
		}
		return 1;
	}
	return kingRoutes(x, y-1, avail) + kingRoutes(x-1, y, avail);
}

int main(){
	binRec(106);
	printf("\n");
	printf("\n");
	printf("%d \n", recPower(3, 2));
	printf("\n");
	printf("\n");
	const int SZ = 6;
	int** desk = init2dIntArray(desk, SZ, SZ);
	
	set2dInt(desk, 0, 4, 1);
	set2dInt(desk, 2, 1, 1);
	set2dInt(desk, 2, 2, 1);
	print2dIntArray(desk, SZ, SZ, 2);
	
	for (int y = 0; y < SZ; ++y) {
		for (int x = 0; x < SZ; ++x)
			printf("%5d", kingRoutes(x, y, desk));
		printf("\n");
	}
	return 0;
}