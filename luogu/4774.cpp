#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
//用multiset防止剑去重
const int N=1e5+10;

int n,p;
LL m[N],r[N],a[N];
LL s[N],maxn;

LL qmul(LL a,LL b,LL p){
    LL ret=0;
    while(b){
        if(b&1)ret=(ret+a)%p;
        b>>=1;
        a=(a+a)%p;
    }
    return ret;
}

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

void init (){
    //初始化
    maxn=0;
    cin>>n>>p;
    for(int i=1;i<=n;i++)cin>>r[i];
    for(int i=1;i<=n;i++)cin>>m[i];
    for(int i=1;i<=n;i++)cin>>s[i];
    
    multiset<LL> mp;
    for(int i=1;i<=p;i++){
        LL tmp;cin>>tmp;
        mp.insert(tmp);
    }

    //分配剑
    for(int i=1;i<=n;i++){
        auto it=mp.upper_bound(r[i]);
        if(it != mp.begin()){
            it--;
        }
        a[i]=*it;
        mp.erase(it);mp.insert(s[i]);
    
        //找出最小攻击次数的最大值,因为x是一个对于每一个龙的所以要让最后ret>max
        maxn=max(maxn,(r[i]+a[i]-1)/a[i]);
    }
}

LL excrt(){
    LL M=1,ret=0;
    for(int i=1;i<=n;i++){
        //Ax+by=c
        LL b=m[i],A=qmul(a[i],M,b),c=r[i]-a[i]*ret;
        c=(c%b+b)%b;

        LL x,y;
        LL d=exgcd(A,b,x,y);
        if(c%d!=0){
            return -1;
        }
        LL k1=b/d;
        x=qmul(x,(c/d),k1);
        x=(x%k1+k1)%k1;

        ret=ret+M*x;
        M=k1*M;
        ret = (ret%M+M)%M;
    }
    if(ret<maxn)ret = ret+(maxn-ret-1+M)/M*M;
    return ret;
}

void solve(){
    init();

    cout<<excrt()<<'\n';
}

int main(){
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}