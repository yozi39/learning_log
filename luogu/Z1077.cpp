#include<bits/stdc++.h>
using namespace std;
//多重背包的方案数
const int N=105,MOD=1e6+7;
int n,m;
long long a[N],dp[N][N];

int main(){
    cin>>n>>m;for(int i=1;i<=n;i++)cin>>a[i];

    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            for(int z=0;z<=min(1LL*j,a[i]);z++){
                dp[i][j]=dp[i][j]+dp[i-1][j-z]%MOD;
            }
        }
    }
    cout<<dp[n][m]%MOD;
}