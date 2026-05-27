#include<bits/stdc++.h>
using namespace std;

const int N=2010;
int fa[N];
int n,m;

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
    cin>>n>>m;
    for(int i=1;i<=2*n;i++){
        fa[i]=i;
    }

    int ans=0;
    unordered_map<int,int> mp;
    mp.clear();
    while (m--)
    {
        char op;
        int p,q;cin>>op>>p>>q;
        if(op == 'E'){
            un(p,q+n);
            un(p+n,q);
        }
        else{
            un(p,q);
        }
    }

    for(int i=1;i<=n;i++){
        mp[find(i)]++;
    }

    cout<<mp.size();
}