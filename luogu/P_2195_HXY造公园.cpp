#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 3e5 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n,m,q;
LL ret;
LL fa[N],d[N],f[N];
vector<int> edge[N];

int find(int x){
    return fa[x] == x ? x:fa[x] = find(fa[x]);
}

void dfs(int x,int fa){
    for(auto v:edge[x]){
        if(v == fa)continue;
        dfs(v,x);

        ret = max(ret,f[x] + f[v] + 1);
        f[x] = max(f[x],f[v] + 1);
    }
}

int main(){
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)fa[i] = i;
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);

        int fx = find(u),fy=find(v);
        if(fx != fy)fa[fx] = fy;
    }

    for(int i=1;i<=n;i++){
        int fi = find(i);
        if(d[fi])continue;

        ret = 0;
        dfs(fi,0);
        d[fi] = ret;
    }

    for(int i=1;i<=q;i++){
        int op;cin>>op;
        int x,y;cin>>x;
        if(op==1){
            cout<<d[find(x)]<<qp;
        } else {
            cin>>y;
            int fx = find(x),fy = find(y);
            if(fx == fy)continue;

            LL t = max(max(d[fx],d[fy]),(d[fx]+1)/2+(d[fy]+1)/2+1);
            fa[fx] = fy;
            d[fy] = t;
        }
    }
}