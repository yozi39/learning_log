//P2024
#include<bits/stdc++.h>
using namespace std;

const int N=3*5e4+10;
int fa[N],n,k;
//3倍,同类,吃的,被吃
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
    for(int i=1;i<=n*3;i++){
        fa[i]=i;
    }

    while(k--){
        int op,x,y;cin>>op>>x>>y;

        if(x>n || y>n){
            ans++;
        }
        else if(op==1){
            //x和y+n在一起说明y会吃了x所以不是同类
            if(issame(x,y+n) || issame(x,y+n+n)){
                ans++;
            }
            else{
                un(x,y);
                un(x+n,y+n);
                un(x+n+n,y+n+n);
            }
        }
        else{//x 吃掉 y
            if(issame(x,y) || issame(x+n+n,y)){
                ans++;
            }
            else{
                un(x,y+n+n);
                un(y,x+n);
                un(x+n+n,y+n);
            }
        }
    }
    cout<<ans;
}