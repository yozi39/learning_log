#include<bits/stdc++.h>
using namespace std;

const int N=3e5+5;

int n;
int f[N];
vector<int> edge[N];

void dfs(int x,int fa,int k){
    for(auto& v:edge[x]){
        if(v == fa)continue;
        dfs(v,x,k);

        f[x] += f[v]+1;
    }
    f[x] -= k;
    if(f[x]<0) f[x] = 0;
}

int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;

        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    int l=0,r=n-1;
    while(l<r){
        int mid = (l+r)>>1;
        memset(f,0,sizeof f);
        dfs(1,0,mid);

        if(f[1]>0){
            l = mid+1;
        } else {
            r = mid;
        }
    }
    
    cout<<r;
}