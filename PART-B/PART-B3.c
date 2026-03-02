#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Insert operation
void insert() {
    int value;

    if ((rear + 1) % MAX == front) {
        printf("Queue is Full!\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);

    if (front == -1) {  // First element
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;
    printf("Inserted: %d\n", value);
}

// Delete operation
void delete() {
    if (front == -1) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Deleted: %d\n", queue[front]);

    if (front == rear) {  // Only one element
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Display operation
void display() {
    int i;

    if (front == -1) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Circular Queue elements: ");

    i = front;
    while (1) {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert();
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}