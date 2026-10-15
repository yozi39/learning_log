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
LL ret,f[N];
map<PII,int> mp;
vector<int> edge[N];

void add(int a,int b,int i){
    if(a>b)swap(a,b);

    if(mp.count({a,b})){
        int j = mp[{a,b}];
        edge[i].push_back(j);
        edge[j].push_back(i);
    }

    mp[{a,b}] = i;
}

void dfs(int x,int fa){
    for(auto y: edge[x]){
        if(y==fa)continue;
        dfs(y,x);

        ret = max(ret,f[x]+f[y]+1);
        f[x] = max(f[x],f[y]+1);
    }
}

int main(){
    cin>>n;
    for(int i=1;i<n-1;i++){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,i);add(a,c,i);add(b,c,i);
    }

    dfs(1,0);
    cout<<ret+1;
}