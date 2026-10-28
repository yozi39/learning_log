#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
#define qp '\n'

const int N=55;
int n,m,cnt;
char g[N][N];
bool st[N][N];
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};

bool bfs(){
    memset(st,0,sizeof st);
    if(g[n][m]=='#')return cnt==0;
    queue<PII> q;
    q.push({n,m});
    st[n][m]=true;
    int ret=0;
    while(q.size()){
        auto t=q.front();q.pop();
        int x=t.first,y=t.second;
        if(g[x][y]=='G')ret++;
        if(g[x][y]=='B')return false;
        for(int i=0;i<4;i++){
            int a=x+dx[i],b=y+dy[i];
            if(a<1||a>n||b<1||b>m)continue;
            if(st[a][b]||g[a][b]=='#')continue;
            st[a][b]=true;
            q.push({a,b});
        }
    }
    return ret==cnt;
}

void solve(){
    cin>>n>>m;
    cnt=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
            if(g[i][j]=='G')cnt++;
        }
    bool ok=true;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(g[i][j]!='B')continue;
            for(int k=0;k<4;k++){
                int a=i+dx[k],b=j+dy[k];
                if(a<1||a>n||b<1||b>m)continue;
                if(g[a][b]=='G')ok=false;
                else if(g[a][b]=='.')g[a][b]='#';
            }
        }
    cout<<(ok&&bfs()?"Yes":"No")<<qp;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--)solve();
}