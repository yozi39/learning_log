#include<stdio.h>
#include<string.h>
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int pan[n+1][n+1];
    memset(pan,0,sizeof(pan));
    for(int i=0;i<m;i++){
        int temp_x,temp_y;
        scanf("%d %d",&temp_x,&temp_y);
        pan[temp_x][temp_y]=1;
        int dx[13]={-1,-1,-1,0,0,0,1,1,1,0,2,0,-2};
        int dy[13]={1,0,-1,1,0,-1,1,0,-1,2,0,-2,0};
        for(int j=0;j<13;j++){
            int x=temp_x+dx[j];
            int y=temp_y+dy[j];
            if(x<=n && y<=n && x>=1 && y>=1){
                pan[x][y]=1;
            }
        }
    }
    for(int i=0;i<k;i++){
        int temp_x,temp_y;
        scanf("%d %d",&temp_x,&temp_y);
        pan[temp_x][temp_y]=1;
        for(int j=-2;j<3;j++){
            for(int z=-2;z<3;z++){
                int x=temp_x+j;
                int y=temp_y+z;
                if(x<=n && y<=n && x>=1 && y>=1){
                    pan[x][y]=1;
                }
            }
        }
    }
    int count=0;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(pan[i][j] == 0){
                count++;
            }
        }
    }
    printf("%d",count);
}