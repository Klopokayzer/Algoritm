#include "geek.h"

/*typedef struct Node {
	int key;
	struct Node *left;
	struct Node *right;
} TreeNode;

TreeNode* treeInsert(TreeNode *t, int data){
	TreeNode *newNode;
	newNode = (TreeNode*) malloc(sizeof(TreeNode));
	newNode->key = data;
	newNode->left = NULL;
	newNode->right = NULL;
	TreeNode *current = t;
	TreeNode *parent = t;
	if (t == NULL) {
		t = newNode;
	} else {
		while (current->key != data){
			parent = current;
			if (current->key > data){
				current = current->left;
				if (current == NULL){
					parent->left = newNode;
					return t;
				}
			} else {
				current = current->right;
				if (current == NULL){
					parent->right = newNode;
					return t;
				}
			}
		}
	}
	return t;
}

void printTree(TreeNode *root){
	if (root){
		printf("%d", root->key);
		if (root->left || root->right){
			printf("(");
			if (root->left)
				printTree(root->left);
			else
				printf("NULL");
			printf(",");
			if (root->right)
				printTree(root->right);
			else
				printf("NULL");
			printf(")");
		}
	}
}*/

BinTreeIntNode* treeInsert(BinTreeIntNode *t, int data) {
    BinTreeIntNode *newNode;
    newNode = (BinTreeIntNode*) malloc(sizeof(BinTreeIntNode));
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    BinTreeIntNode *current = t;
    BinTreeIntNode *parent = t;
    if (t == NULL) {
        t = newNode;
    } else {
        while (current->key != data) {
            parent = current;
            if (current->key > data) {
                current = current->left;
                if (current == NULL) {
                    parent->left = newNode;
                    return t;
                }
            } else {
                current = current->right;
                if (current == NULL) {
                    parent->right = newNode;
                    return t;
                }
            }
        }
    }
    return t;
}

void printBinTree(BinTreeIntNode *root) {
    if (root) {
        printf("%d", root->key);
        if (root->left || root->right) {
            printf("(");
            if (root->left)
                printBinTree(root->left);
            else
                printf("NULL");
            printf(",");
            if (root->right)
                printBinTree(root->right);
            else
                printf("NULL");
            printf(")");
        }
    }
}

BinTreeIntNode* getSuccessor(BinTreeIntNode *node) {
    BinTreeIntNode *current = node->right;
    BinTreeIntNode *parent = node;
    BinTreeIntNode *s = node;

    while (current != NULL) {
        parent = s;
        s = current;
        current = current->left;
    }
    if (s != node->right) {
        parent->left = s->right;
        s->right = node->right;
    }
    return s;
}

boolean treeNodeDelete(BinTreeIntNode *root, int key) {
    BinTreeIntNode *current = root;
    BinTreeIntNode *parent = root;
    boolean isLeftChild = true;

    while (current->key != key) {
        parent = current;
        if (key < current->key) {
            current = current->left;
            isLeftChild = true;
        } else {
            current = current->right;
            isLeftChild = false;
        }
        if (current == NULL)
            return false;
    }

    if (current->left == NULL && current->right == NULL) {
        if (current == root)
            root = NULL;
        else if (isLeftChild)
            parent->left = NULL;
        else
            parent->right = NULL;
    }
    else if (current->right == NULL) {
        if (isLeftChild)
            parent->left = current->left;
        else
            parent->right = current->left;
    }
    else if (current->left == NULL) {
        if (isLeftChild)
            parent->left = current->right;
        else
            parent->right = current->right;
    }
    else {
        BinTreeIntNode *successor = getSuccessor(current);
        if (current == root)
            root = successor;
        else if (isLeftChild)
            parent->left = successor;
        else
            parent->right = successor;
        successor->left = current->left;
    }
    return true;
}

bool isBalanced(BinTreeIntNode *root){
	int r = 0;
	int l = 0;
	while (root->left != NULL){
		l++;
		isBalanced(root->left);
	}
	while (root->right != NULL){
		r++;
		isBalanced(root->right);
	}
	if (r == l){
		return true;
	} else {
		return false;
	}
}

BinTreeIntNode* searchNode(BinTreeIntNode *root, int data){
	if(root->left && root->right != NULL){
	while (root->left != NULL){
		if (root->key==data){
			return root;
		} else {
			searchNode(root->left);
		}
	}
	while (root->right != NULL){
		if (root->key==data){
			return root;
		} else {
			searchNode(root->right);
		}
	}
	} else {
		return NULL;
	}
}

int main(){
	/*TreeNode *tree = treeInsert(tree, 25);
	treeInsert(tree, 8);
	treeInsert(tree, 12);
	treeInsert(tree, 15);
	treeInsert(tree, 29);
	treeInsert(tree, 87);
	treeInsert(tree, 48);
	treeInsert(tree, 2);
	treeInsert(tree, 12);
	printTree(tree);
	printf("\n");*/
	//1 задание
	BinTreeIntNode *tree = treeInsert(tree, 10);
    treeInsert(tree, 8);
    treeInsert(tree, 19);
    treeInsert(tree, 5);
    treeInsert(tree, 9);
    treeInsert(tree, 16);
    treeInsert(tree, 21);
    printBinTree(tree);
    printf(" \n");
	printf("Tree is balance: %d",isBalanced(tree));
	//2 задание
	int BS = 0;
	float trees = 50;
	for (int i = 1; i <= 50; i++){
		TreeNode *i = treeInsert(i, rand()%10000)
		for (int k = 0; k < 10000; k++){
			treeInsert(i, rand()%10000);
		}
		if(isBalanced(i)==true){
			BS++
		};
	}
	printf("Tree is balance %d%%.\n", BS/trees*100);
	//3 задание
	printf("%d", searchNode(tree, 12);
}