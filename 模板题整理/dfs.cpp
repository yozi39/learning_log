/*
    树的遍历DFS
*/
#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int n;
vector<int> q[N];
bool st[N];//状态

void dfs(int u){
    cout<<u<<' ';
    st[u]=true;
    //访问所有孩子
    for(auto v:q[u]){
        if(!st[v]){
            dfs(v);
        }
    }
}

int main(){
    cin>>n;
    for(int i=1;i<n;i++){   //n个点只有n-1个边
        int a,b;cin>>a>>b;
        q[a].push_back(b);
        q[b].push_back(a);
    }
    //dfs
    dfs(1);
}