#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 100 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n;
int maxdep,cnt[N],pre[N],depth[N],maxcnt;
vector<int> edge[N];

void dfs(int x,int dep,int fa){
    maxdep=max(maxdep,dep);
    depth[x]=dep;
    cnt[dep]++;
    maxcnt = max(maxcnt,cnt[dep]);
    pre[x] = fa;

    for(auto v:edge[x]){
        if(v == fa)continue;
        dfs(v,dep+1,x);
    }
}

int lca(int x,int y){
    bool st[N]={};

    for(int i=x;i;i=pre[i])st[i]=1;

    while(y){
        if(st[y]){
            return y;
        } else {
            y = pre[y];
        }
    }
}

int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    dfs(1,1,0);

    int x,y;cin>>x>>y;
    int com = lca(x,y);

    cout<<maxdep<<qp;
    cout<<maxcnt<<qp;
    cout<<2*(depth[x]-depth[com])+(depth[y]-depth[com])<<qp;
}