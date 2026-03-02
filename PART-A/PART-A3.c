#include<stdio.h>

int str_len(char s[]){
    int i = 0;
    while(s[i] != '\0')
        i++;
    return i;    
}

void str_cat(char s1[], char s2[]){
    int i = 0, j = 0;
    while(s1[i] != '\0')
    i++;
    while(s2[j] != '\0'){
    s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = '\0';
}

int str_cmd(char s1[], char s2[]){
    int i = 0;
    while(s1[i] == s2[i]){
        i++;
    if(s1[i] != '\0')
    return 0;
    }
    return s1[i] - s2[i];
}

int main(){
    char s1[50], s2[50];
    
    printf("Enter first String : ");
    scanf("%s",&s1);
    
    printf("Enter first String : ");
    scanf("%s",&s2);

    printf("Length of first String: %d \n",str_len(s1));

    if(str_cmd(s1,s2) == 0)
        printf("String are equel. \n");
    else
        printf("String are not equel. \n");

    str_cat(s1,s2);
    printf("String are Connected: %s",s1);
}
