//P1122
#include<bits/stdc++.h>
using namespace std;

const int N=16010;

int n;
vector<int> edge[N];
int f[N],a[N];

void dfs(int x,int fa){
    f[x]=a[x];
    for(auto y:edge[x]){
        if(y == fa)continue;

        dfs(y,x);
        if(f[y]>0) f[x]+=f[y];
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    dfs(1,0);
    
    int ret=-1e9;
    for(int i=1;i<=n;i++){
        ret = max(ret ,f[i]);
    }
    cout<<ret;
}