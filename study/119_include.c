#include<stdio.h>
#include<ctype.h>

int main(){
    char ch;
    ch=getchar();
    if(isalpha(ch)){
        printf("true");
    }
    else printf("flase");
}