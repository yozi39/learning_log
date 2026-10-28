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
struct node{
    LL u,v,x,y;
}a[N];
vector<int> edge[N];
int dep[N],f[N][25];

void dfs(int x,int fa){
    dep[x] = dep[fa] + 1;
    f[x][0] = fa;

    for(int i=1;i<=20;i++)f[x][i]=f[f[x][i-1]][i-1];
    for(auto y:edge[x]){
        if(y==fa)continue;
        dfs(y,x);
    }
}

int lca(int x,int y){
    if(dep[x] < dep[y])swap(x,y);

    for(int i=20;i>=0;i--){
        if(dep[f[x][i]] < dep[y])continue;

        x = f[x][i];
    }

    if(x == y)return x;

    for(int i=20;i>=0;i--){
        if(f[x][i] != f[y][i]){
            x = f[x][i];
            y = f[y][i];
        }
    }

    return f[x][0];
}

LL ret[N],d[N];
void dfsr(int x,int fa){
    ret[x] = d[x];

    for(auto y:edge[x]){
        if(y == fa)continue;
        dfsr(y,x);

        ret[x] += ret[y];
    }
}

int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>a[i].u>>a[i].v>>a[i].x>>a[i].y;

        edge[a[i].u].push_back(a[i].v);
        edge[a[i].v].push_back(a[i].u);
    }

    dfs(1,0);

    for(int i=1;i<n;i++){
        d[i]++,d[i+1]++;
        int t = lca(i,i+1);
        d[t]-=2;
    }

    dfsr(1,0);

    LL ans = 0;
    for(int i=1;i<n;i++){
        LL x=a[i].u,y=a[i].v,c1=a[i].x,c2=a[i].y;

        if(f[y][0] != x)swap(x,y);
        ans += min(ret[y]*c1,c2);
    }

    cout<<ans;
}