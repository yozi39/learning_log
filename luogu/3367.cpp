#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int fa[N];

int find(int x){
    return fa[x]==x ? x:fa[x]=find(fa[x]);
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
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }

    for(int i=1;i<=m;i++){
        int op,x,y;cin>>op>>x>>y;
        switch(op){
            case 1:
                un(x,y);
                break;
            case 2:
                if(issame(x,y)){
                    cout<<'Y'<<'\n';
                }
                else{
                    cout<<'N'<<'\n';
                }
                break;
        }
    }
}