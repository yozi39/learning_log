#include<bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;

int n,k;
vector<int> edge[N];
int dep[N],f[N][25],d[N];
int ret[N];

void dfs(int x,int fa){
    f[x][0] = fa;
    dep[x] = dep[fa] + 1;
    for(int i=1;i<=20;i++){
        f[x][i] = f[f[x][i-1]][i-1];
    }

    for(auto y:edge[x]){
        if(y == fa)continue;

        dfs(y,x);
    }
}

void dfsr(int x,int fa){
    ret[x] = d[x];

    for(auto y:edge[x]){
        if(y == fa)continue;

        dfsr(y,x);

        ret[x] += ret[y];
    }
}

int lca(int x,int y){
    if(dep[x] < dep[y])swap(x,y);

    for(int i=20;i>=0;i--){
        if(dep[f[x][i]] < dep[y])continue;

        x = f[x][i];
    }

    if(x == y) return x;

    for(int i=20;i>=0;i--){
        if(f[x][i] != f[y][i]){
            x = f[x][i];
            y = f[y][i];
        }
    }

    return f[x][0];
}

int main(){
    cin>>n>>k;

    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;

        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    dfs(1,0);

    while(k--){
        int s,t;cin>>s>>t;
        d[s]++;d[t]++;
        int c = lca(s,t);
        d[c]--;d[f[c][0]]--;
    }

    dfsr(1,0);

    int ans = -1;
    for(int i=1;i<=n;i++){
        ans = max(ans,ret[i]);
    }

    cout<<ans;
}