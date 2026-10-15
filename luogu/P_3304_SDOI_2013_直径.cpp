#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 2e5 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n;
bool st[N];
vector<PLL> edge[N];
LL pre[N],L,R,r,d[N];
LL maxd,D;

void dfs(int x,int fa){
    pre[x] = fa;
    if(d[x]>maxd) maxd = d[x],r=x;
    
    for(auto tmp:edge[x]){
        int y = tmp.first,z=tmp.second;
        if(y==fa || st[y])continue;

        d[y] = d[x] + z;
        dfs(y,x);
    }
}

int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b,c;cin>>a>>b>>c;
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }

    dfs(1,0);L = r;
    d[L]=maxd=0;
    dfs(r,0);R=r;
    D = maxd;
    cout<<D<<qp;

    for(int i=R;i;i=pre[i])st[i]=true;

    for(int i=R;i;i=pre[i]){
        LL ld = d[i],rd = D - d[i];


        maxd=d[i]=0;
        dfs(i,pre[i]);
        if(maxd == rd) R = i;
        if(maxd == ld){
            L = i;
            break;
        }
    }

    int cnt = 0;
    for(int i=R;i!=L;i=pre[i])cnt++;
    cout<<cnt;
}