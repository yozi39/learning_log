#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;

const int N=35;
int n;
int st[N][N],pan[N][N];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

void bfs(PII point){
    if(pan[point.first][point.second]==0 && !st[point.first][point.second]){
        queue<PII> q;
        q.push(point);
        while(q.size()){
            int xo=q.front().first,yo=q.front().second;q.pop();
            for(int i=0;i<4;i++){
                int x=xo+dx[i],y=yo+dy[i];
                if(x>=1 && x<=n && y>=1 && y<=n && !st[x][y] && pan[x][y]==0){
                    PII tmp;tmp.first=x;tmp.second=y;
                    q.push(tmp);
                    st[x][y]=1;
                }
            }
        }
    }
    return;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>pan[i][j];

    //
    for(int i=1;i<=n;i++){
        PII tmp;tmp.first=1;tmp.second=i;
        bfs(tmp);
        tmp.first=i;tmp.second=1;
        bfs(tmp);
        tmp.first=i;tmp.second=n;
        bfs(tmp);
        tmp.first=n;tmp.second=i;
        bfs(tmp);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(pan[i][j]==0 && st[i][j]!=1){
                pan[i][j]=2;
            }
            cout<<pan[i][j]<<' ';
        }
        cout<<'\n';
    }
}