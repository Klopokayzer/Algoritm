#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>

#define true 1 == 1
#define false 1 != 1

char* caesar(char* in, int key, bool encrypt){
	if (encrypt == true){
		for(int i = 0; i < strlen(in); i++){
			in[i] += key;
		}
		return in;
	}else {
		for(int i = 0; i < strlen(in); i++){
			in[i] -= key;
		}
		return in;
	}
}

char* shuffle(char* in, int key, bool encrypt){
	int a = strlen(in)/key;
	char in2[a][key] = {0};
	int h = 0;
	int i = 0;
	int j = 0;
	if (encrypt == true){
		for(i = 0; i < a; i++){
			for (j = 0; j < key; j++){
					in2[i][j] = in[h];
					h++;
			}
		}
		h = 0;
		for(j = 0; j < key; j++){
			for (i = 0; i < a; i++){
					in[h]= in2[i][j];
					h++;
			}
		}
		return in;
	}else {
		for(j = 0; j < key; j++){
			for (i = 0; i < a; i++){
					in2[i][j] = in[h];
					h++;
			}
		}
		h = 0;
		for(i = 0; i < a; i++){
			for (j = 0; j < key; j++){
					in[h]= in2[i][j];
					h++;
			}
		}
		return in;
	}
}



int main(){
	//1 задание
	printf("\n---nexercise 1---\n");
	char str[] = "Abc";
	int key = 4;
	printf("%s\n", str);
	caesar(str,key,true);
	printf("%s\n", str);
	caesar(str,key,false);
	printf("%s\n", str);
	
	//2 задание
	printf("\n---nexercise 2---\n");
	printf("\n");
	char str2[] = "This is a secret message.";
	printf("Message:\n%s\n", str2);
	printf("\n");
	shuffle(str2,key,true);
	printf("Message crypt:\n%s\n", str2);
	printf("\n");
	shuffle(str2,key,false);
	printf("Message encrypt:\n%s\n", str2);
	return 0;
}

