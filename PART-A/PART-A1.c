#include<stdio.h>

int n;

void insert(int a[], int pos, int ele){
    for(int i  = n; i >= pos; i--)
    a[i] = a[i -1];
    a[pos - 1] = ele;
    n++;
}

void delete(int a[], int pos){
    for(int i = pos - 1; i < n - 1; i++)
    a[i] = a[i + 1];
    n--;
}

int main(){

    int a[10],i,pos,ele,ch;

    printf("Enter Size: ");
    scanf("%d",&n);

    printf("Enter Element: \n");
    for(i = 0; i < n; i++){
    scanf("%d",&a[i]);
    }

    printf("\n 1.Insert 2.Delete\n");
    scanf("%d",&ch);

    if(ch == 1){
        printf("Position of Element: \n");
        scanf("%d%d",&pos,&ele);
        insert(a,pos,ele);
    }else if(ch == 2){
        printf("Position: \n");
        scanf("%d",&pos);
        delete(a,pos);
    }

    printf("Array List: \n");
    for(i = 0; i < n; i++)
    printf("%d ",a[i]);
    return 0;
}