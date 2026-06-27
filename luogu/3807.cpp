#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1e5+10;

LL n,m,p;
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

void init(){
    f[0]=1;
    for(int i=1;i<=p-1;i++){//注意到p会污染逆元表全部变0,所以只能到p-1
        f[i]=i*f[i-1]%p;
    }
    g[p-1]=qpow(f[p-1],p-2,p);
    for(int i=p-2;i>=0;i--){
        g[i]=g[i+1]*(i+1)%p;
    }
}

LL C(LL a,LL b,LL p){
    if(a<b)return 0;
    return f[a]*g[a-b]%p*g[b]%p;
}

LL lucas(LL n,LL m,LL p){
    if(m==0)return 1;
    return lucas(n/p,m/p,p)*C(n%p,m%p,p)%p;
}

int main(){
    int T;cin>>T;
    
    while(T--){
        cin>>n>>m>>p;
        init();
        cout<<lucas(n+m,m,p)<<'\n';    
    }
}