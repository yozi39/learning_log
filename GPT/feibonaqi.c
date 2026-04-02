#include<stdio.h>
int main(){
    int n,q=2;
    scanf("%d",&n);
    int num[n];
    num[0]=1;
    num[1]=1;
    printf("%d\t%d\t",num[0],num[1]);
    for (int i=2;i<n;i++){
        num[i]=num[i-1]+num[i-2];
        printf("%d\t",num[i]);
        ++q;
        if(q==5){
            printf("\n");
            q=0;
        }
    }
    return 0;
}