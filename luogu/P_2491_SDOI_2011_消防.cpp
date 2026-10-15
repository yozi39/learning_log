#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 3e5 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n,s;
LL pre[N],maxd,d[N],r=1;
bool st[N];
LL L,R,ret=1e18,D;
vector<PLL> edge[N];

void dfs(int x,int fa){
    pre[x]=fa;
    if(d[x]>maxd)maxd=d[x],r=x;

    for(auto v:edge[x]){
        auto y = v.first,z=v.second;
        if(y==fa || st[y])continue;

        d[y] = d[x] + z;
        dfs(y,x);
    }
}

int main(){
    cin>>n>>s;

    for(int i=1;i<n;i++){
        int a,b,c;cin>>a>>b>>c;
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }

    dfs(1,0);maxd=d[r]=0;
    L = r;
    dfs(r,0);R = r,D=maxd;

    for(int i=R;i!=L;i=pre[i])st[i]=true;

    for(int left = R,right = R;right;right=pre[right]){
        while(d[left] - d[right] > s)left = pre[left];

        ret = min(ret,max(D-d[left],d[right]));
    }

    for(int i=R;i;i=pre[i]){
        d[i]=maxd=0;
        dfs(i,pre[i]);
        ret = max(ret,maxd);
    }

    cout<<ret;
}