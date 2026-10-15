#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+5;

int n,q;
vector<int> edge[N];
int dep[N],fa[N][25],sz[N];

void init(){
    vector<int> ord;
    ord.push_back(1);
    dep[1]=1;

    for(int i=0;i<(int)ord.size();i++){
        int x=ord[i];
        for(auto y:edge[x]){
            if(y==fa[x][0])continue;
            fa[y][0]=x;
            dep[y]=dep[x]+1;
            ord.push_back(y);
        }
    }

    for(int i=n-1;i>=0;i--){
        int x=ord[i];
        sz[x]++;
        if(fa[x][0])sz[fa[x][0]]+=sz[x];
    }

    for(int i=1;i<=20;i++){
        for(int j=1;j<=n;j++){
            fa[j][i]=fa[fa[j][i-1]][i-1];
        }
    }
}

int lca(int x,int y){
    if(dep[x]<dep[y])swap(x,y);

    for(int i=20;i>=0;i--){
        if(dep[fa[x][i]]>=dep[y])
            x=fa[x][i];
    }

    if(x==y)return x;

    for(int i=20;i>=0;i--){
        if(fa[x][i]!=fa[y][i]){
            x=fa[x][i];
            y=fa[y][i];
        }
    }
    return fa[x][0];
}

int son(int c,int x){
    if(c==x)return 0;

    for(int i=20;i>=0;i--){
        if(dep[fa[x][i]]>dep[c])
            x=fa[x][i];
    }
    return x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>q;
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    init();

    while(q--){
        int a,b,c;cin>>a>>b>>c;
        int p=lca(a,b);

        if(c==p){
            int x=son(c,a),y=son(c,b);
            cout<<n-sz[x]-sz[y]<<'\n';
        }
        else if(lca(a,c)==c && lca(b,c)==p){
            int x=son(c,a);
            cout<<sz[c]-sz[x]<<'\n';
        }
        else if(lca(b,c)==c && lca(a,c)==p){
            int y=son(c,b);
            cout<<sz[c]-sz[y]<<'\n';
        }
        else{
            cout<<0<<'\n';
        }
    }
}