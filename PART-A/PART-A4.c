#include <stdio.h>

void swap_valu(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap_ref(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int x = 5, y = 10;
    printf("Befor Swapping x = %d  y = %d \n", x, y);

    swap_valu(x, y);
    printf("After swap by value: x = %d y = %d \n ", x, y);

    swap_ref(&x, &y);
    printf("After swap by refrence x = %d y = %d \n:", x, y);
    return 0;
}
