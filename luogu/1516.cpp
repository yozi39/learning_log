#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL exgcd(LL a,LL b,LL& x,LL& y){
    if(b==0){
        x=1;y=0;
        return a;
    }

    LL x1,y1;
    LL d = exgcd(b,a%b,x1,y1);
    x=y1;y=x1-a/b*y1;
    return d;
}

LL x,y,m,n,l;
LL a,b,c;

int main(){
    cin>>x>>y>>m>>n>>l;

    if(m-n<0){
        a=n-m;
        b=l;
        c=x-y;
    }
    else{
        a=m-n;
        b=l;
        c=y-x;
    }

    LL d = exgcd(a,b,x,y);

    if(c%d != 0){
        cout<<"Impossible";
    }
    else{
        x=x*(c/d);y=y*(c/d);
        LL k1=b/d;
        x=(x%k1+k1)%k1;
        cout<<x;
    }
}