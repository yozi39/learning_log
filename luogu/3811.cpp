#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=3e6;

LL inv[N],n;
LL p;

void get_inv(){
    inv[1]=1;
    cout<<1<<'\n';
    for(int i=2;i<=n;i++){
        inv[i]=p-p/i*inv[p%i]%p;
        cout<<inv[i]<<'\n';
    }
}

int main(){
    cin>>n>>p;
    get_inv();
}