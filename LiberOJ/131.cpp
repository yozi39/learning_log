#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) (x & -x)
typedef long long LL;

const int N=1e6+5;

int n,q;
LL a[N];

void modify(int x,LL k){
    for(int i=x;i<=n;i+=lowbit(i)){
        a[i]+=k;
    }
}

LL query(int x){
    LL sum=0;
    for(int i=x;i;i-=lowbit(i)){
        sum+=a[i];
    }
    return sum;
}

int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        modify(i,x);
        modify(i+1,-x);
    }

    while (q--)
    {
        int op,l,r,x;
        cin>>op;
        if(op==1){
            cin>>l>>r>>x;
            modify(l,x);
            modify(r+1,-x);
        } else {
            cin>>x;
            cout<<query(x)<<'\n';
        }
    }
}