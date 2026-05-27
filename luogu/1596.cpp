#include<bits/stdc++.h>
using namespace std;
//二维变一维要从0开始存
const int N=105*105*105,dx[4]={0,1,1,1},dy[4]={1,1,0,-1};
int n,m;
char mp[105][105];
int fa[N];

pair<int,int> fix(int p){//恢复回去
    int x = (p - 1) / m + 1;
    int y = (p - 1) % m + 1;
    pair<int,int> tmp;tmp.first=x;tmp.second=y;
    return tmp;
}

int change(int x,int y){
    return (x-1)*m+y;//开头说的
}

int find(int x){
    return fa[x]==x? x:fa[x]=find(fa[x]);
}

void un(int x,int y){
    int xo=find(x);
    int yo=find(y);
    fa[xo]=yo;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        fa[i]=i;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]=='W'){
                for(int k=0;k<4;k++){
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(nx>=1 && nx<=n && ny>=1 && ny<=m){
                        int pos=change(nx,ny);
                        if(mp[i+dx[k]][j+dy[k]]=='W'){
                            un(pos,change(i,j));
                        }
                    }
                }
            }
        }
    }

    int ans=0;
    for(int i=1;i<=n*m;i++){
        pair<int,int> tmp=fix(i);
        if(fa[i]==i && mp[tmp.first][tmp.second]=='W')ans++;
    }
    cout<<ans;
}