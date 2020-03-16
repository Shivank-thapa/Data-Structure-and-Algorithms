#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;


void insertAtFront(Node **head, int num) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = num;
    newNode->next = *head;
    *head = newNode;
}

Node *mergeLists(Node *head1, Node *head2) {
    Node *mergedHead = NULL;
    if(!head1 || !head2)
        return head1==NULL?head2:head1;
    if(head1->data < head2->data) {
        mergedHead = head1;
        head1=head1->next;
    }
    else {
        mergedHead = head2;
        head2=head2->next;
    }
    Node *temp = mergedHead;

    while(head1 && head2) {
        if(head1->data < head2->data) {
            temp->next = head1;
            head1=head1->next;
        }
        else {
            temp->next = head2;
            head2=head2->next;
        }
        temp = temp->next;
    }

    if(head1) {
        temp->next = head1;
    }

    if(head2) {
        temp->next = head2;
    }

    return mergedHead;
}

void printList(Node *head) {
    while(head != NULL) {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}


int main(void) {

    //First sorted list
    Node *head1 = NULL;
    insertAtFront(&head1, 100);
    insertAtFront(&head1, 90);
    insertAtFront(&head1, 80);
    insertAtFront(&head1, 70);
    insertAtFront(&head1, 60);
    printf("First sorted list: ");
    printList(head1);

    //Second sorted list
    Node *head2 = NULL;
    insertAtFront(&head2, 70);
    insertAtFront(&head2, 67);
    insertAtFront(&head2, 65);
    insertAtFront(&head2, 55);
    insertAtFront(&head2, 54);
    insertAtFront(&head2, 54);
    insertAtFront(&head2, 10);
    printf("Second sorted list: ");
    printList(head2);

    Node *mergedHead = mergeLists(head1, head2);
    printf("Merged sorted list: ");
    printList(mergedHead);
    return 0;
}

