#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;

void insertAtEnd(Node **head, int data) {
	Node *p = (Node *)malloc(sizeof(Node));
	p->data = data;	
	p->next = p;
	
	if(*head == NULL) {
		*head = p;
	}
	else {
		Node *tmp = *head;
		while(tmp->next != *head){
			tmp = tmp->next;
		} 
		tmp->next = p;
		p->next = *head;
	}
}

void insertAtBeginning(Node **head, int data){
	Node *p = (Node *)malloc(sizeof(Node));
	p->data = data;
	p->next = p;
	if(*head == NULL){
		*head = p;
	}
	else {
		Node *tmp = *head;
		while(tmp->next != *head) {
			tmp = tmp->next;
		}
		tmp->next = p;
		p->next = *head;
		*head = p;
	}
}

void deleteFromBeginning(Node **head){
	if(*head == NULL) {
		printf("List is empty!\n");
		return;
	}
	Node *tmp = *head;
	Node *head2 = *head;
	while(tmp->next != *head) {
		tmp = tmp->next;
	}
	tmp->next = (*head)->next;
	*head = (*head)->next;
	free(head2);
}

void printList(Node *head) {
	if(head == NULL) {
		printf("List is empty!");
		return;
	}
	Node *tmp = head;
	do {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}while(tmp != head);
	printf("\n");
}



int main(void){
	Node *head = NULL;
	insertAtBeginning(&head,13);
	insertAtEnd(&head,12);
	insertAtEnd(&head,11);
	insertAtEnd(&head,10);
	insertAtEnd(&head,9);
	insertAtBeginning(&head,14);
	printList(head);
	deleteFromBeginning(&head);
	printList(head);
	deleteFromBeginning(&head);
	printList(head);
	return 0;
}

