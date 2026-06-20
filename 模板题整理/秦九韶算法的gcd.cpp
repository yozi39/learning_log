//niuke 275615 https://ac.nowcoder.com/acm/problem/275615
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

string a;
LL b;

LL gcd(LL a,LL b){
    return b==0? a:gcd(b,a%b);
}

LL calc(){
    LL t=0;
    for(auto y:a){
        t=10*t+y-'0';
        t%=b;
    }
    return t;
}

int main(){
    cin>>a>>b;
    cout<<gcd(b,calc());
}