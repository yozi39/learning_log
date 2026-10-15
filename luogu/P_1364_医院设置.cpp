#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 105;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n;
LL p[N];
LL ret = LINF;
vector<int> edge[N];
LL f[N],g[N],r,W;

void dfs1(int x,int fa){
    f[x] = p[x];
    LL m = 0;

    for(auto v:edge[x]){
        if(v == fa)continue;
        dfs1(v,x);

        m = max(m,f[v]);
        f[x] += f[v];
    }   
    m = max(m,W-f[x]);
    if(m < ret){
        r = x;
        ret = m;
    }
}

void dfs2(int x,int fa){
    f[x] = p[x];

    for(auto v:edge[x]){
        if(v==fa)continue;
        dfs2(v,x);

        f[x] += f[v];
        g[x] += g[v]+f[v];
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int u,v;
        cin>>p[i]>>u>>v;
        W += p[i];

        if(u){
            edge[i].push_back(u);
            edge[u].push_back(i);
        }
        if(v){
            edge[i].push_back(v);
            edge[v].push_back(i);
        }
    }

    dfs1(1,0);
    dfs2(r,0);

    cout<<g[r];
}