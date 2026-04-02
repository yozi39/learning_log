#include<stdio.h>
int main(){
    char name[16];
    printf("please input the name who you want to greet:");
    scanf("%15s", name);
    printf("hello, %s\n", name);
}