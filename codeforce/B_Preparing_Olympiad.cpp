#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 20 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

LL n,l,r,x;
LL c[N],ret;

void dfs(int x,LL sum,LL maxn,LL minn){
    if(x > n){
        if(sum>=l && sum<=r && maxn-minn>=::x)ret++;
        return;
    }

    dfs(x+1,sum+c[x],max(maxn,c[x]),min(minn,c[x]));
    dfs(x+1,sum,maxn,minn);
}

int main(){
    cin>>n>>l>>r>>x;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }

    dfs(1,0,0,LINF);

    cout<<ret;
}