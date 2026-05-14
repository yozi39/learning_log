#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10,MOD=100003;
int n,k;
int dp[N];

int main(){
    cin>>n>>k;
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                dp[i]+=dp[i-j]%MOD;
            }
        }
    }

    cout<<dp[n]%MOD;
}