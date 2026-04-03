#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* reverse_string(char* str){
    int len=strlen(str);
    char* reversed = (char*)malloc((len+1)*sizeof(char));
    if(reversed == NULL){
        printf("Error");
        return NULL;
    }
    for(int i=0;i<len;i++){
        reversed[i]=str[len-1-i];
    }
    reversed[len]='\0';
    return reversed;
}
//字符串逆序
int main(){
    char str[50];
    scanf("%s",str);
    char* reversed_str=reverse_string(str);//char* 用str来提供地址
    if(reversed_str != NULL){
        printf("%s",reversed_str);
        free(reversed_str);
    }
}