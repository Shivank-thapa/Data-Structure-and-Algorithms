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

void printList(Node *head) {
    while(head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void reverseList(Node **head) {
    Node *prev = NULL;
    Node *curr = *head;
    Node *nxt = NULL;

    while(curr) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    *head = prev;
}

int main(void) {
    Node *head = NULL;
    addToBeginning(&head, 50);
    addToBeginning(&head, 40);
    addToBeginning(&head, 30);
    addToBeginning(&head, 20);
    addToBeginning(&head, 10);

    printf("List before reversal: ");
    printList(head);

    reverseList(&head);

    printf("List after reversal: ");
    printList(head);
    return 0;
}

