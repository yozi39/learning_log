#include<stdio.h>
#include<string.h>

int main(){
    int n;
    char pass[51];
    int len;
    scanf("%d",&n);
    scanf("%s",pass);
    len=strlen(pass);
    n=n%26;
    for(int i=0;i<len;i++){
        pass[i] = (pass[i] - 'a' + n) % 26 + 'a';
    }
    printf("%s",pass);
}

//debug 1: n%26 保证在26个字母里面
//debug 2: char -128~127(没记错的话) 如果超出之后返回-，所以要保守复制pass[i]