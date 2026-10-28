#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 1e4 + 5,M = 5e4+10;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n,m;
struct node{
    int x,y,z;
}e[M];
vector<PII> edge[N];
int f[N][25],g[N][25];
int fa[N],dep[N];

int find(int x){
    return fa[x] == x? x:fa[x] = find(fa[x]);
}

void dfs(int x,int fa,int w){
    f[x][0] = fa;
    g[x][0] = w;
    dep[x] = dep[fa] + 1;
    for(int i=1;i<=15;i++){
        f[x][i] = f[f[x][i-1]][i-1];
        g[x][i] = min(g[x][i-1],g[f[x][i-1]][i-1]);
    }

    for(auto t:edge[x]){
        int y = t.first,z = t.second;
        if(y == fa)continue;
        dfs(y,x,z);
    }
}

int lca(int x,int y){
    int ret = INF;
    if(dep[x]<dep[y])swap(x,y);

    for(int i=15;i>=0;i--){
        if(dep[f[x][i]] >= dep[y]){
            ret = min(ret,g[x][i]);
            x = f[x][i];
        }
    }

    if(x == y)return ret;

    for(int i=15;i>=0;i--){
        if(f[x][i] != f[y][i]){
            ret = min(ret,min(g[x][i],g[y][i]));
            x = f[x][i];
            y = f[y][i];
        }
    }
    return min(ret,min(g[x][0],g[y][0]));
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>e[i].x>>e[i].y>>e[i].z;
    }
    for(int i=1;i<=n;i++)fa[i] = i;
    sort(e+1,e+1+m,[](node& a,node& b){
        return a.z>b.z;
    });
    for(int i=1;i<=m;i++){
        int x = e[i].x,y = e[i].y,z=e[i].z;
        int fx = find(x),fy = find(y);
        if(fx == fy){
            continue;
        }

        fa[fx] = fy;
        edge[x].push_back({y,z});
        edge[y].push_back({x,z});
    }

    for(int i=1;i<=n;i++){
        if(dep[i])continue;
        dfs(i,0,INF);
    }

    int q;cin>>q;
    while(q--){
        int x,y;cin>>x>>y;
        if(find(x) != find(y))cout<<-1<<qp;
        else cout<<lca(x,y)<<qp;
    }
}