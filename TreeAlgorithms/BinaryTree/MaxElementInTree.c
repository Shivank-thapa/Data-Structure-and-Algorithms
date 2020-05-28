#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int getMax(Node *root) {
    int max = INT_MIN;
    
    if(root != NULL) {
        int rootData = root->data;
        int leftData = getMax(root->left);
        int rightData = getMax(root->right);
        
        if(leftData > rightData)
            max = leftData;
        else
            max = rightData;
        
        if(max < rootData)
            max = rootData;
    }
    return max;
}

int main(void) {
    Node *root = createNode(1);
    root->left = createNode(11);
    root->right = createNode(900);
    root->left->left = createNode(54);
    root->left->right = createNode(123);
    root->right->right = createNode(21);
    
    int max = getMax(root);
    
    if(max != INT_MIN)
        printf("Max element is %d.", max);
    else
        printf("Tree is empty!");
	return 0;
}


