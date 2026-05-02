#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL a,b,p;
LL ans=1;

int main(){
    cin>>a>>b>>p;
    LL ansa,ansb;
    ansa=a;
    ansb=b;
    //快速幂模板
    while(b>0){
        if(b&1) ans = ans*a%p; 
        a = a*a%p;
        b>>=1;
    }
    cout<<ansa<<'^'<<ansb<<" mod "<<p<<'='<<ans;
}