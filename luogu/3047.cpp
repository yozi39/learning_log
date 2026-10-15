#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int n,k;
int h[N];
int f[N][25],g[N][25];
vector<int> edge[N];

void dfs1(int x,int fa){
    for(int i=0;i<=k;i++) f[x][i] = h[x];
    for(auto& v:edge[x]){
        if(fa == v)continue;
        dfs1(v,x);

        for(int i = 1;i <= k;i++) f[x][i] += f[v][i-1];
    }
}

void dfs2(int x,int fa){
    for(auto& y:edge[x]){
        if(y == fa)continue;

        g[y][0] = f[y][0];
        g[y][1] = f[y][1] + g[x][0];

        for(int i=2;i<=k;i++) g[y][i] = f[y][i] + g[x][i-1]
                                        -f[y][i-2];

        dfs2(y,x);
    }
}

int main(){
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }

    dfs1(1,0);

    for(int i=0;i<=k;i++)g[1][i] = f[1][i];
    dfs2(1,0);

    for(int x = 1 ; x<=n;x++){
        cout<<g[x][k]<<'\n';
    }
}