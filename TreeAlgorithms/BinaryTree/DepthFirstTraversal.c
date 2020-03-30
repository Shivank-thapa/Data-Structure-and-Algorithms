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

/* Print inorder traversal of tree */
void printInorder(Node *head) {
    if(!head) {
        return;
    }
    printInorder(head->left);
    printf("%d ", head->data);
    printInorder(head->right);
}

/* Print preorder traversal of tree */
void printPreorder(Node *head) {
    if(!head) {
        return;
    }
    printf("%d ", head->data);
    printPreorder(head->left);
    printPreorder(head->right);
}

/* Print postorder traversal of tree */
void printPostorder(Node *head) {
    if(!head) {
        return;
    }
    printPostorder(head->left);
    printPostorder(head->right);
    printf("%d ", head->data);
}


int main(void) {
    Node *head = createNode(10);
    head->left = createNode(20);
    head->right = createNode(30);
    head->left->left = createNode(40);
    head->left->right = createNode(50);
    head->right->left = createNode(60);
    head->right->right = createNode(70);

    printf("Inorder traversal: ");
    printInorder(head);
    printf("\n");

    printf("Preorder traversal: ");
    printPreorder(head);
    printf("\n");

    printf("Postorder traversal: ");
    printPostorder(head);
    printf("\n");
    return 0;
}
