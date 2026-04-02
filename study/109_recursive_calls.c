#include<stdio.h>

int fibo(unsigned int n){
    int count=0;
    if(n==0) return 0;
    else if(n==1) return 1;
    else {
        return fibo(n-1)+fibo(n-2);
    }
}

int main(){
    unsigned int n=10;
    int result=fibo(n);
    printf("%d",result);
}