#include<bits/stdc++.h>
using namespace std;
//B3642
const int N=1e6+10;
int n,l[N],r[N];

void dfs(int root){
    cout<<root<<' ';
    if(l[root]!=0)dfs(l[root]);
    if(r[root]!=0)dfs(r[root]);
}

void dfsmid(int root){
    if(l[root]!=0)dfsmid(l[root]);
    cout<<root<<' ';
    if(r[root]!=0)dfsmid(r[root]);
}

void dfsback(int root){
    if(l[root]!=0)dfsback(l[root]);
    if(r[root]!=0)dfsback(r[root]);
    cout<<root<<' ';
}

void bfs(int root){
    queue<int> q;q.push(root);
    while(q.size()){
        int x=q.front();q.pop();
        cout<<x;
        if(l[x])q.push(l[x]);
        if(r[x])q.push(r[x]);
    }
}

int main(){
    cin>>n;int root;
    for(int i=1;i<=n;i++)cin>>l[i]>>r[i];

    dfs(1);
    cout<<'\n';
    dfsmid(1);
    cout<<'\n';
    dfsback(1);
    cout<<'\n';
    //bfs(1);
    return 0;
}