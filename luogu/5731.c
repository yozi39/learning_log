#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int pan[n][n];
    int count=1;
    int up=0,down=n-1,left=0,right=n-1;
    while(count <= n*n){
        for(int i=left;i<=right;i++){
            pan[i][up]=count;
            count++;
        }
        for(int j=up+1;j<=down;j++){
            pan[right][j]=count;
            count++;
        }
        for(int i=right-1;i>=left;i--){
            pan[i][down]=count;
            count++;
        }
        for(int j=down-1;j>=up+1;j--){
            pan[left][j]=count;
            count++;
        }
        right--;
        left++;
        down--;
        up++;
    }
    count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            count++;
            if(pan[j][i]<10)printf("  %d",pan[j][i]);
            else{
                printf(" %d",pan[j][i]);
            }
            if(count%n==0)printf("\n");
        }
    }
}