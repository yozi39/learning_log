#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 1e5 + 5,M=2e5 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n,m;
vector<int> edge[N];
int d[N],dep[N],f[N][25];

void dfs(int x,int fa){
    f[x][0] = fa;
    dep[x] = dep[fa] + 1;

    for(int i=1;i<=20;i++)f[x][i] = f[f[x][i-1]][i-1];

    for(auto y:edge[x]){
        if(y==fa)continue;
        dfs(y,x);
    }
}

int a[N];
void dfsr(int x,int fa){
    a[x] = d[x];

    for(auto y:edge[x]){
        if(y == fa)continue;

        dfsr(y,x);
        a[x] += a[y];
    }
}

int lca(int x,int y){
    if(dep[x]<dep[y])swap(x,y);

    for(int i=20;i>=0;i--){
        if(dep[f[x][i]] < dep[y])continue;

        x=f[x][i];
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

int main(){
    cin>>n>>m;
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    dfs(1,0);

    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        d[u]++;d[v]++;d[lca(u,v)]-=2;
    }

    dfsr(1,0);

    LL ret=0;
    for(int i=2;i<=n;i++){
        int x = a[i];
        if(x == 0)ret += m;
        else if(x == 1)ret++;
    }

    cout<<ret;
}