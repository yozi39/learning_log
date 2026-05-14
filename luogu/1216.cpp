#include<bits/stdc++.h>
using namespace std;

const int N=1010;

int n;
int dp[N],a[N][N];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            cin>>a[i][j];
    //
    for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--){
            dp[j]=max(dp[j],dp[j-1])+a[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i]);
    }
    cout<<ans;
}