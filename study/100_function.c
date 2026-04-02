#include<stdio.h>
void print_greetings(char name[100]){
    printf("%s,nice to meet you\n",name);
    printf("%s,nice weather\n",name);
    printf("%s,do you eat lunch?",name);
}
int main(){
    char name[100];
    scanf("%s",name);
    print_greetings(name);
    return 0;
}