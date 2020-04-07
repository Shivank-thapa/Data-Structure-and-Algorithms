#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

bool areIdenticalTrees(Node *r1, Node *r2) {
    if(!r1 && !r2)
        return true;
    else if(!r1 || !r2) {
        return false;
    }
    else {
        return (r1->data == r2->data && areIdenticalTrees(r1->left, r2->left) && areIdenticalTrees(r1->right, r2->right));
    }
    return false;
}

int main(void) {
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    Node *root2 = createNode(1);
    root2->left = createNode(3);
    root2->right = createNode(2);
    root2->right->left = createNode(5);
    root2->right->right = createNode(4);

    Node *root3 = createNode(1);
    root3->left = createNode(2);
    root3->right = createNode(3);
    root3->left->left = createNode(4);
    root3->left->right = createNode(5);

    printf("%d\n", areIdenticalTrees(root, root2));
    printf("%d\n", areIdenticalTrees(root, root3));
    return 0;
}

