#include<bits/stdc++.h>
using namespace std;

int n,v;
int a[1010],b[1010];
int dp[1010][1010];

int main(){
    cin>>n>>v;for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<=v;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=a[i]){
                dp[i][j]=max(dp[i][j],dp[i-1][j-a[i]]+b[i]);
            }
        }
    }
    cout<<dp[n][v];
}