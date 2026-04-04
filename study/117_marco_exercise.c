#include<stdio.h>

#define SQUARE(a) (a*a)

int main(){
    int num;
    scanf("%d",&num);
    int result=SQUARE(num);
    printf("%d",result);
}