#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef __int128 LLL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'
#define DEBUG_1

const LL N = 70;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

#ifdef DEBUG_1
#define CHECK cout<<1<<qp;
#endif

int n,nn[N];
LL f[N][2][2*N+5];

LL dfs(int pos,bool limit,int sum,bool flag){
    if(!pos) return (!flag && sum>=0);
    if(~f[pos][limit][sum+N] && !flag) return f[pos][limit][sum+N];

    int up = limit? nn[pos]:1;
    LL ret = 0;
    for(int i=0;i<=up;i++){
        if(flag && i==0){
            ret+=dfs(pos-1,limit&&(i==nn[pos]),sum,1);
        }
        else{
            ret+=dfs(pos-1,
                    limit&&(i==nn[pos]),
                    sum+(i==0?1:-1),
                    0);
        }
    }

    return (limit||flag)? ret:f[pos][limit][sum+N] = ret;
}

LL calc(LL x){
    n=0;
    memset(f,-1,sizeof f);
    while(x){
        nn[++n] = x%2;
        x /= 2;
    }

    return dfs(n,1,0,1);
}

int main(){
    LL a,b;
    cin>>a>>b;
    cout<<calc(b)-calc(a-1)<<qp;
}