#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 500000 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n;
vector<PLL> edge[N];
LL f[N],ret;

void dfs(int x,int fa){
    for(auto v:edge[x]){
        auto y = v.first,z=v.second;
        if(y==fa)continue;
        dfs(y,x);
        
        ret = max(ret,f[x]+f[y]+z);
        f[x] = max(f[x],f[y]+z);
    }
}

int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v,w;cin>>u>>v>>w;
        edge[u].push_back({v,w});
        edge[v].push_back({u,w});
    }

    dfs(1,0);

    cout<<ret;
}