#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

bool checkChildrenSum(Node *root) {
    if(!root || (!(root->left) && !(root->right)))
        return true;
    int lData=0, rData=0;

    if(root->left)
        lData = root->left->data;
    if(root->right)
        rData = root->right->data;

    if((root->data == lData + rData) && checkChildrenSum(root->left) && checkChildrenSum(root->right))
        return true;
    else
        return false;
}

int main(void) {
    Node *root1 = createNode(10);
    root1->left = createNode(8);
    root1->right = createNode(2);
    root1->left->left = createNode(3);
    root1->left->right = createNode(5);
    root1->right->left = createNode(2);

    checkChildrenSum(root1) ? printf("Children sum property satisfied!\n") : printf("Children sum property not satisfied");

    return 0;
}
