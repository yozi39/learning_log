#include<stdio.h>
int is(int su){
    if(su<=1)printf("请输入大于1的自然数");
    else {
        for(int i=2;i<su;++i){
            if(su%i==0) return 0;
        }
        return 1;
    }
}
int main(){
    int n;
    printf("input your number:");
    scanf("%d",&n);
    if(is(n) == 0)printf("yes yes yes yes yes");
    else printf("no!!!");
}