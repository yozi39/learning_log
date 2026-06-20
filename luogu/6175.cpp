#include<bits/stdc++.h>
using namespace std;

const int N=110,INF=1e8;

int n,m;
int e[N][N],f[N][N];

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[i][j]=e[i][j]=INF;
        }
    }
    for(int i=1;i<=n;i++)e[i][i]=f[i][i]=0;
    for(int i=1;i<=m;i++){
        int a,b,c;cin>>a>>b>>c;
        e[a][b]=e[b][a]=f[b][a]=f[a][b]=min(c,e[a][b]);
    }

    int ans=INF;
    for(int k=1;k<=n;k++){
        for(int i=1;i<k;i++){//这里要小于k,因为后续的点还没有加入,不能==k因为加上k变成负环
            for(int j=i+1;j<k;j++){//注意不能i==j不然会错误的出来ans=0;
                ans=min(ans,f[i][j]+e[i][k]+e[k][j]);
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    if(ans==INF)cout<<"No solution.";
    else{cout<<ans;}
}