#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;

int fa[N];
int n,m,p;

int find(int x){
    return fa[x]==x? x:fa[x]=find(fa[x]);
}

bool issame(int x,int y){
    return find(x)==find(y);
}

void un(int x,int y){
    int xo=find(x);
    int yo=find(y);
    fa[xo]=yo;
}

int main(){
    cin>>n>>m>>p;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        if(!issame(x,y))un(x,y);
    }

    while(p--){
        int x,y;cin>>x>>y;
        if(issame(x,y))cout<<"Yes"<<'\n';
        else{
            cout<<"No"<<'\n';
        }
    }
}