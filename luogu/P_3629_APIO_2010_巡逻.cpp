#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 2e5 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n,k;
vector<int> edge[N];
LL ret,d[N],pre[N],f[N];
LL maxd,r=1,L,R,l1,l2,maxcnt=1;
bool st[N];

void dfs(int x,int fa){
    pre[x] = fa;
    if(d[x]>maxd){
        maxd=d[x],r=x,maxcnt=1;
    }
    if(d[x] == maxd)maxcnt++;

    for(auto y:edge[x]){
        if(y == fa)continue;

        d[y] = d[x] + 1;
        dfs(y,x);
    }
}

void dp(int x,int fa){
    for(auto y:edge[x]){
        if(y==fa)continue;
        dp(y,x);

        int w=(st[x] && st[y])? -1:1;
        l2 = max(l2,f[x] + f[y] + w);
        f[x] = max(f[x],f[y] + w);
    }
}

int main(){
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    dfs(1,0);L = r,maxd=d[r]=0;
    dfs(r,0);R=r,l1=maxd;

    if(k==1){
        cout<<2*n-1-l1;
        return 0;
    }

    for(int i=R;i;i=pre[i])st[i] = true;

    dp(1,0);

    cout<< 2*n - l1 - l2;
}