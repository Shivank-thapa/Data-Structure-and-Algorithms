#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    bool visited;
    struct Node *next;
}Node;

void insertAtFront(Node **head, int num) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = num;
    newNode->next = *head;
    newNode->visited=false;
    *head = newNode;
}

int findLen(Node *start) {
    int len=1;
    Node *temp = start;
    while(temp->next != start) {
        temp = temp->next;
        len++;
    }
    return len;
}

int checkLoop(Node *head){
    Node *slowPtr = head, *fastPtr = head;
    while(slowPtr && fastPtr && fastPtr->next){
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if(slowPtr == fastPtr)
            return findLen(slowPtr);
    }
    return 0;
}

int main(void) {

    //LinkedList with loop
    Node *head1 = NULL;
    insertAtFront(&head1, 10);
    insertAtFront(&head1, 50);
    insertAtFront(&head1, 100);
    insertAtFront(&head1, 20);
    insertAtFront(&head1, 30);
    head1->next->next->next->next->next = head1->next;
    printf("Length of loop is: %d\n",checkLoop(head1));

    //LinkedList without loop
    Node *head2 = NULL;
    insertAtFront(&head2, 10);
    insertAtFront(&head2, 50);
    insertAtFront(&head2, 100);
    insertAtFront(&head2, 20);
    insertAtFront(&head2, 30);
    printf("Length of loop is: %d\n",checkLoop(head2));
    return 0;
}

