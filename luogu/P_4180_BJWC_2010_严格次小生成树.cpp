#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;
typedef long long LL;

const int N = 1e5+5,M = 3e5+5,INF = 0x3f3f3f3f;

LL n,m,kcnt;
int fa[N];
bool st[M];
struct node{
    int x,y,z;    
}e[M];
vector<PII> edge[N];

int find(int x){
    return fa[x] == x? x:fa[x] = find(fa[x]);
}

void kruskal(){
    for(int i=1;i<=m;i++){
        int x = e[i].x,y=e[i].y,z=e[i].z;
        int fx = find(x),fy = find(y);

        if(fx == fy)continue;

        st[i] = 1;
        fa[fx] = fy;
        kcnt = kcnt + z;
        edge[x].push_back({y,z});
        edge[y].push_back({x,z});
    }
}

int dep[N];
int f[N][25],g[N][25],h[N][25];

void calc(int x,int& m1,int& m2){
    if(x > m1) m2 = m1,m1=x;
    else if(x < m1)m2 = max(m2,x);
}

void dfs(int x,int fa,int w){
    f[x][0] = fa;
    g[x][0] = w;
    h[x][0] = -INF;
    dep[x] = dep[fa] + 1;
    for(int i=1;i<=20;i++){
        f[x][i] = f[f[x][i-1]][i-1];
        int m1 = -INF,m2 = -INF;
        calc(g[x][i-1],m1,m2);calc(g[f[x][i-1]][i-1],m1,m2);
        calc(h[x][i-1],m1,m2);calc(h[f[x][i-1]][i-1],m1,m2);
        g[x][i] = m1;
        h[x][i] = m2;
    }

    for(auto t:edge[x]){
        int y = t.first,z = t.second;
        if(y == fa)continue;

        dfs(y,x,z);
    }
}

void lca(int x,int y,int& m1,int& m2){
    if(dep[x] < dep[y])swap(x,y);

    for(int i=20;i>=0;i--){
        if(dep[f[x][i]] < dep[y])continue;

        calc(g[x][i],m1,m2);calc(h[x][i],m1,m2);
        x = f[x][i];
    }

    if(x == y) return;

    for(int i=20;i>=0;i--){
        if(f[x][i] != f[y][i]){
            calc(g[x][i],m1,m2);calc(h[x][i],m1,m2);
            calc(g[y][i],m1,m2);calc(h[y][i],m1,m2);
            x = f[x][i];
            y = f[y][i];
        }
    }

    calc(g[x][0],m1,m2);calc(h[x][0],m1,m2);
    calc(g[y][0],m1,m2);calc(h[y][0],m1,m2);
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++)
        cin>>e[i].x>>e[i].y>>e[i].z;
    sort(e+1,e+1+m,[](node& a,node& b){
        return a.z<b.z;
    });

    kruskal();
    dfs(1,0,-INF);

    LL ret=1e18;
    for(int i=1;i<=m;i++){
        if(st[i])continue;
        int x = e[i].x,y = e[i].y,z = e[i].z;
        
        int m1 = -INF,m2 = -INF;
        lca(x,y,m1,m2);

        if(m1 != z) ret = min(ret,kcnt + z - m1);
        else ret = min(ret,kcnt+z-m2);
    }

    cout<<ret;
}