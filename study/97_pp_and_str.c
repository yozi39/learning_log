#include<stdio.h>
int main(){
    char *name[6]={"Alice","Bob","Csl","Dldsfjl","Easdj","Fucku"};
    char **ptr=name;
    for(int i=0;i<6;i++){
        if(**ptr=='C'){
            printf("%s\n",*ptr);
        }
        ptr++;
    }
}