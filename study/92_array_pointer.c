#include<stdio.h>
int main(){
    int arr[8]={1,3,5,7,9,11,13,15};
    int (*ptr)[];
    int sum=0;
    (ptr)=&arr;
    for(int i=0;i<8;i++){
        sum+=(*ptr)[i];
    }
    printf("sum=%d",sum);
}
