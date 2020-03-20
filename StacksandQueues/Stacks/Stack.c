#include<stdio.h>
#include<stdbool.h>
#define capacity 10

int top = -1;

void push(int s[], int num) {
    if(top == capacity-1) {
        printf("Stack overflow! Cannot push element.\n");
        return;
    }
    top++;
    s[top] = num;
    printf("Push successful!\n");
}

void pop(int s[]) {
    if(top == -1) {
        printf("Stack underflow! Cannot pop.\n");
        return;
    }
    top--;
    printf("Pop successful!\n");
}

void peek(int s[]) {
    if(top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("%d is at top of stack.\n", s[top]);
}

int main(void) {
    int stack[capacity];
    int choice, num;
    bool flag = true;

    do {
        printf("Enter operation to perform\n");
        printf("1.Push\n2.Pop\n3.Peek\n4.Exit\n");
        scanf("%d", &choice);
        switch(choice) {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &num);
            push(stack, num);
            break;
        case 2:
            pop(stack);
            break;
        case 3:
            peek(stack);
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
