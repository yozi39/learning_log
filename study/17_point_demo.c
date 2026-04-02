#include<stdio.h>
int main(){
    char ch='A';
    char* c_ptr=&ch;
    printf("%c",*c_ptr);
    *c_ptr = 'a';
    printf("%c",*c_ptr);
    return 0;
}