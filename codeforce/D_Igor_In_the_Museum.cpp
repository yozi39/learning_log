#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
#define qp '\n'

const int N = 1005;
const int dx[]={1,-1,0,0},dy[]={0,0,1,-1};

int n,m,k,tot;
char pan[N][N];
int id[N][N],cnt[N*N];

void bfs(int sx,int sy){
    queue<PII> q;
    id[sx][sy] = ++tot;
    q.push({sx,sy});

    while(q.size()){
        auto t = q.front();q.pop();
        int x = t.first,y = t.second;

        for(int i=0;i<4;i++){
            int nx = x+dx[i],ny = y+dy[i];
            if(nx<1 || nx>n || ny<1 || ny>m)continue;

            if(pan[nx][ny]=='*'){
                cnt[tot]++;
            } else if(!id[nx][ny]){
                id[nx][ny] = tot;
                q.push({nx,ny});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)cin>>(pan[i]+1);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(pan[i][j]=='.' && !id[i][j])bfs(i,j);
        }
    }

    while(k--){
        int x,y;cin>>x>>y;
        cout<<cnt[id[x][y]]<<qp;
    }
}