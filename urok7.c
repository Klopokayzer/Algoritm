#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void sortInserts(int* arr, int len){
	int temp, pos;
	for(int i = 1; i < len; ++i){
		temp = arr[i];
		pos = i - 1;
		while (pos >= 0 && arr[pos] > temp){
			arr[pos + 1] = arr[pos];
			pos--;
		}
		arr[pos + 1] = temp;
	}
}

void swapInt(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void fillIntRandom(int* array, int size, int border) {
    for (int i = 0; i < size; ++i)
        *(array + i) = rand() % border;
}

void printIntArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%3d", array[i]);
        if (i != size - 1)
            printf(",");
    }
    printf("\n");
}

void QiuckSort(int* arr, int first, int last){
	int i = first;
	int j = last;
	int x = arr[(first + last)/2];
	do {
		while (arr[i]<x) i++;
		while (arr[j]>x) j--;
		if(i <= j){
			swapInt(&arr[i], &arr[j]);
			i++;
			j--;}
	}while (i <= j);
	if (i < last) QiuckSort(arr, i, last);
	if (first < j) QiuckSort(arr, first, j);
}

/*void BlockSort(int* arr, int len){
	const int max = len;
	const int b = 10;
	int buckets[b];
	for(int i=0; i < b; ++i){
		if(arr[i]%2==0){
			int cont = buckets[i];
			buckets[arr[i]%b] =  arr[i];
			
		}
			int d = (arr[i]/digit)%b;
			int counter = buckets[d][max];
			buckets[d][counter] = arr[i];
			counter++;
			buckets[d][max]=counter;
		}
		int idx = 0;
		for(int i =0; i < b; ++i){
			if(arr[i]%2==0){
			for(int j = 0; j < buckets[i][max]; ++j){
				arr[idx++]=buckets[i][j];
			}
			buckets[i][max]=0;
		}
	}
}*/

int main(){
	const int SIZE = 30;
	int array[SIZE];
	int a;
	fillIntRandom(array, SIZE, 100);
	printIntArray(array, SIZE);
	//1 задание
	if(SIZE<=10){
		sortInserts(array, SIZE);
	}else{
		a = (array[0]+array[SIZE/2]+array[SIZE-1])/3;
		array[SIZE/2] = a;
		QiuckSort(array, 0, SIZE-1);
	}
	printIntArray(array, SIZE);
	printf("\n");
	//2 задание
	int arr2[12] = {0, 2, 8, 3, 4, 6, 5, 9, 8, 2, 7, 3};
	printIntArray(arr2, 12);
	/*BlockSort(arr2, 12);
	printIntArray(arr2, 12);*/
	//Не смог разобраться с блочной сортировкой, чтобы она поменяла всего 2 числа местами... Получилось все четные числа сделать 2 и 8))...
	return 0;
}