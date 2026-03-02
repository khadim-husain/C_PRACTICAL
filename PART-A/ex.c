#include<stdio.h>

void lsearch();
void bsearch();

int main(){
    int op;

    do{
        printf("1.Linear search\n");
        printf("2.Binary search\n");
        printf("3.Exit \n");
        printf("Enter Option: \n");
        scanf("%d",&op);


        switch(op){
            case 1:
            lsearch();
            break;

            case 2:
            bsearch();
            break;
        }
    }while(op != 3);
}



void lsearch(){
    int a[20],i,n,key,f=0;
    printf("Enter the size of an array: ");
    scanf("%d",&n);
    printf("Enter the array Elemenet: \n");
    for(i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the key to be searched:  \n");
    scanf("%d",&key);
    for(i = 0; i < n; i++){
        if(a[i] == key){
            f = 1;
            i++;
        }
    }
    if(f == 1){
        printf("key found.\n");
    }else{
        printf("key not found.\n");
    }
}


void bsearch(){
    int a[20],i,n,key,low,high,mid,f=0;
    printf("Enter the size of an array: \n");
    scanf("%d",&n);
    printf("Enter the emelemt achending ordr: \n");
    for(i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the key to be searched: \n");
    scanf("%d",&key);
    low = 0;
    high = n - 1;
    while(low <= high){
        mid = (low + high)/2;
        if(a[mid] == key){
            f = 1;
            break;
        }else if(low < a[mid]){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }    
    if(f == 1){
        printf("Key found.\n");
    }else{
        printf("Key not found.\n");
    }
}