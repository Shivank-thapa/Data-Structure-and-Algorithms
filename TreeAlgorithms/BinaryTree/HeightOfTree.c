#include<stdio.h>
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

int height(Node *root) {
    if(!root) {
        return 0;
    }
    int leftHeight = height(root->left);    //calculate height of left subtree
    int rightHeight = height(root->right);  //calculate height of right subtree
    if(leftHeight > rightHeight)
        return leftHeight+1;
    else
        return rightHeight+1;
}

int main(void) {
    Node *root1 = createNode(10);
    root1->left = createNode(20);
    root1->right = createNode(30);
    root1->left->left = createNode(40);
    root1->left->right = createNode(50);
    printf("Height of first tree is: %d\n", height(root1));

    Node *root2 = createNode(1);
    root2->left = createNode(2);
    root2->left->left = createNode(3);
    root2->left->left->left = createNode(4);
    root2->left->left->left->left = createNode(5);
    printf("Height of second tree is: %d\n", height(root2));

    return 0;
}
