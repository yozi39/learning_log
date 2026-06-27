#include<iostream>
using namespace std;
typedef long long LL;

//1.
LL qpow(LL a,LL b,LL p){
    LL ret=1;
    while(b){
        if(b&1)ret = ret*a%p;
        a=a*a%p;
        b>>=1;
    }
    return ret;
}

LL c(int n,int m,int p){
    if(n<m)return 0;
    LL up=1,down=1;
    for(LL i=n-m+1;i<=n;i++)up=up*i%p;
    for(LL i=2;i<=m;i++)down=down*i%p;
    return up*qpow(down,p-2,p)%p;
}

//2.
//https://www.luogu.com.cn/problem/P2822
//杨辉三角和前缀和数组

const int N=2010;

int n,m,k;
int f[N][N];
int g[N][N];


void get_table(){
    for(int i=0;i<=2000;i++){
        f[i][0]=1;
        for(int j=1;j<=i;j++){
            f[i][j]=(f[i-1][j-1]+f[i-1][j])%k;
            g[i][j]=g[i-1][j]+g[i][j-1]-g[i-1][j-1]+(f[i][j] == 0 ? 1:0);
        }
        g[i][i+1]=g[i][i];
    }
}

int main(){
    int T;scanf("%d%d",&T,&k);
    get_table();
    while(T--){
        scanf("%d%d",&n,&m);
        printf("%d\n",g[n][min(n,m)]);
    }
}

/*
3.打表阶乘以及阶乘的逆元表
    求逆元:
        1.费马小定理
        2.exgcd
        3.打表逆元
        4.打表i的阶乘逆元
*/
//https://www.luogu.com.cn/problem/B3717
const int N=5e6+10,P=998244353;

LL ff[N],gg[N];

LL qpow(LL a,LL b,LL p){
    LL ret=1;
    while(b){
        if(b&1)ret=ret*a%p;
        a=a*a%p;
        b>>=1;
    }
    return ret;
}

LL c(LL n,LL m){
    if(n<m)return 0;
    return ff[n]*gg[n-m]%P*gg[m]%P;
}

int main(){
    int T,n;scanf("%d%d",&T,&n);
    ff[0]=1;
    for(int i=1;i<=n;i++){
        ff[i]=ff[i-1]*i%P;
    }
    
    gg[n]=qpow(ff[n],P-2,P);
    for(int i=n-1;i>=0;i--){
        gg[i]=(i+1)*gg[i+1]%P;
    }
    
    LL ans=0;
    while(T--){
        LL n,m;scanf("%lld%lld",&n,&m);
        ans ^= c(n,m);
    }
    printf("%lld\n",ans);
}


/*
4.卢卡斯定理
Cmn同余C(m/p)(n/p)*C(m%p)(n%p)在mod p的意义下
*/
//https://www.luogu.com.cn/problem/P3807
const int M=1e5+10;
LL n,m,p;
LL fff[M],ggg[M];

LL qpow(LL a,LL b,LL p){
    LL ret=1;
    while(b){
        if(b&1)ret=ret*a%p;
        a=a*a%p;
        b>>=1;
    }
    return ret;
}

void init(){
    fff[0]=1;
    for(int i=1;i<=p-1;i++){//注意到p会污染逆元表全部变0,所以只能到p-1
        fff[i]=i*fff[i-1]%p;
    }
    ggg[p-1]=qpow(fff[p-1],p-2,p);
    for(int i=p-2;i>=0;i--){
        ggg[i]=ggg[i+1]*(i+1)%p;
    }
}

LL C(LL a,LL b,LL p){
    if(a<b)return 0;
    return fff[a]*ggg[a-b]%p*ggg[b]%p;
}

LL lucas(LL n,LL m,LL p){
    if(m==0)return 1;
    return lucas(n/p,m/p,p)*C(n%p,m%p,p)%p;
}

int main(){
    int T;cin>>T;
    
    while(T--){
        cin>>n>>m>>p;
        init();
        cout<<lucas(n+m,m,p)<<'\n';    
    }
}