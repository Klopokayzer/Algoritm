#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>



int hash(char *S)
{
     int i,r=0;
     while(*S)
     {
         r+=(int)(*S);
         S++;
     }
     return r;
}

void exchange (int *money, int SIZE, int sum){
	int count = 0;
	for (int i = 0; i < SIZE; i++){
		count = sum/money[i];
		sum = sum%money[i];
		printf("Nominal monet:%d count:%d \n", money[i], count);
	}
}

int main(){
	//1 задание
	printf("\nexercise 1:\n");
	char str[] = "Hello!";
	printf("Summa codov symbol: %d \n", hash(str));
	//printf("%s ", hash(str));
	//2 задание
	printf("\nexercise 2:\n");
	int SIZE = 5;
	int money[SIZE] = {50, 10, 5, 2, 1};
	int sum = 98;
	exchange(money, SIZE, sum);
	return 0;
}