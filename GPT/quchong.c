#include<stdio.h>
#include<limits.h>
int main(){
    int n;
    int max=INT_MIN,min=INT_MAX;
    int sum=0,ave;
    scanf("%d",&n);
    int num[n];
    for (int i=0;i<n;i++){
        scanf("%d",&num[i]);
        if(max<num[i]){max=num[i];}
        if(min>num[i]){min=num[i];}
        sum +=num[i];
    }
    int a;
    a=max-min;
    ave = sum/n;
}