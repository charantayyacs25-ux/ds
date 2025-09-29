#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void push(int value);
void pop();
void peek();
void display();

int stack[SIZE];
int top = -1;

int main() {
    int value, choice;

    while (1) {
        printf("\n*** Menu ***\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if (top == SIZE - 1) {
                    printf("Stack overflow! Insertion not possible.\n");
                } else {
                    printf("Enter a value to be inserted: ");
                    scanf("%d", &value);
                    push(value);
                }
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Wrong selection, try again!\n");
        }
    }
    return 0;
}

void push(int value) {
    top++;
    stack[top] = value;
    printf("Insertion success!\n");
}

void pop() {
    if (top == -1) {
        printf("Deletion not possible because stack is empty!\n");
    } else {
        printf("Deleted element: %d\n", stack[top]);
        top--;
    }
}

void peek() {
    if (top == -1) {
        printf("Stack underflow!\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
