#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;

const int N=405;
int n,m,x,y;
int dist[N][N];
int dx[8]={1,2,2,1,-1,-2,-2,-1};
int dy[8]={2,1,-1,-2,-2,-1,1,2};
queue<PII> q;

void bfs(){
    memset(dist,-1,sizeof(dist));
    q.push({x,y});
    dist[x][y]=0;

    while(q.size()){
        auto t=q.front();q.pop();
        int i=t.first,j=t.second;
        for(int z=0;z<8;z++){
            int x=i+dx[z],y=j+dy[z];
            if(x>=1 && x<=n && y>=1 && y<=m && dist[x][y]==-1){
                dist[x][y]=dist[i][j]+1;
                q.push({x,y});
            }
        }
    }
}

int main(){
    cin>>n>>m>>x>>y;

    bfs();

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<dist[i][j]<<' ';
        }
        cout<<'\n';
    }
}