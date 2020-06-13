#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
}Node;

Node *createNode(int d) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = d;
    p->left = NULL;
    p->right = NULL;
    p->parent = NULL;
    
    return p;
}

Node * insertNode(Node *root, int data) {
    if(root == NULL)
        return createNode(data);
    
    Node *p;
    if(data <= root->data) {
        p = insertNode(root->left, data);
        root->left = p;
        p->parent = root;
    }
    
    else {
        p = insertNode(root->right, data);
        root->right = p;
        p->parent = root;
    }
    return root;
}

void inOrder(Node *root) {
    if(root) {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

Node *min(Node *p) {
    Node *tmp = p;
    while(tmp->left) {
        tmp = tmp->left;
    }
    return tmp;
}

Node *successor(Node *x) {
    if(x->right) {
        return min(x->right);
    }
    Node *y = x->parent;
    while(y && x == y->right) {
        x = y;
        y = y->parent;
    }
    return y;
}

int main(void) {
	Node *root = NULL;
	root = insertNode(root, 20);
	root = insertNode(root, 8);
	root = insertNode(root, 22);
	root = insertNode(root, 4);
	root = insertNode(root, 12);
	root = insertNode(root, 10);
	root = insertNode(root, 14);
	printf("In order traversal is: ");
	inOrder(root);
	Node * x = successor(root->left->right->right);
	printf("\nSuccessor of %d is %d\n",root->left->right->right->data, x->data);
	
	return 0;
}


