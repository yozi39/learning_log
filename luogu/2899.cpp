#include <bits/stdc++.h>
using namespace std;

const int N=1e4+5,INF=0x3f3f3f3f;

int n;
vector<int> edge[N];
int f[N],g[N],h[N];

void dfs(int x,int fa){
    f[x]=1;h[x]=0;
    int diff=INF;

    for(auto v:edge[x]){
        if(v==fa) continue;
        dfs(v,x);

        g[x] += min(f[v],g[v]);
        f[x] += min(g[v],min(f[v],h[v]));
        h[x] += min(f[v],g[v]);
        diff = min(diff , f[v]-g[v]);
    }
    if(diff >0) g[x] += diff;
}

int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    dfs(1,0);

    cout<<min(f[1],g[1]);
}