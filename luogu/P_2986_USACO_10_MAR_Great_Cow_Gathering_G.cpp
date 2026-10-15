#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 2e5 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n;
LL c[N],C;
vector<PLL> edge[N];
LL ret=1e18,r;
LL f[N],g[N];

void dfs1(int x,int fa){
    f[x] = c[x];
    LL m = 0;
    for(auto v:edge[x]){
        LL y = v.first,z=v.second;
        if(y == fa)continue;
        dfs1(y,x);

        m = max(m,f[y]);
        f[x] += f[y];
    }
    m = max(m,C-f[x]);

    if(m<ret){
        r = x;
        ret = m;
    }
}

void dfs2(int x,int fa){
    f[x] = c[x];
    for(auto v:edge[x]){
        int y = v.first,z=v.second;
        if(y==fa)continue;
        dfs2(y,x);

        f[x] += f[y];
        g[x] += g[y] + f[y]*z;
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        C += c[i];
    }
    for(int i=1;i<n;i++){
        int a,b,l;
        cin>>a>>b>>l;

        edge[a].push_back({b,l});
        edge[b].push_back({a,l});
    }
    
    dfs1(1,0);
    dfs2(r,0);
    cout<<g[r];
}