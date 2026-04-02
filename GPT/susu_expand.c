#include<stdio.h>
int su(int num,int time){
    for(int i=2;i<num;++i){
        if(i%2==0)time++;
    }
    return time;
}
int main(){
    int time=0,num;
    printf("input your destination number:");
    scanf("%d",&num);
    time=su(num,time);
    printf("form 2 to %d the number of susu is : %d",num,time);
}
