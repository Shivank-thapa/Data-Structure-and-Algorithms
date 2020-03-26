#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

void insertNode(Node **head, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *head;
    if(*head != NULL)
        (*head)->prev = newNode;
    *head = newNode;
    printf("Inserted %d\n", data);
}

void deleteNode(Node **head) {
    int data;
    Node *tmp = *head;
    if(*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    data = (*head)->data;
    *head = (*head)->next;
    free(tmp);
    printf("Deleted %d\n", data);
}

void printList(Node *head) {
    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("Your list is: NULL");
    while(head) {
        printf("<-%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main(void) {
    int choice, data;
    bool flag = true;
    Node *head = NULL;

    do {
        printf("Enter your choice:\n");
        printf("1.Insert in front\n2.Delete from front\n3.Print List\n4.Quit\n");
        scanf("%d", &choice);
        switch(choice) {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &data);
            insertNode(&head, data);
            break;
        case 2:
            deleteNode(&head);
            break;
        case 3:
            printList(head);
            break;
        case 4:
            flag = false;
            break;
        default:
            printf("Enter a valid choice\n");
        }
    }while(flag);
    return 0;
}
