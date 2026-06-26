#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
//这个题目a可以出现负数,调用qmul要保证b>=0
const int N=15;
//r全部是0
LL a[N],m[N];
LL x,y;
int n;

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
    LL M=1;for(int i=1;i<=n;i++)M *= m[i];

    LL ret=0;
    for(int i=1;i<=n;i++){
        LL c=M/m[i];
        exgcd(c,m[i],x,y);
        x=(x%m[i]+m[i])%m[i];

        //防止因为a的负导致ret变小而题目要的是正整数所以要补正
        ret = ((ret+qmul(a[i],qmul(x,c,M),M))%M+M)%M;
    }
    return ret;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>m[i];
    }

    cout<<crt();
}