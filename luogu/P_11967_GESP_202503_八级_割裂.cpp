#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 1e6 + 5,A=1e5+5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n,a;
vector<int> edge[N];
PII g[A],b;
int dep[N],f[N][25];
void dfs(int x,int fa){
    dep[x] = dep[fa] + 1;
    f[x][0] = fa;

    for(int i=1;i<=20;i++){
        f[x][i] = f[f[x][i-1]][i-1];
    }

    for(auto y:edge[x]){
        if(y == fa)continue;
        dfs(y,x);
    }
}

int lca(int x,int y){
    if(dep[x] < dep[y])swap(x,y);

    for(int i=20;i>=0;i--){
        if(dep[f[x][i]] < dep[y])continue;

        x = f[x][i];
    }

    if(x == y)return x;

    for(int i=20;i>=0;i--){
        if(f[x][i] != f[y][i]){
            x = f[x][i];
            y = f[y][i];
        }
    }

    return f[x][0];
}

int ret[N],d[N];
void dfsr(int x,int fa){
    ret[x] = d[x];

    for(auto y:edge[x]){
        if(y == fa)continue;
        dfsr(y,x);

        ret[x] += ret[y];
    }
}

int main(){
    cin>>n>>a;

    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    dfs(1,0);
    
    for(int i=1;i<=a;i++){
        int x,y;cin>>x>>y;
        d[x]++;d[y]++;
        int t = lca(x,y);
        d[t]--;d[f[t][0]]--;
    }
    
    int tx,ty;cin>>tx>>ty;
    int tt = lca(tx,ty);
    d[tx]--;d[ty]--;
    d[tt]++;d[f[tt][0]]++;
    
    dfsr(1,0);

    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(ret[i]<0)cnt++;
    }
    cout<<cnt;
}