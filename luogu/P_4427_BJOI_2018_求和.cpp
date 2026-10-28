#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 300000 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int n,m;
LL dep[N],a[N],pre[N][55];
vector<int> edge[N];
int f[N][25];

LL qpow(int a,int b){
    LL ret = 0;
    while(b){
        if(b&1)ret = ret*a%MOD;
        a = a*a%MOD;
        b >>= 1;
    }

    return ret;
}

void dfs(int x,int p){
    dep[x]=dep[p]+1;
    f[x][0]=p;

    LL t=1;
    for(int k=1;k<=50;k++){
        t=t*dep[x]%MOD;
        pre[x][k]=(pre[p][k]+t)%MOD;
    }

    for(int i=1;i<=20;i++)
        f[x][i]=f[f[x][i-1]][i-1];

    for(auto y:edge[x]){
        if(y==p)continue;
        dfs(y,x);
    }
}

int lca(int x,int y){
    if(dep[x] < dep[y])swap(x,y);

    for(int i=20;i>=0;i--){
        if(dep[f[x][i]] < dep[y])continue;

        x = f[x][i];
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
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    
    dep[0] = -1;//调了半天才发现,这个我传入的是fa不是depth,要用0去更新!!!
    dfs(1,0);

    cin>>m;
    while(m--){
        int a,b,c;cin>>a>>b>>c;

        int t = lca(a,b);
        LL ret=(pre[a][c]+pre[b][c]-pre[t][c]-pre[f[t][0]][c])%MOD;
        cout<<(ret+MOD)%MOD<<qp;
    }
}