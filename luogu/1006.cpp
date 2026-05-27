#include<bits/stdc++.h>
using namespace std;

const int N=55;
int n,m;
int mp[N][N],dp[N][N][N][N];

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int l=1;l<=n;l++){
                for(int z=1;z<=m;z++){
                    if(i+j!=l+z)continue;

                    dp[i][j][l][z]=max(
                        max(dp[i-1][j][l-1][z],dp[i-1][j][l][z-1]),
                        max(dp[i][j-1][l-1][z],dp[i][j-1][l][z-1])
                    )+mp[i][j]+mp[l][z];

                    if(i==l && j==z)dp[i][j][l][z]-=mp[i][j];
                }
            }
        }
    }

    cout<<dp[n][m][n][m];
}