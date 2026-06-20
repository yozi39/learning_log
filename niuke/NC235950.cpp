#include<bits/stdc++.h>
using namespace std;

int n,t;
int w[105],v[105],x[105],dp[105][105];

int main(){
    cin>>n>>t;for(int i=1;i<=n;i++)cin>>x[i]>>w[i]>>v[i];
    
    for(int i=1;i<=n;i++){
        for(int j=t;j>=0;j--){//要去逆序的填表
            for(int z=0;z<=x[i] && z*w[i]<=j;z++){
                dp[i][j]=max(dp[i][j],dp[i-1][j-z*w[i]]+z*v[i]);
            }
        }
    }
    
    cout<<dp[n][t];
}