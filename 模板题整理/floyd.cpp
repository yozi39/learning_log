#include<bits/stdc++.h>
using namespace std;

const int N=105;
int n,m;
int f[N][N],edge[N][N];

int main(){
    cin>>n>>m;
    //初始化
    memset(f,0x3f,sizeof f);
    for(int i=1;i<=n;i++)f[i][i]=0;
    for(int i=1;i<=m;i++){
        int a,b,c;cin>>a>>b>>c;
        f[a][b]=f[b][a]=min(c,f[a][b]);
    }

    //floyd
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }

    //输出
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<f[i][j]<<' ';
        }
        cout<<'\n';
    }
}