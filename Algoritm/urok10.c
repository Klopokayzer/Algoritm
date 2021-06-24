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

void printOneLinkIntNode(OneLinkNode *n) {
    if (n == NULL) {
        printf("[]");
        return;
    }
    printf("[%d]", n->dat);
}

void printOneLinkIntList(OneLinkList *lst) {
    OneLinkNode *current = lst->head;
    if (current == NULL) {
        printOneLinkIntNode(current);
    } else {
        do {
            printOneLinkIntNode(current);
            current = current->next;
        } while (current != NULL);
    }
    printf(" Size: %d \n", lst->size);
}

T popOneLinkStack(OneLinkList *stack) {
    if (stack->size == 0) {
        printf("Stack is empty \n");
        return -1;
    }
    OneLinkNode *tmp = stack->head;
    T data = stack->head->dat;
    stack->head = stack->head->next;
    free(tmp);
    stack->size--;
    return data;
}

boolean pushOneLinkStack(OneLinkList *stack, T value) {
    OneLinkNode *tmp = (OneLinkNode*) malloc(sizeof(OneLinkNode));
    if (tmp == NULL) {
        printf("Stack overflow \n");
        return false;
    }
    tmp->dat = value;
    tmp->next = stack->head;

    stack->head = tmp;
    stack->size++;
    return true;
}

void initOneLinkList(OneLinkList *lst) {
    lst->head = NULL;
    lst->size = 0;
}

void freeOneLinkStack(OneLinkList *stack){
    while(stack->size != 0)
        popOneLinkStack(stack);
    
    free(stack);
}

bool CharIsOpeningBrace(char* CharToCheck, char bracesArr[][2], int bracesTypes){
    for (int i = 0; i < bracesTypes; ++i) {
        if (*CharToCheck == bracesArr[i][0])
            return true;
    }

    return false;
}

bool CharIsClosingBrace(char* CharToCheck, char bracesArr[][2], int bracesTypes){
    for (int i = 0; i < bracesTypes; ++i) {
        if (*CharToCheck == bracesArr[i][1])
            return true;
    }

    return false;
}

bool BracesMatchEachOther(char OpeningBrace, char ClosingBrace, char bracesArr[][2], int bracesTypes){
    for (int i = 0; i < bracesTypes; ++i) {
        if (OpeningBrace == bracesArr[i][0] && ClosingBrace == bracesArr[i][1]){
            return true;
        }
    }

    return false;
}

bool bracesCheck(char* expression) {
    if (expression == NULL)
        return true;
    const int bracesTypesNum = 4;
    char braces[][2] = {
        {'(', ')'}, 
        {'{', '}'}, 
        {'[', ']'}, 
        {'<', '>'}
    };
    OneLinkList *Stack = (OneLinkList*) malloc(sizeof(OneLinkList));
    initOneLinkList(Stack);
    bool BracesAreBalanced = true;
    while (*expression != '\0') {
        if (CharIsOpeningBrace(expression, braces, bracesTypesNum))
        {
            pushOneLinkStack(Stack, *expression);
        }  
        else if (CharIsClosingBrace(expression, braces, bracesTypesNum))
        {
            if (Stack->head == NULL)
            {
                pushOneLinkStack(Stack, *expression);
                BracesAreBalanced = false;
                break;
            }
            else if (BracesMatchEachOther((char) Stack->head->dat, *expression, braces, bracesTypesNum))
            {
                popOneLinkStack(Stack);
            }
            else
            {
                pushOneLinkStack(Stack, *expression);
                BracesAreBalanced = false;
                break;
            }
        }
        expression++;
    }
    if (Stack->head == NULL)
        BracesAreBalanced = true;
    freeOneLinkStack(Stack);
    return BracesAreBalanced;
}

void copyList(OneLinkList* from, OneLinkList* to) {
    int ElementsLeftToCopy = from->size;
    OneLinkNode *current = from->head;
    while (ElementsLeftToCopy != 0) { 
        for (int i = 0; i < ElementsLeftToCopy - 1; ++i) {
            current = current->next;
        }
        pushOneLinkStack(to, current->dat);
		ElementsLeftToCopy--;
        current = from->head;
    }
}

bool isAscendingSorted(OneLinkList *lst) {
    OneLinkNode *current = lst->head;
    while (current->next != NULL) {
        if (current->dat > current->next->dat)
            return false;
        current = current->next;
    }
    return true;
}

/*void printOneLinkIntNode(OneLinkNode *n) {
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



/*OneLinkNode* removeCyclin(OneLinkList *lst, int data){
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
	printf("Zadan1\n");
	printf("Braces are%s balanced \n", bracesCheck("") ? "" : " not");                     
    printf("Braces are%s balanced \n", bracesCheck(")") ? "" : " not");                    
    printf("Braces are%s balanced \n", bracesCheck("() ( { () [ {} ] } )") ? "" : " not"); 
    printf("Braces are%s balanced \n", bracesCheck("{ ( }") ? "" : " not");                
    printf("Braces are%s balanced \n", bracesCheck("[2/{5*(4+7)}]") ? "" : " not");   
	
	printf("Zadan2\n");
	OneLinkList* originalList = (OneLinkList*) malloc(sizeof(OneLinkList));
    initOneLinkList(originalList);
    for (int i = 9; i > 0; --i) {
        pushOneLinkStack(originalList, i);
    }
    OneLinkList* listCopy = (OneLinkList*) malloc(sizeof(OneLinkList));
    initOneLinkList(listCopy); 
    printOneLinkIntList(originalList);
    copyList(originalList, listCopy);
    printOneLinkIntList(listCopy);
    freeOneLinkStack(originalList);
    freeOneLinkStack(listCopy);
	
	printf("Zadan3\n");
	OneLinkList* sortedList = (OneLinkList*) malloc(sizeof(OneLinkList));
    initOneLinkList(sortedList);
    for (int i = 9; i > 0; --i) {
        pushOneLinkStack(sortedList, i);
    }
    printf("List: ");
    printOneLinkIntList(sortedList);
    printf("is%s in ascending order\n\n", isAscendingSorted(sortedList) ? "" : " not");
    freeOneLinkStack(sortedList);
	
	
	
	/*OneLinkList *l = (OneLinkList*) malloc(sizeof(OneLinkList));
	initOneLinkList(l);
	printCyclinIntList(l);
	insetCyclin(l, 1);
	insetCyclin(l, 20);
	insetCyclin(l, 10);
	printCyclinIntList(l);
	/*sortirovkaup(l);*/

}