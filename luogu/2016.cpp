#include <bits/stdc++.h>
using namespace std;

const int N=1510;

int n;
int f[N],g[N];
vector<int> edge[N];

void dfs(int x,int fa){
    f[x]=1;

    for(auto v:edge[x]){
        if(v==fa) continue;
        dfs(v,x);

        g[x] += f[v];
        f[x] += min(g[v],f[v]);
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,time;
        cin>>x>>time;
        
        for(int j=1;j<=time;j++){
            int y;cin>>y;
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
    }

    dfs(0,-1);

    cout<<min(f[0],g[0]);
}