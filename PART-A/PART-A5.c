#include<stdio.h>

int bin_to_dec(int n){
    if(n == 0)
    return 0;
    return (n % 10) + 2 * bin_to_dec(n / 10);
}

int main(){

int bin;
printf("Enter the binary number: ");
scanf("%d", &bin);

    printf("Decimal value:%d", bin_to_dec(bin));
return 0;
}