#include<bits/stdc++.h>
using namespace std;

const int N=5e4+10,MOD=3;
int dist[N],k,fa[N],n;

int find(int x){
    if(fa[x]==x)return x;
    
    int t=find(fa[x]);
    dist[x]+=dist[fa[x]];
    return fa[x]=t;
}

void un(int x,int y,int w){
    int fx=find(x),fy=find(y);

    if(fx != fy){
        fa[fx]=fy;
        dist[fx]=w+dist[y]-dist[x];
    }
}

int main(){
    int ans=0;
    cin>>n>>k;

    for(int i=1;i<=n;i++)fa[i]=i;
    
    while(k--){
        int op,x,y;cin>>op>>x>>y;
        if(x>n || y>n){
            ans++;
            continue;
        }
        int fx=find(x);int fy=find(y);

        if(op == 1){
            if(fx==fy && ((dist[x]-dist[y])%MOD+MOD)%MOD != 0){
                ans++;
            }
            else{
                un(x,y,0);
            }
        }
        else{//x->y
            if(fx==fy && ((dist[x]-dist[y])%MOD+MOD)%MOD != 1){
                ans++;
            }
            else{
                un(x,y,1);
            }
        }
    }
    cout<<ans;
}