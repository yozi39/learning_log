#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=15;

int n;
LL m[N],b[N];
LL x,y;

LL qmul(LL a,LL b,LL p){
    LL ret=0;
    while(b){
        if(b&1)ret = (ret+a)%p;
        b>>=1;
        a=(a+a)%p; 
    }
    return ret;
}

void exgcd(LL a,LL b,LL& x,LL& y){
    if(b==0){
        x=1;y=0;
        return;
    }

    LL x1,y1;
    exgcd(b,a%b,x1,y1);
    x=y1;y=x1-a/b*y1;
    return;
}

LL crt(){
    LL M=1;for(int i=1;i<=n;i++)M*=m[i];
    LL ret=0;

    for(int i=1;i<=n;i++){
        LL c=M/m[i];
        exgcd(c,m[i],x,y);
        x=(x%m[i]+m[i])%m[i];

        ret = (ret+qmul(qmul(x,c,M),b[i],M))%M;
    }
    return ret;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m[i]>>b[i];
    }

    cout<<crt();
}