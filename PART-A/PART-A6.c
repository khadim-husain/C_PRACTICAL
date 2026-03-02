#include<stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int val){
    if(rear == MAX - 1){
        printf("Queue is Overflow.");
        return;
    }
    if(front == -1) front = 0;
    rear++;
    queue[rear] = val;
    printf("%d Inserted.\n",val);
}

void dequeue(){
    if(front == -1 || front>rear){
        printf("Queue is Underflow.\n");
        return;
    }
    printf("%d Deleted.\n",queue[front]);
    front++;
}

void display(){
    if(front == -1 || front>rear){
        printf("Queue is Empty.\n");
        return;
    }
    printf("Queue Element: \n");
    for(int i = front; i <= rear; i++)
        printf("%d ",queue[i]);
        printf("\n");   
}

int main(){
    
    int choice,val;

    do{
        printf("\n 1.Enqueue 2.Dequeue 3.Display 4.Exit \n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("Enter Value: ");
            scanf("%d",&val);
            enqueue(val);
            break;

            case 2:
            dequeue();
            break;

            case 3:
            display();
            break;

            case 4:
            printf("Exiting...\n");
            break;

            default :
            printf("Invalid choice.\n");
        }
    
    }while(choice != 4);
}
