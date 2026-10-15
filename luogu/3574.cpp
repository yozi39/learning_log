#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;

int n;
int t[N];
int f[N],g[N];
int s[N];
vector<int> edge[N];

bool cmp(int a,int b){
    return g[a]-f[a]<g[b]-f[b];
}

void dfs(int x,int fa){
    f[x] = t[x];
    for(auto v:edge[x]){
        if(v == fa)continue;
        dfs(v,x);
    }

    int cnt = 0;
    for(auto v:edge[x]){
        if(v == fa)continue;
        s[++cnt]=v;
    }

    sort(s+1,s+1+cnt,cmp);

    int T = 0;
    for(int i=1;i<=cnt;i++){
        int v = s[i];

        f[x] = max(f[x],f[v] + T + 1);
        T += 2+g[v];
    }
    g[x] = T;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t[i];
    }
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);        
    }

    dfs(1,0);

    cout<<max(f[1],g[1]+t[1]);
}