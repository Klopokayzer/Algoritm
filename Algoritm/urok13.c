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

typedef struct {
    struct TwoLinkNode *head;
    struct TwoLinkNode *tail;
    int size;
} TwoLinkList;

typedef struct TwoLinkNode {
    int dat;
    struct TwoLinkNode *next;
    struct TwoLinkNode *prev;
} TwoLinkNode;

typedef int boolean;
T stack[SIZE];
int cursor = -1;
const int n = 6;

int matrix[n][n] = {
	{0,1,1,0,0,0},
	{1,0,0,1,1,1},
	{1,0,0,0,0,1},
	{1,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,1,0},
};
	
int visited[n] = {0};

void set2dInt(int** array, const int row, const int col, int value) {
    *((*(array + row)) + col) = value;
}	

int get2dInt(int** array, const int row, const int col) {
    return *((*(array + row)) + col);

}

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

void initTwoLinkList(TwoLinkList *lst) {
    lst->head = NULL;
    lst->tail = NULL;
    lst->size = 0;
}



void setLineValues(int** matrix, int cols, int row, ...) {
    va_list args;
    va_start(args, row);
    for (int i = 0; i < cols; ++i) {
        set2dInt(matrix, row, i, va_arg(args, int));
    }
    va_end(args);
}

void printIntArray(int* array, int size, int offset) {
    char format[7];
    sprintf(format, "%%%dd", offset);
    for (int i = 0; i < size; ++i) {
        printf(format, array[i]);
        if (i != size - 1)
            printf(",");
    }
    printf("\n");
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

int** init2dIntArray(int** array, const int row, const int col) {
    array = (int**) calloc(sizeof(int*), row);
    for (int i = 0; i < row; ++i) {
        *(array + i) = (int*) calloc(sizeof(int), col);
    }
    return array;
}

void resetArr() {
    for (int i = 0; i < n; ++i) {
        visited[i] = 0;
    }
}

void adjacencyCount (int** matrix, const int size, int* adjacencyLinks) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix[j][i] == 1 && i != j) 
                adjacencyLinks[i]++;
        }
    }
}

int** CreateGraph(){
    int** adj = init2dIntArray(adj, n, n);
    //                                  A  B  C  D  E  F
    setLineValues(adj, n,  0,  0, 1, 0, 1, 0, 0); // A
    setLineValues(adj, n,  1,  1, 0, 1, 1, 0, 0); // B
    setLineValues(adj, n,  2,  0, 1, 0, 0, 0, 0); // C
    setLineValues(adj, n,  3,  1, 1, 0, 0, 0, 0); // D
    setLineValues(adj, n,  4,  0, 0, 0, 0, 0, 1); // E
    setLineValues(adj, n,  5,  0, 0, 0, 0, 1, 0); // F

    return adj;
}

boolean TwoLinkEnqueue(TwoLinkList *queue, T value) {
    TwoLinkNode *tmp = (TwoLinkNode*) malloc(sizeof(TwoLinkNode));
    if (tmp == NULL) {
        printf("Out of memory! \n");
        return false;
    }
    tmp->dat = value;
    tmp->next = NULL;
    tmp->prev = queue->tail;

    if (queue->tail != NULL) {
        queue->tail->next = tmp;
    }
    if (queue->head == NULL) {
        queue->head = tmp;
    }

    queue->tail = tmp;
    queue->size++;
    return true;
}

T TwoLinkDequeue(TwoLinkList *queue) {
    if (queue->size == 0) {
        printf("Queue is empty \n");
        return -1;
    }
    TwoLinkNode *tmp = queue->head;
    T data = queue->head->dat;

    queue->head = queue->head->next;

    if (queue->head != NULL) {
        queue->head->prev = NULL;
    }
    if (tmp == queue->tail) {
        queue->tail = NULL;
    }

    free(tmp);
    queue->size--;
    return data;
}

void traversalCount (int** matrix, int start, const int size, int* traversalLinks) {
    bool visit[n] = {false};
    TwoLinkList* queue = (TwoLinkList*) malloc(sizeof(TwoLinkList));
    initTwoLinkList(queue);
    TwoLinkEnqueue(queue, start);
    while (queue->size > 0) {
        int indx = TwoLinkDequeue(queue);
        if (visit[indx]) 
            continue;

        visit[indx] = true;
        for (int i = 0; i < size; ++i) {
            if (get2dInt(matrix, indx, i) == 1) {
                if (i != indx)
                    traversalLinks[i]++;
                if (!visit[i])
                    TwoLinkEnqueue (queue, i);
            }
        }
    }
}

int main(){
	//1 задание
	printf("Exercise 1");
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
	printf("\n \n Exercise 2a \n");
	//2 задание
	
	int adjacencyLinks[n] = {0};
	int** graph = CreateGraph();
	adjacencyCount(graph, n, adjacencyLinks);
    printIntArray(adjacencyLinks, n, 3);
	printf("\n Exercise 2b \n");
	int traversalLinks[n] = {0};
	traversalCount(graph, 0, n, traversalLinks);
    printIntArray(traversalLinks, n, 3);
	
}