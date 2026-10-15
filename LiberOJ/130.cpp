#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) (x & -x)
typedef long long LL;

const int N=1e6+5;

int n,q;
LL s[N];

void modify(int x,int k){
    for(int i=x;i<=n;i=i+lowbit(i)){
        s[i]+=k;
    }
}

LL query(int x){
    LL sum=0;
    for(int i=x;i;i=i-lowbit(i)){
        sum+=s[i];
    }
    return sum;
}

int main(){
    cin>>n>>q;

    for(int i=1;i<=n;i++){
        int x;cin>>x;
        modify(i,x);
    }

    while(q--){
        int op,a,b;
        cin>>op>>a>>b;
        if(op==1){
            modify(a,b);
        } else {
            LL l=query(a-1);
            LL r=query(b);
            cout<<r-l<<'\n';
        }
    }
}