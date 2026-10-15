#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=30;

LL a,b;
int n,nn[N],mod;
LL f[N][105];

LL dfs(int pos,bool limit,LL sum){
    if(!pos) return (sum%mod)? 0:1;
    if(!limit && ~f[pos][sum%mod]) return f[pos][sum%mod];

    int up = limit? nn[pos]:9;
    LL ret = 0;
    for(int i=0;i<=up;i++){
        ret+=dfs(pos-1,nn[pos]==i && limit,sum+i);
    }

    return limit? ret:f[pos][sum%mod] = ret;
}

LL calc(LL x){
    n = 0;
    memset(f,-1,sizeof f);
    while(x){
        nn[++n] = x%10;
        x /= 10;
    }

    return dfs(n,1,0);
}

int main(){
    while(cin>>a>>b>>mod){
        cout<<calc(b)-calc(a-1)<<'\n';
    }
}