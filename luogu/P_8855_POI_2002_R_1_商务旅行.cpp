#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 3e5 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n,m;
vector<int> edge[N];
vector<PII> query[N];
bool st[N];
int ret[N],fa[N],dep[N];

int find(int x){
    return fa[x] == x ? x:fa[x] = find(fa[x]);
}

void tarjan(int x,int depth){
    st[x] = 1;
    dep[x] = depth;

    for(auto y:edge[x]){
        if(st[y])continue;

        tarjan(y,depth+1);
        fa[y] = x;
    }
    for(auto v:query[x]){
        auto y = v.first,z=v.second;

        if(st[y])ret[z] = dep[x]+dep[y]-2*dep[find(y)];
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)fa[i] = i;
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);        
    }
    int pre;
    cin>>m>>pre;
    for(int i=1;i<m;i++){
        int x;cin>>x;
        query[x].push_back({pre,i});
        query[pre].push_back({x,i});
        pre = x;
    }

    tarjan(1,0);
    LL sum = 0;
    for(int i=1;i<m;i++){
        sum += ret[i];
    }

    cout<<sum<<qp;
}