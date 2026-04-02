#include<stdio.h>
int ab(int num){
    if(num%2==1)return 1;
    return 0;
}
int main(){
    int num,h;
    scanf("%d",&num);
    if(ab(num)==1) {
        printf("ji");
        return 1;
    }
    printf("ou");
    return 0;
}