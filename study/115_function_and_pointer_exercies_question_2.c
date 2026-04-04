#include<stdio.h>

int max(int a,int b){
    return (a>b)?a:b;
}

int min(int a,int b){
    return (a>b)?b:a;
}

int operate(int a,int b,int (*fp)(int a,int b)){
    return fp(a,b);
}

int main(){
    int num_1,num_2;
    int choice,result; //1 max;2 min;
    scanf("%d %d %d",&num_1,&num_2,&choice);
    switch (choice)
    {
    case 1:
        result=operate(num_1,num_2,max);
        printf("max:%d",result);
        break;
    case 2:
        result=operate(num_1,num_2,min);
        printf("min:%d",result);
        break;
    default:
        printf("error");
        break;
    }
}