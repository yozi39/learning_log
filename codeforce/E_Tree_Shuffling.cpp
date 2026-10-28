#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 2e5+5;

int n;
int f[N],g[N];//f放位置不对并且希望1的数量，g为0
LL a[N],b[N],c[N];
vector<int> edge[N];
LL ret=0;

void dfs(int x,int fa,LL p){
    p = min(p,a[x]); // 进入节点：更新根到这里的最低价格

    (c[x]? f[x]:g[x]) = (b[x]==c[x]? 0:1);
    for(auto y:edge[x]){
        if(y == fa)continue;

        dfs(y,x,p);
        f[x] += f[y]; // 孩子处理后，剩余需要 0→1 的数量
        g[x] += g[y]; // 剩余需要 1→0 的数量
    }

    // 所有孩子的剩余点汇总完，再配对
    int num = min(f[x],g[x]);
    ret += 2LL*num*p;
    f[x] -= num;
    g[x] -= num;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    dfs(1,0,a[1]);
    if(f[1] || g[1])cout<<-1;
    else cout<<ret;
}