#include<bits/stdc++.h>
using namespace std;
//同时活动DP
int n;
int dp[10][10][10][10],mp[10][10];

int main(){
    cin>>n;
    while(true){
        int tmp1,tmp2;cin>>tmp1>>tmp2;
        cin>>mp[tmp1][tmp2];
        if(!(tmp1 && tmp2 && mp[tmp1][tmp2]))break;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int z=1;z<=n;z++){
                for(int l=1;l<=n;l++){
                    if(i + j != z + l) continue;

                    dp[i][j][z][l]=max(max(dp[i-1][j][z-1][l],dp[i-1][j][z][l-1]),max(dp[i][j-1][z-1][l],dp[i][j-1][z][l-1]))+mp[i][j]+mp[z][l];
                    if(i == z && j == l)dp[i][j][z][l]-=mp[i][j];
                }
            }
        }
    }
    
    cout<<dp[n][n][n][n];
}


/*advance
    for(int k = 2; k <= 2 * n; k++){
        for(int i = 1; i <= n; i++){
            for(int z = 1; z <= n; z++){

                int j = k - i;
                int l = k - z;

                if(j < 1 || j > n || l < 1 || l > n) continue;

                int add = mp[i][j] + mp[z][l];

                if(i == z && j == l){
                    add -= mp[i][j];
                }

                f[k][i][z] =
                    max(
                        max(f[k-1][i-1][z-1], f[k-1][i-1][z]),
                        max(f[k-1][i][z-1],   f[k-1][i][z])
                    ) + add;
            }
        }
    }
*/