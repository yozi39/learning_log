#include<bits/stdc++.h>
using namespace std;

const int N=3*5e4+10;
int fa[N],n,k;

int find(int x){
    return fa[x]==x ? x:fa[x]=find(fa[x]);
}

void un(int x,int y){
    fa[find(x)]=find(y);
}

bool issame(int x,int y){
    return find(x)==find(y);
}

int main(){
    cin>>n>>k;
    int ans=0;
    while(k--){
        int op,x,y;cin>>op>>x>>y;
        if(x>n || y>n){
            ans++;
            continue;
        }
        
    }
}