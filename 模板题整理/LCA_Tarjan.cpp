//一个离线算法不能在线,但是效率会比倍增稍高
//3379
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 5e5 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n,m,s;
vector<int> edge[N];
vector<PII> query[N];
bool st[N];
int ret[N],fa[N];

int find(int x){
    return fa[x] == x ? x:fa[x] = find(fa[x]);
}
//利用dfs顺序去标记
void tarjan(int x){
    st[x] = 1;
    for(auto y:edge[x]){
        if(st[y])continue;

        tarjan(y);
        //结合它的父节点
        fa[y] = x;
    }

    for(auto v:query[x]){
        auto y=v.first,z=v.second;

        //记录答案
        if(st[y])ret[z] = find(y);
    }
}

int main(){
    cin>>n>>m>>s;
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        query[a].push_back({b,i});
        query[b].push_back({a,i});
    }
    for(int i=1;i<=n;i++){
        fa[i] = i;
    }

    tarjan(s);
    for(int i=1;i<=m;i++){
        cout<<ret[i]<<qp;
    }
}