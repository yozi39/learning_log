//扫雷
#include<string.h>
#include<stdio.h>
int main(){
    int x,y,count=0;
    scanf("%d %d",&x,&y);
    char pan[x][y];
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            scanf(" %c",&pan[i][j]);
            if(pan[i][j] != '*') pan[i][j]='0';
        }
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(pan[i][j] != '*'){
                for(int dx=i-1;dx<=i+1;dx++){
                    for(int dy=j-1;dy<=j+1;dy++){
                        if(dx>=0 && dx<x && dy>=0 && dy<y){
                            if(pan[dx][dy]=='*'){
                                count++;
                            }
                        }
                    }
                }
                pan[i][j] += count;
                count=0;
            }
        }
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            printf("%c",pan[i][j]);
        }
        printf("\n");
    }
}

//debug 一个个格子走动然后使用八方查找，而不是通过*去标记八方位置

/*别的方式
    这里使用的是n的二重循环来遍历八方，可以改为使用八方向量可以修改

            for(int dx=i-1;dx<=i+1;dx++){
                for(int dy=j-1;dy<=j+1;dy++){
                    if(dx>=0 && dx<x && dy>=0 && dy<y){
                        if(pan[dx][dy]=='*'){
                            count++;
                        }
                    }
                }
            }

    变成

            // 定义八个方向：左上、上、右上、左、右、左下、下、右下
            int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
            int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

            // 在遍历每个格子时
            for(int dir = 0; dir < 8; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && pan[nx][ny] == '*') {
                    count++;
                }
    }
    
*/