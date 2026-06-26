#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL exgcd(LL a,LL b,LL& x,LL& y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    LL x1,y1,d;
    d = exgcd(b,a%b,x1,y1);//为什么要d,因为最后通项要gcd(a,b)
    x=y1;y=x1-a/b*y1;
    return d;
}

int main(){
    int T;scanf("%d",&T);
    while (T--)
    {
        LL a,b,c,x,y;scanf("%lld%lld%lld",&a,&b,&c);
        //裴蜀定理 ax+by=gcd(a,b);
        LL d = exgcd(a,b,x,y);//求出一组特解的x0

        if(c%d != 0){//无解
            printf("-1\n");
        }
        else{
            LL xt,yt,k1,k2,maxx,minx,maxy,miny;
            xt=x*(c/d);yt=y*(c/d);k1=b/d;k2=a/d;
            minx=(xt%k1+k1)%k1;
            if(minx==0)minx=k1;
            maxy=(c-a*minx)/b;
            if(maxy<=0){
                miny=(yt%k2+k2)%k2;
                if(miny == 0) miny = k2;
                printf("%lld %lld\n",minx,miny);
            }
            else{
                miny=(yt%k2+k2)%k2;
                if(miny == 0)miny=k2;
                maxx=(c-b*miny)/a;
                LL cnt=(maxx-minx)/k1+1;
                printf("%lld %lld %lld %lld %lld\n",cnt,minx,miny,maxx,maxy);
            }
        }
    }
    return 0;
}