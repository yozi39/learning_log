#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n;
vector<LL> f;

int main(){
    cin>>n;
    if(n==1){
        cout<<1;
        return 0;
    }
    if(n==2){
        cout<<2;
        return 0;
    }
    f.push_back(1);f.push_back(1);f.push_back(2);
    for(LL i=2;i<n;i++){
        LL tmp=f[i-2]+f[i-1]+f[i];
        f.push_back(tmp);
    }
    cout<<f[f.size()-1];
}