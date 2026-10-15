#include<bits/stdc++.h>
using namespace std;

const int N=6e3+5;
    
int n;
int r[N];
vector<int> edge[N];
int f[N],g[N];
bool st[N];

void dfs(int x){
    f[x]=r[x];
    for(auto y:edge[x]){
        dfs(y);

        f[x] += g[y];
        g[x] += max(f[y],g[y]);
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>r[i];
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        st[a] = true;
        edge[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(!st[i]){
            dfs(i);
            cout<<max(f[i],g[i]);
        }
    }
}