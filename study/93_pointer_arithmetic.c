#include<stdio.h>
int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int *ptr_1;
    ptr_1=arr;
    for (int i = 0;i<10;i +=2){
        printf("%d ",*(ptr_1+i));
    }
}