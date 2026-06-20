#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int p=1000000007;

LL qpow(LL a,LL b,LL p){
    LL ret=1;
    while(a){
        if(a&1) ret = ret*b%p;
        a >>= 1;
        b = b*b%p;
    }
    return ret;
}

int main(){
    LL n;
    while(cin>>n){
        LL S=(((n%p)*(n%p+1))%p*(n%p*2+1)%p)*qpow(p-2,6,p);
        cout << (S%p+p)%p << endl;
    }
}