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

/*二进制优化
#include<bits/stdc++.h>
using namespace std;

const int N=110*5;
int n,t,pos;
int w[N],v[N],dp[N];

int main(){
    cin>>n>>t;
    for(int i=1;i<=n;i++){
        int x,y,z;cin>>x>>y>>z;
        //拆分
        int tmp=1;
        while(x>=tmp){
            pos++;
            w[pos]=tmp*y;
            v[pos]=tmp*z;
            x-=tmp;
            tmp*=2;
        }
        
        if(x){//不能拆分了但是还有多的
            pos++;
            w[pos]=x*y;
            v[pos]=x*z;
        }
    }
    //01背包
    for(int i=1;i<=pos;i++){
        for(int j=t;j>=w[i];j--){
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    
    cout<<dp[t];
}
*/

/*  advance
#include<bits/stdc++.h>
using namespace std;

int n,t;
int w[105],v[105],x[105],dp[105];

int main(){
    cin>>n>>t;for(int i=1;i<=n;i++)cin>>x[i]>>w[i]>>v[i];
    
    for(int i=1;i<=n;i++){
        for(int j=t;j>=0;j--){//要去逆序的填表
            for(int z=0;z<=x[i] && z*w[i]<=j;z++){
                dp[j]=max(dp[j],dp[j-z*w[i]]+z*v[i]);
            }
        }
    }
    
    cout<<dp[t];
}
*/