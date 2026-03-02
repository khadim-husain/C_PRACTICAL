#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_begin(){
    struct node *newnode;
    int value;

    newnode = (struct node *)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter value to insert:");
    scanf("%d",&value);

    newnode->data = value;
    newnode->next = head;
    head = newnode;

    printf("Node inserted at beginning\n");
}

void insert_end(){
    struct node *newnode, *temp;
    int value;

    newnode = (struct node *)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->next = NULL;

    if(head == NULL){
        head = newnode;
    } else {
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
    printf("Node inserted at end\n");
}

void delete_begin(){
    struct node *temp;

    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    temp = head;
    head = head->next;
    printf("Deleted element: %d\n",temp->data);
    free(temp);
}


void delete_end(){
    struct node *temp, *prev;

    if(head == NULL){
        printf("List is empty\n");
        return;
    }

    if(head->next == NULL){
        printf("Deleted Element: %d\n",head->data);
        free(head);
        head = NULL;
        return;
    }
    temp = head;
    while(temp->next != NULL){
        prev = temp;
        temp = temp -> next;
    }
    prev -> next = NULL;
    printf("deleted element: %d\n",temp->data);
    free(temp);
}


void display(){
    struct node *temp;

    if(head == NULL){
        printf("List is Empty\n");
        return;
    }
    temp = head;
    printf("Linked List:");
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    int choice;

    while(1){
        printf("\n---Linked List Menu---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete at beginning\n");
        printf("4. Delete at End\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

             switch (choice) {
            case 1: insert_begin(); break;
            case 2: insert_end(); break;
            case 3: delete_begin(); break;
            case 4: delete_end(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}