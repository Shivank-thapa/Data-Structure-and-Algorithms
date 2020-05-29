#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define LIMIT 20

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *rightSibling;
}Node;

Node *createNode(int data) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    p->rightSibling = NULL;
    
    return p;
}

void connectRightSiblings(Node *root) {
    if(!root)
        return;
    if(root->left)
        root->left->rightSibling = root->right;
    if(root->right)
        root->right->rightSibling = (root->rightSibling)?root->rightSibling->left:NULL;
    connectRightSiblings(root->left);
    connectRightSiblings(root->right);
}  

int main(void) {
	Node *root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);
    root->right->left = createNode(60);
    root->right->right = createNode(70);
    
    connectRightSiblings(root);
	return 0;
}


