#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define lowbit(x) (x&-x)

const int N=1e6+5;

int n,q;
struct tree{
    LL a[N];

    void modify(int x,LL k){
        for(int i=x;i<=n;i+=lowbit(i))a[i]+=k;
    }

    LL query(int x){
        LL sum=0;
        for(int i=x;i;i-=lowbit(i))sum+=a[i];
        return sum;
    }
}d,dx;

LL query(int x){
    return 1LL*(x+1)*d.query(x)-dx.query(x);
}

int main(){
    cin>>n>>q;

    for(int i=1;i<=n;i++){
        LL x;cin>>x;

        d.modify(i,x);
        d.modify(i+1,-x);

        dx.modify(i,1LL*i*x);
        dx.modify(i+1,-1LL*(i+1)*x);
    }

    while(q--){
        int op,l,r;
        LL x;
        cin>>op>>l>>r;

        if(op==1){
            cin>>x;

            d.modify(l,x);
            d.modify(r+1,-x);

            dx.modify(l,1LL*l*x);
            dx.modify(r+1,-1LL*(r+1)*x);
        }else{
            cout<<query(r)-query(l-1)<<'\n';
        }
    }
}