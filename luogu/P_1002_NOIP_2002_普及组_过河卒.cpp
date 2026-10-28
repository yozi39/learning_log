#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define qp '\n'

const int N=25;
int n,m,x,y;
LL dp[N][N];
bool st[N][N];

int dx[9]={0,1,1,-1,-1,2,2,-2,-2};
int dy[9]={0,2,-2,2,-2,1,-1,1,-1};

int main(){
    cin>>n>>m>>x>>y;

    for(int i=0;i<9;i++){
        int a=x+dx[i],b=y+dy[i];
        if(a>=0&&a<=n&&b>=0&&b<=m)
            st[a][b]=true;
    }

    if(!st[0][0])dp[0][0]=1;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(st[i][j])continue;
            if(i==0&&j==0)continue;

            if(i>0)dp[i][j]+=dp[i-1][j];
            if(j>0)dp[i][j]+=dp[i][j-1];
        }
    }

    cout<<dp[n][m]<<qp;
}