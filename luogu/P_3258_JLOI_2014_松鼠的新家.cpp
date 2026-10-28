#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 3e5 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n;
int p[N],d[N];
vector<int> edge[N];

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

int ret[N];
void dfsr(int x,int fa){
    ret[x] = d[x];

    for(auto y:edge[x]){
        if(y == fa)continue;
        dfsr(y,x);
        ret[x] += ret[y];
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

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>p[i];
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;

        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    dfs(1,0);

    for(int i=1;i<n;i++){
        int t = lca(p[i],p[i+1]);

        d[p[i]]++;d[p[i+1]]++;
        d[t]--;d[f[t][0]]--;
    }

    dfsr(1,0);
    for(int i=2;i<=n;i++)ret[p[i]]--;

    for(int i=1;i<=n;i++){
        cout<<ret[i]<<qp;
    }
}