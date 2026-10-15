#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 2e5 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n,m;
vector<PLL> edge[N];
vector<PII> query[N];
bool st[N];
int ret[N],fa[N],dep[N];

int find(int x){
    return fa[x] == x? x:fa[x] = find(fa[x]);
}

void tarjan(int x,int depth){
    st[x] = 1;
    dep[x] = depth;

    for(auto v:edge[x]){
        auto y = v.first,z = v.second;
        if(st[y])continue;

        tarjan(y,depth+z);
        fa[y] = x;
    }

    for(auto v:query[x]){
        auto y = v.first,z=v.second;

        if(st[y])ret[z] = dep[x]+dep[y]-2*dep[find(y)];
    }
}

void init(){
    for(int i=1;i<n;i++){
        int a,b,c;cin>>a>>b>>c;
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        query[a].push_back({b,i});
        query[b].push_back({a,i});
    }
    for(int i=1;i<=n;i++){
        fa[i] = i;
    }
}

int main(){
    cin>>n>>m;

    init();
    tarjan(1,0);

    for(int i=1;i<=m;i++){
        cout<<ret[i]<<qp;
    }
}