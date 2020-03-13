#include<stdio.h>
#include<stdbool.h>
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
    printf("Inserted &d successfully!\n");
}

void deleteNode(Node **head, int position) {
    if(*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node *tmp = *head;
    int i=0;
    if(position == 0) {
        printf("Deleted %d.\n",tmp->data);
        *head = tmp->next;
        free(tmp);
        return;
    }
    while(i<position-1) {
        tmp = tmp->next;
        if(tmp == NULL || tmp->next == NULL) {
            printf("Invalid index!\n");
            return;
        }
        i++;
    }

    Node *nxt = tmp->next->next;
    printf("Deleted %d.\n", tmp->next->data);
    free(tmp->next);
    tmp->next=nxt;
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
    Node *root = NULL;
    int choice, num;
    bool flag = true;

    do {
        printf("Enter operation to perform\n");
        printf("1.Insert\n2.Delete\n3.Print List\n4.Exit\n");
        scanf("%d", &choice);
        switch(choice) {
        case 1:
            printf("Enter element to insert at beginning: ");
            scanf("%d", &num);
            insertAtFront(&root, num);
            break;
        case 2:
            printf("Enter index of element to delete: ");
            scanf("%d",&num);
            deleteNode(&root, num);
            break;
        case 3:
            printList(root);
            break;
        case 4:
            flag = false;
            break;
        default:
            printf("Enter a valid choice!\n");
        }
    } while(flag);
    return 0;
}
