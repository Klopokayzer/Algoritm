#include <stdio.h>
#include <stdlib.h>
#define true 1 == 1
#define false 1 != 1
#include "geek.h"


/*typedef struct OneLinkNode {
	int dat;
	struct OneLinkNode *next;
} OneLinkNode;

typedef struct {
	OneLinkNode *head;
	int size;
} OneLinkList;*/

OneLinkNode n;
OneLinkList l;


void initOneLinkList(OneLinkList *lst) {
    lst->head = NULL;
    lst->size = 0;
}

void printOneLinkIntNode(OneLinkNode *n) {
    if (n == NULL) {
        printf("[]");
        return;
    }
    printf("[%d]", n->dat);
}

void insetCyclin(OneLinkList *lst, int data){
	OneLinkNode *part = (OneLinkNode*) malloc(sizeof(OneLinkNode));
	part->dat = data;
	part->next = lst->head;
	
	OneLinkNode *current = lst->head;
	if (current == NULL){
		lst->head = part;
		part->next = lst->head;
		lst->size++;
		return;
	} else {
		while (current->next != lst->head){
			current= current->next;
		}
		current->next = part;
		lst->size++;
	}
}



OneLinkNode* removeCyclin(OneLinkList *lst, int data){
	OneLinkNode *current = lst-> head;
	OneLinkNode *parent = NULL;
	
	if (current == NULL){
		return NULL;
	}
	while (current->next != lst->head && current->dat != data){
		parent=current;
		current=current->next;
	}
	if(current->dat != data){
		return NULL;
	}
	if(current==lst->head){
		if(current->next == lst->head){
			lst->head = NULL;
			lst->size--;
			return current;
		} else {
			OneLinkNode *tmp = current;
			while (current->next != lst->head){
				current = current->next;
			}
			lst->head = tmp->next;
			current->next = lst->head;
			lst->size--;
			return tmp;
		}
	}
	parent->next=current->next;
	lst->size--;
	return current;
}

void printCyclinIntList (OneLinkList *lst){
	OneLinkNode *current = lst->head;
	if(current==NULL){
		printOneLinkIntNode(current);
	}else {
		do {
			printOneLinkIntNode(current);
			current = current->next;
		} while (current != lst-> head);
	}
	printf(" Size: %d \n", lst->size);
}

/*void sortirovkaup(OneLinkList *lst){
	OneLinkNode *current = lst->head;
	if (OneLinkNode->dat < OneLinkNode->dat->next){
		while (current != lst-> head);{
			current = current->next;
		}
		printf("True");
	} else {
		printf("False");
	}
}*/

int main (){
	OneLinkList *l = (OneLinkList*) malloc(sizeof(OneLinkList));
	initOneLinkList(l);
	printCyclinIntList(l);
	insetCyclin(l, 1);
	insetCyclin(l, 20);
	insetCyclin(l, 10);
	printCyclinIntList(l);
	/*sortirovkaup(l);*/

}