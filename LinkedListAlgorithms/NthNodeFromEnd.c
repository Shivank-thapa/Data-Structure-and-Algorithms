#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

void addToBeginning(Node **head, int data) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

void findNode(Node *head, int n) {
    Node *frontPtr = head;
    Node *rearPtr = head;

    while(n > 0) {
        frontPtr = frontPtr->next;
        n--;
    }
    while(frontPtr) {
        frontPtr = frontPtr->next;
        rearPtr = rearPtr->next;
    }
    printf("%d\n", rearPtr->data);
}

int main(void) {
    Node *head = NULL;
    addToBeginning(&head, 50);
    addToBeginning(&head, 40);
    addToBeginning(&head, 30);
    addToBeginning(&head, 20);
    addToBeginning(&head, 10);

    int n = 3;
    findNode(head, n);
    return 0;
}


