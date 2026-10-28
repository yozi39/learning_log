#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 1005 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f,
dx[]={0,0,1,-1},
dy[]={1,-1,0,0};

int n,m;
int pan[N][N];
bool st[N][N];

LL bfs(int x,int y){
    queue<PII> q;
    q.push({x,y});
    st[x][y] = true;
    LL ret = pan[x][y];

    while(q.size()){
        auto t = q.front();q.pop();
        auto x = t.first,y = t.second;

        for(int k=0;k<4;k++){
            int nx = x + dx[k],ny = y + dy[k];

            if(nx<1 || nx>n || ny<1 || ny>m)continue;
            if(st[nx][ny] || !pan[nx][ny])continue;

            ret += pan[nx][ny];
            st[nx][ny] = true;
            q.push({nx,ny});        
        }
    }

    return ret;
}

void solve(){
    memset(st,0,sizeof st);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>pan[i][j];
        }
    }

    LL ret = -1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!st[i][j] && pan[i][j]){
                ret = max(ret,bfs(i,j));
            }
        }
    }
    cout<<max(0ll,ret)<<qp;
}

int main(){
    int t;cin>>t;
    while(t--)solve();
}