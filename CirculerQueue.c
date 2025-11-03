#include <stdio.h>
#define SIZE 5

int queue_array[SIZE];
int front = -1, rear = -1;

int isFull() {
    if ((front==0 && rear == SIZE-1)||front==rear+1)
    {
        return 1;
    }
    
}

int isEmpty() {
    return (front == -1);
}

void enqueue() {
    int add_item;

    if (isFull()) {
        printf("\nQueue Overflow!\n");
        return;
    }

    printf("\nEnter the value to insert: ");
    scanf("%d", &add_item);

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }

    queue_array[rear] = add_item;
    printf("%d inserted successfully!\n", add_item);
}

void dequeue() {
    if (isEmpty()) {
        printf("\nQueue Underflow!\n");
        return;
    }

    int deleted_item = queue_array[front];

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }

    printf("\n%d deleted from the queue.\n", deleted_item);
}

void display() {
    if (isEmpty()) {
        printf("\nQueue is Empty!\n");
        return;
    }

    printf("\nElements in Circular Queue are:\n");

    int i = front;
    while (1) {
        printf("%d ", queue_array[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice Please try again.\n");
        }
    }
}
