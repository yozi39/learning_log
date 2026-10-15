#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;

const int N=5e5+5;

int n;
int s;
vector<PII> edge[N];
LL f[N];
LL g[N];

void dfs(int x,int fa){
    LL maxn=0;

    for(auto& v:edge[x]){
        int b=v.first,c=v.second;

        if(b==fa) continue;

        dfs(b,x);

        maxn=max(maxn,g[b]+c);
    }

    g[x]=maxn;

    for(auto& v:edge[x]){
        int b=v.first,c=v.second;

        if(b==fa) continue;

        f[x] += f[b] + maxn-(g[b]+c);
    }
}

int main(){
    cin>>n;cin>>s;
    for(int i=1;i<n;i++){
        int a,b,c;cin>>a>>b>>c;

        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }

    dfs(s,0);

    cout<<f[s];
}