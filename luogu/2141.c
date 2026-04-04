#include<stdio.h>
#include<string.h>
int main(){
    int n,count=0;
    scanf("%d",&n);
    int num[n];
    int status[n];
    memset(status,0,sizeof(status));
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    for(int i=0;i<n;i++){
        for(int k=i+1;k<n;k++){
            for(int z=0;z<n;z++){
                if(num[i]+num[k] == num[z]){
                    status[z]=1;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        if(status[i]==1){
            count++;
        }
    }
    printf("%d",count);
}