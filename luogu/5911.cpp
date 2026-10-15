#include<bits/stdc++.h>
using namespace std;

const int N=20;

int W,n;
int t[N],w[N];
int dp[1<<N];
int sumw[1<<N],maxt[1<<N];

int main(){
    cin>>W>>n;
    for(int i=0;i<n;i++){
        cin>>t[i]>>w[i];
    }

    // 预处理：每一个集合的总重量、最大时间
    for(int st=0;st<(1<<n);st++){
        for(int i=0;i<n;i++){
            if((st>>i)&1){
                sumw[st]+=w[i];
                maxt[st]=max(maxt[st],t[i]);
            }
        }
    }

    memset(dp,0x3f,sizeof dp);
    dp[0]=0;

    for(int st=1;st<(1<<n);st++){
        // y = 最后一批过桥的人
        for(int y=st;y;y=st&(y-1)){
            if(sumw[y]>W)continue;

            dp[st]=min(dp[st],dp[st^y]+maxt[y]);
        }
    }

    cout<<dp[(1<<n)-1];
}

//收获
//拆分子集其实不一定只能用在预处理里面,这里用在
//dp过程中才能不会TLE