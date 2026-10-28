#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 50 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f,
dx[]={0,0,1,-1},
dy[]={1,-1,0,0};

int n,m,k;
char pan[N][N];
bool st[N][N];
vector<pair<LL,pair<int,int>>> ans;
vector<PII> pos;

LL bfs(int x,int y){
    queue<PII> q;
    q.push({x,y});
    st[x][y] = true;
    LL ret = 1;
    bool isLake = true;

    while(q.size()){
        auto t = q.front();q.pop();
        auto x = t.first,y=t.second;

        if(x == 1 || x == n || y == 1 || y == m) isLake = false;
        //return 0 只标了半块海，剩下的会被当成新湖
        
        for(int k=0;k<4;k++){
            int nx = x + dx[k],ny = y + dy[k];

            if(nx<1 || nx>n || ny<1 || ny>m)continue;
            if(st[nx][ny] || pan[nx][ny] == '*')continue;

            st[nx][ny] = true;
            ret++;
            q.push({nx,ny});
        }
    }
    return isLake ? ret : 0;
}

int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>pan[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(pan[i][j] == '.' && !st[i][j]){
                auto x = bfs(i,j);
                if(x)ans.push_back({x,{i,j}});
            }
        }
    }
    sort(ans.begin(), ans.end(), greater<pair<LL,pair<int,int>>>());
    LL ret = 0;
    while (ans.size()>k){
        ret+=ans.back().first;
        pos.push_back(ans.back().second);
        ans.pop_back();
    }
    cout<<ret<<qp;
    memset(st,0,sizeof st);
    for(auto v:pos){
        bfs(v.first,v.second);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<(st[i][j] == true? '*':pan[i][j]);
        }
        cout<<qp;
    }
}