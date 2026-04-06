#include<stdio.h>

#define MAXN 40000

int main(){
    int N;
    scanf("%d",&N);
    int num[MAXN]={0};
    int count=0;
    int sum=0;
    while (sum < N * N) {
        scanf("%d", &num[count]);
        sum += num[count];
        count++;
    }
    int z=0;
    for(int i=0;i<count;i++){
        if(i%2==0){
            for(int j=0;j<num[i];j++){
                printf("0");
                z++;
                if(z%N==0)printf("\n");
            }
        }
        if(i%2==1){
            for(int j=0;j<num[i];j++){
                printf("1");
                z++;
                if(z%N==0)printf("\n");
            }
        }
    }
}