#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=1e5+5,MOD=1e9+7;

int n,k;
vector<int> edge[N];
LL f[N][5];//x为子树有多少个填色方法;
int color[N];
LL ret=0;
bool st[N];

void dfs(int x,int fa){
    if(!st[x]){
        f[x][1] = f[x][2] = f[x][3] = 1 ;
    }

    for(auto v:edge[x]){
        if(v==fa) continue;

        dfs(v,x);

        f[x][1] = (f[x][1] * ((f[v][2] + f[v][3])%MOD)) % MOD;
        f[x][2] = (f[x][2] * ((f[v][1] + f[v][3])%MOD)) % MOD;
        f[x][3] = (f[x][3] * ((f[v][2] + f[v][1])%MOD)) % MOD;
    }
}

int main(){
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    for(int i=1;i<=k;i++){
        int a,b;
        cin>>a>>b;
        
        st[a] = true;
        f[a][b] = 1;
    }

    dfs(1,0);

    LL ret = 0;
    cout<<((f[1][1]+f[1][2])%MOD+f[1][3])%MOD;
}