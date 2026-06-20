#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL x,y,z;

LL gcd(LL a,LL b){
    return b==0 ? a:gcd(b,a%b);
}

int main(){
    cin>>x>>y>>z;
    int ans=gcd(gcd(x,y),z);
    cout<<ans;
}