#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

void insertAtFront(Node **head, int num) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = num;
    newNode->next = *head;
    *head = newNode;
}

void removeDuplicates(Node **head) {
    Node *curr, *nxt;
    curr = *head;
    if(curr == NULL)
        return;
    while(curr->next != NULL) {
        nxt = curr->next;
        if(curr->data == nxt->data) {
            curr->next = nxt->next;
            free(nxt);
        }
        else {
            curr=curr->next;
        }
    }
}



void printList(Node *head){
    if(head == NULL){
        printf("List is empty!\n");
        return;
    }
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(void) {
    Node *head = NULL;

    insertAtFront(&head, 100);
    insertAtFront(&head, 100);
    insertAtFront(&head, 100);
    insertAtFront(&head, 100);
    insertAtFront(&head, 50);
    insertAtFront(&head, 50);
    insertAtFront(&head, 50);
    insertAtFront(&head, 20);
    insertAtFront(&head, 20);
    insertAtFront(&head, 20);

    printf("Before removing duplicates:");
    printList(head);

    removeDuplicates(&head);

    printf("After removing duplicates:");
    printList(head);

    return 0;
}

