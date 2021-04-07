#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>
#define true 1 == 1
#define false 1 != 1
#define T int
#define SIZE 100

typedef int boolean;
T stack[SIZE];
int cursor = -1;
const int n = 6;

int matrix[n][n] = {
	{0,1,1,0,0,0},
	{0,0,0,1,1,1},
	{0,0,0,0,0,1},
	{1,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,1,0},
};
	
int visited[n] = {0};
	
boolean push(T data){
	if (cursor < SIZE){
		stack[++cursor] = data;
		return true;
	} else {
		printf("%s \n", "Stack overflow");
		return false;
	}
}

T pop(){
	if (cursor != -1){
		return stack[cursor--];
	} else {
		printf("%s \n", "Stack is empty");
		return -1;
	}
}

void depthTravers(int st) {
    int r;
	push(st);
    visited[st] = 1;
    for (r = 0; r < n; ++r) {
        if (matrix[st][r] == 1 && !visited[r]) {
			depthTravers(r);
        }
    }
}

void resetArr() {
    for (int i = 0; i < n; ++i) {
        visited[i] = 0;
    }
}

int main(){
	depthTravers(0);
    resetArr();
    printf("\n");
	while (cursor != -1){
		printf("%d ", pop());
	}
	depthTravers(2);
    resetArr();
    printf("\n");
	while (cursor != -1){
		printf("%d ", pop());
	}
	depthTravers(1);
    resetArr();
    printf("\n");
	while (cursor != -1){
		printf("%d ", pop());
	}
}