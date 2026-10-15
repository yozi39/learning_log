#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 5e5 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n,m;
int dep[N],fa[N][25];
vector<int> edge[N];

void dfs(int x,int depth){
    dep[x] = depth;

    for(auto y:edge[x]){
        if(dep[y])continue;

        fa[y][0]=x;//忘了喵
        dfs(y,depth+1);
    }
}

int lca(int x,int y){
    if(dep[x] < dep[y])swap(x,y);

    for(int i=20;i>=0;i--){
        if(dep[fa[x][i]] < dep[y])continue;
        
        x = fa[x][i];
    }

    if(x == y)return x;

    for(int i = 20; i>=0;i--){
        if(fa[x][i] != fa[y][i]){
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    dfs(1,1);
    for(int i=1;i<=20;i++){
        for(int j=1;j<=n;j++){
            fa[j][i] = fa[fa[j][i-1]][i-1];
        }
    }

    while(m--){
        int a,b,c;cin>>a>>b>>c;

        int x=lca(a,b);
        int y=lca(a,c);
        int z=lca(b,c);

        int p;
        if(x==y)p=z;
        else if(y==z)p=x;
        else p=y;

        LL ret=dep[a]+dep[b]+dep[c]-dep[x]-dep[y]-dep[z];

        cout<<p<<' '<<ret<<qp;
    }
}