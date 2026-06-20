#include<bits/stdc++.h>
using namespace std;
//离散化加并查集
const int N=1e5+10,M=2e5+10;
int ik,jk,e,n,fa[M];
int in[N],jnn[N],pos=1;

int find(int x){
    return fa[x]==x? x:fa[x]=find(fa[x]);
}

void un(int x,int y){
    int xo=find(x);
    int yo=find(y);
    fa[xo]=yo;
}

bool issame(int x,int y){
    return find(x)==find(y);
}

unordered_map<int,int> id;
int cnt=0;
int getid(int x){
    if(id[x] == 0){
        id[x]=++cnt;
        fa[cnt]=cnt;
    }
    return id[x];
}

int main(){
    int T;cin>>T;
    while(T--){
        id.clear();
        cnt=0;
        pos=1;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>ik>>jk>>e;
            int x=getid(ik);
            int y=getid(jk);

            if(e){
                un(x,y);
            }
            else{
                in[pos]=x;
                jnn[pos++]=y;
            }
        }
        bool flag=true;
        for(int i=1;i<pos;i++){
            if(issame(in[i],jnn[i])){
                flag=false;
                break;
            }
        }
        if(flag)cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
}