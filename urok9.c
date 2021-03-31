#include <stdio.h>
#include <stdlib.h>
#define SZ 10
#define T int
#define SIZE 100
#define true 1 == 1
#define false 1 != 1

T stack[SIZE];
int cursor = -1;
typedef int boolean;

typedef struct {
	int pr;
	int dat;
} Node;

Node* arr[SZ];
int head;
int tail;
int items;

void pritnQ(){
	printf("[ ");
	for(int i = 0; i < SZ; ++i){
		if (arr[i]==NULL)
			printf("[*, *] ");
		else
			printf("[%d, %d] ", arr[i]->pr, arr[i]->dat);
	}
	printf(" ]\n");
}

void init(){
	for(int i = 0; i < SZ; ++i){
		arr[i] = NULL;
	}
	head = 0;
	tail = 0;
	items = 0;
}

void ins(int pr, int dat){
	Node *node = (Node*) malloc(sizeof(Node));
	node->dat = dat;
	node->pr = pr;
	if (items == 0){
		arr[tail++] = node;
		items++;
	} else if (items == SZ){
		printf("%s \n", "Queue is full");
		return;
	} else {
		arr[tail++] = node;
		items++;
	}
}

/*Node* rem(){
	if (items == 0) {
		return NULL;
	} else {
		int flag;
		for(int i = 0; i < SZ; i++){
			if(flag < arr[i]->pr){
				flag = arr[i]->pr;
			}
		}
		for(int i = 0; i < SZ; i++){
			if (flag >= arr[i]->pr){
				Node *tmp = arr[i];
				arr[i] = NULL;
				items--;
				return tmp;
			}
		}
	}
}
*/

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

void binRec(int n){
	if (n <=0)
		return;
	push(n % 2);
	binRec(n/2);
}

int main(){
	//1 задание
	init();
	ins(1, 11);
	ins(5, 22);
	ins(3, 33);
	ins(2, 44);
	ins(7, 55);
	ins(2, 66);
	ins(5, 77);
	ins(9, 88);
	ins(1, 99);
	ins(3, 100);
	pritnQ();
	/*for(int i = 0; i < 7; ++i){
		Node* n = rem();
		printf("pr=%d, dat=%d \n", n->pr, n->dat);
	}
	с удаление исключением я не разобрался, компилятор выдаёт ошибку
	 "warning: control reaches end of non-void function [-Wreturn-type]
	pritnQ();*/
	
	//2 задание
	binRec(25);
	printf("\n");
	while (cursor != -1){
		printf("%d", pop());
	}
	printf("\n");
	pop();
	return 0;
}