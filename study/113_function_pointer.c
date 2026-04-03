#include<stdio.h>

int max(int a,int b){
    return (a>b)?a:b;
}

int min(int a,int b){
    return (a<b)?b:a;
}

int main(){
    int num_1,num_2;
    int result=0,choice;
    int (*fp)(int,int) =NULL;
    scanf("%d %d %d",&num_1,&num_2,&choice);
    if(choice==1){
        fp=max;
    }
    else if(choice == 2){
        fp=min;
    }
    else {
        printf("input 1 or 2"); 
        return 1;
    }
    result=fp(num_1,num_2);
    printf("%d",result);
}