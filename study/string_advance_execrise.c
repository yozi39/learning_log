#include<stdio.h>
#include<string.h>
int main(){
    char user_name[26],password_1[26],password_2[26];
    int len=0,result=0,success=0;
    printf("please input your user name:(len should be less than 16 and longer than 5):");
    scanf("%s",user_name);
    len=strlen(user_name);
    if(len<=5||len>=16){printf("please regeister again");return 0;}
    else{printf("valid user name!");}
    printf("please input your password:(len should be less than 20 and longer than 8):");
    scanf("%s",password_1);
    len=strlen(password_1);
    if(len<8||len>20){
        printf("invalid password!");
        return 0;
    }
    else{
        printf("please input your password agagin:");
        scanf("%s",password_2);
    }
    success=strcmp(password_1,password_2);
    if (success){printf("register fail:");}
    else{printf("register success:");}
    return 0;
}