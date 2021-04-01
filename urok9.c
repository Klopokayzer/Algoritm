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

typedef struct {
	Node* arr[SZ];
	int tail;
	int items;
} PriorQueue;

bool queueIsEmpty(PriorQueue* Queue){
    return Queue && Queue->items == 0;
}

bool queueIsFull(PriorQueue* Queue){
    return Queue && Queue->items == SZ;
}

void printNode(Node* NodeToPrint){
    if (NodeToPrint == NULL)
        printf("[*, *] ");
    else
        printf("[%d, %d] ", NodeToPrint->pr, NodeToPrint->dat);
}

void pritnQ(PriorQueue* Queue){
	if (Queue == NULL)
        printf("%s \n", "Queue is NULL!");

    printf("[ ");

    for (int i = 0; i < Queue->tail; ++i)
        printNode(Queue->arr[i]);    
    
    printf(" ]\n");
}

void init(PriorQueue* Queue){
	if (Queue == NULL){
        printf("%s \n", "Queue is NULL!");
        return;    
    }
	Queue->tail = 0;
    Queue->items = 0;
    for (int i = 0; i < SZ; ++i) {
        Queue->arr[i] = NULL;
    }
}

void ins(PriorQueue* Queue, int pr, int dat){
	if (Queue == NULL){
        printf("%s \n", "Queue is NULL!");
        return;    
    }

    if (queueIsFull(Queue)){
        printf("%s \n", "Queue is full!");
        return;    
    }
    
    Node *node = (Node*) malloc(sizeof(Node));
    node->pr = pr;
    node->dat = dat;
    Queue->arr[Queue->tail] = node;
    Queue->tail++;
    Queue->items++;
}

Node* removeFromQueue(PriorQueue* Queue){
    if (Queue == NULL){
        printf("%s \n", "Queue is NULL!");
        return NULL;
    }

    if (queueIsEmpty(Queue)) {
        printf("%s \n", "Queue is empty!");
        return NULL;
    }
    int maxPriority = Queue->arr[0]->pr;
    int idxOfMaxPriorityElement = 0;
    for (int i = 1; i < Queue->items; ++i) {
        if (Queue->arr[i]->pr > maxPriority) {
            maxPriority = Queue->arr[i]->pr;
            idxOfMaxPriorityElement = i;
        }
    }
    Node *tmp = Queue->arr[idxOfMaxPriorityElement];
    while (idxOfMaxPriorityElement < Queue->items) {
        Queue->arr[idxOfMaxPriorityElement] = Queue->arr[idxOfMaxPriorityElement + 1];
        idxOfMaxPriorityElement++;
    }
    Queue->items--;
    Queue->tail--;
    return tmp;
}


//для второго задания
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
	PriorQueue* NewQueue = (PriorQueue*) malloc(sizeof(PriorQueue));
	init(NewQueue);
	ins(NewQueue, 1, 11);
	ins(NewQueue, 5, 22);
	ins(NewQueue, 3, 33);
	ins(NewQueue, 2, 44);
	ins(NewQueue, 7, 55);
	ins(NewQueue, 2, 66);
	ins(NewQueue, 5, 77);
	ins(NewQueue, 9, 88);
	ins(NewQueue, 1, 99);
	ins(NewQueue, 3, 100);
	pritnQ(NewQueue);
	Node* RemoveNode1 = removeFromQueue(NewQueue);
	pritnQ(NewQueue);
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