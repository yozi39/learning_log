#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 2e5 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

LL d[N];
int n,l,r;
vector<int> edge[N];

void dfs1(int x,int fa){
    for(auto v:edge[x]){
        if(v==fa)continue;
        d[v] = d[x]+1;
        if(d[v]>d[l]) l=v;
        dfs1(v,x);
    }
}

void dfs2(int x,int fa){
    for(auto v:edge[x]){
        if(v == fa)continue;

        d[v] = d[x] + 1;
        if(d[v]>d[r]) r=v;
        dfs2(v,x);
    }
}

int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    dfs1(1,0);
    d[l] = 0;
    dfs2(l,0);
    cout<<d[r];
}