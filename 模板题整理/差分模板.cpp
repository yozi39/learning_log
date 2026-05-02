#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    LL n,q;
    cin>>n>>q;
    LL a[n+1];
    LL f[n+1];
    memset(a,0,sizeof(a));
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i]=a[i]-a[i-1];
    }
    for(int i=1;i<=q;i++){
        LL front,back;
        cin>>front>>back;
        LL op;
        cin>>op;

        f[front]+=op;
        f[back+1]-=op;
    }
    LL sum=0;
    for(int i=1;i<=n;i++){
        sum+=f[i];
        a[i]=sum;
    }

    for(int i=1;i<=n;i++){
        cout<<a[i]<<' ';
    }
}
//NC226303 一样代码