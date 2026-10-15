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
LL f[N][25],dep[N];
vector<int> edge[N];

void dfs(int x,int depth,int fa){
    dep[x] = depth;
    f[x][0] = fa;

    for(auto y:edge[x]){
        if(y == fa)continue;
        dfs(y,depth+1,x);
    }
}

void init(int x){
    dfs(x,1,0);

    for(int i=1;i<=20;i++){
        for(int j = 1;j<=n;j++){
            f[j][i] = f[f[j][i-1]][i-1];
        }
    }
}

int lca(int x,int y){
    if(dep[x]<dep[y])swap(x,y);

    for(int i=20;i>=0;i--){
        if(dep[f[x][i]]>=dep[y]){
            x=f[x][i];
        }
    }

    if(x == y)return x;

    for(int i=20;i>=0;i--){
        if(f[x][i] != f[y][i]){
            x = f[x][i];
            y = f[y][i];
        }
    }

    return f[x][0];
}

int main(){
    cin>>n>>m>>s;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    init(s);

    while(m--){
        int a,b;
        cin>>a>>b;

        cout<<lca(a,b)<<qp;
    }
}