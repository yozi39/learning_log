#include<stdio.h>
int main(){
    char c[100];
    int count =0 ;
    printf("plesae input a string:");
    scanf("%99s",c);
    for(int i=0;i<99;i++){
        if((int)(c[i])>=48 && (int)(c[i])<=57){
            count += 1;
        }
    }
    printf("the count of character is:%d\n",count);
}