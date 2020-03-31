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

void printLevel(Node *root, int level) {
    if(!root)
        return;
    if(level == 1)
        printf("%d ", root->data);
    else if(level > 1) {
        printLevel(root->left, level-1);
        printLevel(root->right, level-1);
    }
}

void printLevelOrder(Node *root) {
    int i, h = height(root);

    for(i=1; i<=h; i++) {
        printf("Level %d: ", i);
        printLevel(root, i);
        printf("\n");
    }
}


int main(void) {
    Node *root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);
    root->right->left = createNode(60);
    root->right->right = createNode(70);

    printLevelOrder(root);
    return 0;
}

