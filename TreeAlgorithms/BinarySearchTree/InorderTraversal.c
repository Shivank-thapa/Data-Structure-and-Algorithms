#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node *createNode(int data) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;

    return p;
}

Node *insertNode(Node *node, int data) {
    if(node == NULL) {
        return createNode(data);
    }
    if(data < node->data) {
        node->left = insertNode(node->left, data);
    }
    else if(data > node->data) {
        node->right = insertNode(node->right, data);
    }
    return node;
}

void inOrder(Node *root) {
    if(!root) {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

int main(void){
    Node *root = insertNode(NULL, 10);
    insertNode(root, 20);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 7);
    insertNode(root, 25);

    inOrder(root);
    return 0;
}
