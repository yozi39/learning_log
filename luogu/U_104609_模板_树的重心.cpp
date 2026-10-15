#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 5e4+5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

LL n,r1,r2,ret=N;
LL f[N];
vector<int> edge[N];

void dfs(int x,int fa){
    f[x] = 1;
    LL m = 0;

    for(auto v:edge[x]){
        if(v==fa)continue;
        dfs(v,x);

        m = max(m,f[v]);
        f[x] += f[v];
    }
    m = max(m,n-f[x]);
    if(m < ret){                                                                                                                                                                                        
        r1 = x,r2 = 0;
        ret = m;
    }
    else if(m == ret){
        r2 = x;
    }
}

int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    dfs(1,0);

    if(r2 && r1>r2)swap(r1,r2);
    if(r1 && r2)cout<<r1<<' '<<r2<<qp;
    else cout<<r1<<qp;
}