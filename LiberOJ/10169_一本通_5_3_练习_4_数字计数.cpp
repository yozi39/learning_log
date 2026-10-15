#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef __int128 LLL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'
#define DEBUG_1

const LL N = 20;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

#ifdef DEBUG_1
#define CHECK cout<<1<<qp;
#endif

int n,nn[N],d;
LL f[N][N][2][2];

LL dfs(int pos,LL sum,bool limit,bool flag){
    if(!pos) return sum;
    if(~f[pos][sum][limit][flag])return f[pos][sum][limit][flag];

    int up = limit? nn[pos]:9;
    LL ret = 0;
    for(int i=0;i<=up;i++){
        int t = (i==d? 1:0);
        if(flag && !d && !i) t=0;

        ret += dfs(pos-1,sum+t,limit && (i==nn[pos]),flag && !i);
    }

    return f[pos][sum][limit][flag] = ret;
}

LL calc(LL x){
    n=0;memset(f,-1,sizeof f);

    while(x){
        nn[++n] = x%10;
        x/=10;
    }    

    return dfs(n,0,1,1);
}

int main(){
    LL a,b;
    cin>>a>>b;
    for(d=0;d<=9;d++){
        cout<<calc(b)-calc(a-1)<<' ';
    }
    cout<<qp;
}