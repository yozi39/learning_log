#include<stdio.h>
#include<limits.h>
int main(){
    int max=INT_MIN,min=INT_MAX;
    int q=0,p=0,n,num;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        if(max<num){
            max=num;
            q=1;
        }
        else if(num == max){q++;}
        if(min>num){
            min=num;
            p=1;
        }
        else if(num==min){p++;}
    }
    printf("%d %d %d %d",max,min,q,p);
}