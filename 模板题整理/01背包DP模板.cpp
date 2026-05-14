#include<bits/stdc++.h>
using namespace std;

int n,V;
int dp[1010][1010],v[1010],w[1010];

int main(){
    cin>>n>>V;for(int i=1;i<=n;i++){cin>>v[i]>>w[i];}
    //1Q

    for(int i=1;i<=n;i++){
        for(int j=0;j<=V;j++){
            dp[i][j]=dp[i-1][j];//不选
            if(j>=v[i]){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+w[i]);//w[i]放进去只有选了才可以增加价值
            }
        }
    }
    cout<<dp[n][V]<<'\n';

    //2Q

    memset(dp,-0x3f,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=V;j++){
            dp[i][j]=dp[i-1][j];//不选
            if(j>=v[i]){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+w[i]);
            }
        }
    }
    if(dp[n][V]<0){cout<<0;return 0;}
    cout<<dp[n][V];
}