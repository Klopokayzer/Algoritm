#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main ()
{
	int number;
	int a;
	float b;
	printf("Vvedite chislo!\n");
	scanf("%d", &number);
	for (a = 2; a <= number; a++){
		if (number%a==0){
			b++;
		}
	}
	if (b > 1) {
		printf("Chsilo %d ne prostoe \n", number);
	} else {
		printf("Chsilo %d prostoe \n", number);
	}
	return 0;
}