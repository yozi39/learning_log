#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1e9,p=1e9+7;

LL n,k;

LL qpow(LL a,LL b,LL c){
    int ret=1;
    while(a){
        if(a&1)ret = ret*b % c;
        a>>=1;
        b = b * b % c;
    }
    return ret;
}

int main(){
    int T;cin>>T;
    while(T--){
        cin>>n>>k;
        LL ans;
        ans=(qpow(n+1,k+1,p)-k-1)*qpow(p-2,k,p);
        cout<<(ans%p+p)%p<<endl;
    }
}
