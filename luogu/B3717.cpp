#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=5e6+10,P=998244353;

LL f[N],g[N];

LL qpow(LL a,LL b,LL p){
    LL ret=1;
    while(b){
        if(b&1)ret=ret*a%p;
        a=a*a%p;
        b>>=1;
    }
    return ret;
}

LL c(LL n,LL m){
    if(n<m)return 0;
    return f[n]*g[n-m]%P*g[m]%P;
}

int main(){
    int T,n;scanf("%d%d",&T,&n);
    f[0]=1;
    for(int i=1;i<=n;i++){
        f[i]=f[i-1]*i%P;
    }
    
    g[n]=qpow(f[n],P-2,P);
    for(int i=n-1;i>=0;i--){
        g[i]=(i+1)*g[i+1]%P;
    }
    
    LL ans=0;
    while(T--){
        LL n,m;scanf("%lld%lld",&n,&m);
        ans ^= c(n,m);
    }
    printf("%lld\n",ans);
}