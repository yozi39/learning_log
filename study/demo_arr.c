#include<stdio.h>

int main(){
    int arr[5];
    for (int i = 0;i<5;i++){
        printf("请输入第%d个数:",i+1);
        scanf("%d",&arr[i]);
    }
    for (int i = 0;i<5;i++){
        printf("%d\t",arr[i]);
    }
}