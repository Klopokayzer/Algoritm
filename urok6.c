#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sort(int array[3][3]){
for (int k = 0; k < 3; ++k)
	{
		for (int l = 0; l < 3; ++l)
		{
			for (int i = 0; i < 3; ++i)
			{
				for (int j = 0; j < 3; ++j)
				{
					if (i+1==3 and j+1==3)
					{
						continue;
					}
					else
					{
						if (j+1 == 3 and array[i][j] > array[i+1][0])
						{
							int t = array[i][j];
							array[i][j] = array[i+1][0];
							array[i+1][0] = t;
						}
						else
						{
							if (array[i][j]>array[i][j+1])
							{
								int t = array[i][j];
								array[i][j] = array[i][j+1];
								array[i][j+1] = t;
							}
						}
					}
				}
			}
		}
	}	
	return array[3][3];
}

void schet(int a, int nomer){
		float chislo;
		chislo = sqrt(fabs(a))+5*pow(a,3);
		if (chislo > 400)
		printf("Result chisla #%d bolshe 400 \n",nomer);
		else
		printf("Result chisla #%d: %d = %f \n",nomer,a, chislo);
}

int invert(int arr[11]){
	int a = 10;
	int temp;
	for (int i = 0; i < 11/2; i++){
		temp = arr[i];
		arr[i] = arr[a];
		arr[a] = temp;
		a--;
	}
	return arr[11];
}

int main(){
	
	//1 задание
	const int n = 3; 
	const int m = 3;
    int array[n][m]={{1,9,2},{5,7,6},{4,3,8}};
	for (int i = 0; i < n; i++)
	{
        for (int j = 0; j < m; j++)
		{
        printf("%d", array[i][j]);
    }
	printf("\n");
	}
	sort(array);
	printf("Sort: \n");
	for (int i = 0; i < n; i++)
	{
        for (int j = 0; j < m; j++)
		{
        printf("%d", array[i][j]);
    }
	printf("\n");
	}
	printf("\n");
    //2 задание
	int arr2[11];
	float chislo;
	for (int i = 0; i < 11; i++){
		scanf("%d", &arr2[i]);
	}
	for (int i = 0; i < 11; i++){
		printf("%4d", arr2[i]);
	}
	printf("\n");
	invert(arr2);
	for (int i = 0; i < 11; i++){
		printf("%4d", arr2[i]);
	}
	printf("\n");
	for (int i = 0; i < 11; i++){
		schet(arr2[i], i);
	}
	
	return 0;
}