#include<stdio.h>
#include<limits.h>
int main(){
    int n,m;
    int now=0,min=INT_MAX;
    scanf("%d %d",&n,&m);
    int num[n];
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    for(int i=0;i<n-m+1;i++){
        now=0;
        for(int j=0;j<m;j++){
            now += num[i+j];
        }
        if(now<min){
            min=now;
        }
    }
    printf("%d",min);
}