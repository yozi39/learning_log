#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define lowbit(x) (x & -x)

const int N=1e5+10;

int n,m;
LL a[N];

struct BIT{
    LL tr[N];

    void add(int x,LL v){
        for(int i=x;i<=n;i+=lowbit(i))
            tr[i]+=v;
    }

    LL query(int x){
        LL res=0;
        for(int i=x;i;i-=lowbit(i))
            res+=tr[i];
        return res;
    }
}t1,t2;

int main(){
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        t1.add(i,a[i]);
        t2.add(i,1LL*i*a[i]);
    }

    while(m--){
        string op;
        int x;
        cin>>op>>x;

        if(op[0]=='Q'){
            cout<<1LL*(x+1)*t1.query(x)-t2.query(x)<<'\n';
        }
        else{
            LL v;
            cin>>v;

            LL d=v-a[x];

            t1.add(x,d);
            t2.add(x,1LL*x*d);

            a[x]=v;
        }
    }
}