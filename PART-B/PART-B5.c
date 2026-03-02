#include<stdio.h>

int main()
{
    int a[100], n, i, j, item;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("\nEntered elements are:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    for(i = 1; i < n; i++)
    {
        item = a[i];
        j = i - 1;

        while(j >= 0 && item < a[j])
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = item;
    }

    printf("\n\nSorted array:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
