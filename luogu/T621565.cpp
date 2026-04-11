#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,T;
    cin>>n>>m;
    int pan[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>pan[i][j];
    cin>>T;
    int x,y,a,b;
    for(int i=0;i<T;i++){
        cin>>x>>y>>a>>b;
        x--; y--; a--; b--;
        swap(pan[x][y],pan[a][b]);
    }
    int dx[4]={1,0,-1,0};
    int dy[4]={0,-1,0,1};
    int status[n][m];
    int cnt=0;
    memset(status,0,sizeof(status));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            bool ok=true;
            for(int z=0;z<4;z++){
                int temp_x= i+dx[z];
                int temp_y= j+dy[z];
                if(temp_x>=0 && temp_x<n &&temp_y>=0 &&temp_y<m){
                    if(pan[i][j]<=pan[temp_x][temp_y]){
                        ok=false;
                        break;
                    }
                }
            }
            if(ok){
                status[i][j]=1;
                cnt++;
            }
        }
    }
    cout<<cnt<<'\n';
    for(int j=0;j<n;j++){
        for(int k=0;k<m;k++){
            if(status[j][k] == 1){
                cout<<j+1<<' '<<k+1<<'\n';
            }
        }
    }

        //debug 用status[][]++ == 4在边缘的地方可能最多都不到四个
        //看输入这个是1,1原点的所以要--来确保和我的0,0的合得来
        //learn 用bool来做状态值判断比status更有用;
    
}