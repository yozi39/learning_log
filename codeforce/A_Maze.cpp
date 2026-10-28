#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;

#define qp '\n'
const int N = 505;

int n,m,k;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
char pan[N][N];
bool st[N][N];
vector<PII> ret;

void bfs(PII s){
    queue<PII> q;
    q.push(s);
    st[s.first][s.second] = true;

    while(q.size()){
        auto t = q.front();q.pop();
        int x = t.first,y = t.second;
        ret.push_back(t);

        for(int i=0;i<4;i++){
            int nx = x+dx[i],ny = y+dy[i];
            if(nx<1 || nx>n || ny<1 || ny>m)continue;
            if(pan[nx][ny]!='.' || st[nx][ny])continue;
            st[nx][ny] = true;
            q.push({nx,ny});
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m>>k;
    PII s;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>pan[i][j];
            if(pan[i][j]=='.')s = {i,j};
        }
    }

    bfs(s);
    while(k--){
        auto t = ret.back();ret.pop_back();
        pan[t.first][t.second] = 'X';
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)cout<<pan[i][j];
        cout<<qp;
    }
}