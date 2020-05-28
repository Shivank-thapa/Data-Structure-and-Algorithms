#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;


Node *createNode(int x){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

int sum(Node *root) {
    if(root == NULL)
        return 0;
    return (sum(root->left) + sum(root->right) + root->data);
}

int main(void) {
    Node *root = createNode(1);
    root->left = createNode(11);
    root->right = createNode(9);
    root->left->left = createNode(2);
    root->left->right = createNode(3);
    root->right->right = createNode(5);
    
    printf("Sum of all nodes of the tree is : %d\n",sum(root));
	return 0;
}

