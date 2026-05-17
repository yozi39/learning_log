#include<bits/stdc++.h>
using namespace std;

int n,V;
int v[1010],w[1010];
int dp[1010];

int main(){
    cin>>n>>V;for(int i=1;i<=n;i++)cin>>v[i]>>w[i];

    for(int i=1;i<=n;i++){
        for(int j=v[i];j<=V;j++){
            if(j>=v[i]){
                dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
            }
        }
    }
    cout<<dp[V]<<'\n';

    memset(dp,-0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=v[i];j<=V;j++){
            dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    if(dp[V]<0){cout<<0;return 0;}
    cout<<dp[V];
}