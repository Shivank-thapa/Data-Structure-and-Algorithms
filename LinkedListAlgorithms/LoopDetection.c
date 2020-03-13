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

void checkLoop(Node *head){
    if(head == NULL){
        printf("List is empty!\n");
        return;
    }
    while(head != NULL) {
        if(head->visited) {
            printf("Cycle found!\n");
            return;
        }
        head->visited=true;
        head = head->next;
    }
    printf("No cycle found!\n");
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
    checkLoop(head1);

    //LinkedList without loop
    Node *head2 = NULL;
    insertAtFront(&head2, 10);
    insertAtFront(&head2, 50);
    insertAtFront(&head2, 100);
    insertAtFront(&head2, 20);
    insertAtFront(&head2, 30);
    checkLoop(head2);
    return 0;
}
