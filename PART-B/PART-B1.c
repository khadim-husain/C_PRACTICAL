#include <stdio.h>
#define MAX 5

int stack[MAX], top = -1;

void push(int item)
{
    if (top == MAX - 1)
    {
        printf("Stack is Overflow.\n");
    }
    else
    {
        stack[++top] = item;
        printf("%d Item Inserted.", item);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is Underflow.\n");
    }
    else
    {
        int item = stack[top--];
        printf("%d item Deleted.", item);
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is Empty.\n");
    }
    else
    {
        printf("Stack Element:\n ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{

    int choice, item;

    do
    {
        printf("\n1.Push 2.Pop 3.Display 4.Exit \n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value of push: \n");
            scanf("%d", &item);
            push(item);
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 4);
}