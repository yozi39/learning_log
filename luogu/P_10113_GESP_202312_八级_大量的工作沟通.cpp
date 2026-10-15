#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n,m,ret;
int fa[N][25],pre[N],dep[N],mx[N];
vector<int> edge[N];

void dfs(int x,int depth){
    dep[x] = depth;
    mx[x] = max(mx[pre[x]],x);

    for(auto y:edge[x]){
        if(y == pre[x])continue;
        dfs(y,depth+1);
    }
}

int lca(int x,int y){
    if(dep[x]<dep[y])swap(x,y);

    for(int i=20;i>=0;i--){
        if(dep[fa[x][i]] < dep[y])continue;
        x = fa[x][i];
    }

    if(x == y)return x;

    for(int i=20;i>=0;i--){
        if(fa[x][i] != fa[y][i]){
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}

int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int x;cin>>x;
        pre[i] = x;
        fa[i][0] = x;

        edge[x].push_back(i);
        edge[i].push_back(x);
    }
    dfs(0,0);
    for(int i=1;i<=20;i++){
        for(int j=1;j<n;j++){
            fa[j][i] = fa[fa[j][i-1]][i-1];
        }
    }

    int q;
    cin>>q;

    for(int i=1;i<=q;i++){
        cin>>m;
        queue<int> q;

        for(int i=1;i<=m;i++){
            int x;cin>>x;
            q.push(x);
        }
        while(q.size()>1){
            auto f = q.front();q.pop();
            auto s = q.front();q.pop();

            ret = lca(s,f);
            q.push(ret);
        }
        cout<<mx[q.front()]<<'\n';
    }
}