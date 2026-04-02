#include<string.h>
#include<stdio.h>
int main(){
    char str_1[50]={};
    char str_2[50]={};
    int result=0,len=0;
    for (int i=0;i<30;i++){   
        str_2[i]='b';
    }
    strcpy(str_1,str_2);
    
}