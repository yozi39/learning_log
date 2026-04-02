#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    int num[n];
    int status[10000] = {0};

    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }

    int ok=1;

    for(int i=1;i<n;i++){
        int temp;
        temp=abs(num[i]-num[i-1]);
        if(temp<1 || temp>=n || status[temp]==1){
            ok=0;
            break;
        }
        
        status[temp]=1;
    }

    if(ok)printf("Jolly");
    else printf("Not jolly");
    
    return 0;
}