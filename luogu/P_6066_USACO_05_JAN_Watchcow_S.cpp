#include<bits/stdc++.h>
using namespace std;
#define qp '\n'
const int N = 1e4+5;

int n,m;
vector<int> edge[N],ret;

void dfs(int x){
    while(edge[x].size()){
        int y = edge[x].back();
        edge[x].pop_back();
        dfs(y);
    }
    ret.push_back(x);
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    dfs(1);

    for(int i=2*m;i>=0;i--){
        cout<<ret[i]<<qp;
    }
}