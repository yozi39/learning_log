#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    return b==0 ? a:gcd(b,a%b);
}

int main(){
    int n;cin>>n;
    int ans;cin>>ans;ans=abs(ans);
    for(int i=2;i<=n;i++){
        int x;cin>>x;x=abs(x);
        ans = gcd(ans,x);
    }
    cout<<ans;
}