#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+20,INF=0x3f3f3f3f;

LL n,l,r;
LL a[N];
LL dp[N];
deque<LL> q;

void insert(int x){
    int tmp=x-l;
    if(tmp>=0 && dp[tmp]!=-INF){
        while(q.size() && dp[q.back()] <= dp[tmp])q.pop_back();
        q.push_back(tmp);
    }
    while(q.size() && q.front()<x-r)q.pop_front();
}

LL query(){
    return q.front();
}

int main(){
    cin>>n>>l>>r;
    for(int i=0;i<=n;i++){
        cin>>a[i];
        dp[i]=-INF;
    }
    dp[0]=0;
    for(int i=1;i<=n;i++){
        insert(i);
        if(q.size()){
            dp[i]=dp[q.front()]+a[i];
        }
    }

    LL ans=-INF;
    for(int i=max(0LL,n-r+1);i<=n;i++){
        ans=max(ans,dp[i]);
    }
    cout<<ans;
}