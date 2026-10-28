#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 1e3 + 5,M=2e3+5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n,m;
vector<PII> edge[N];
vector<int> g[N],rg[N];
PII aa[M];
bool v1[N],v2[N],ok[N];

void bfs(int x,vector<int> g[],bool vis[]){
    queue<int> q;
    q.push(x);vis[x]=true;
    while(q.size()){
        int x=q.front();q.pop();
        for(int y:g[x]){
            if(vis[y])continue;
            vis[y]=true;q.push(y);
        }
    }
}

int dist[N],cnt[N];
bool st[N];
bool spfa(int x){
    memset(dist,0x3f,sizeof dist);
    queue<int> q;
    q.push(x);
    st[x] = true;
    dist[x] = 0;

    while(q.size()){
        auto x = q.front();q.pop();
        st[x] = false;

        for(auto t:edge[x]){
            int y = t.first,z=t.second;
            if(!ok[y])continue;

            if(dist[y]>dist[x]+z){
                dist[y] = dist[x]+z;
                cnt[y] = cnt[x]+1;

                if(cnt[y]>=n+1)return true;
                if(!st[y]){
                    q.push(y);
                    st[y] = true;
                }
            }
        }
    }
    return false;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        aa[i].first = a;aa[i].second=b;
        g[a].push_back(b);rg[b].push_back(a);
        edge[a].push_back({b,9});
        edge[b].push_back({a,-1});
    }
    bfs(1,g,v1);
    if(!v1[n]){
        cout<<-1<<qp;
        return 0;
    }
    bfs(n,rg,v2);
    for(int i=1;i<=n;i++){
        ok[i]=v1[i]&&v2[i];
        if(ok[i])edge[0].push_back({i,0});
    }

    if(spfa(0)){
        cout<<-1<<qp;
    } else{
        cout<<n<<' '<<m<<qp;
        for(int i=1;i<=m;i++){
            int a=aa[i].first,b=aa[i].second,w=1;
            if(ok[a]&&ok[b])w=dist[b]-dist[a];
            cout<<a<<' '<<b<<' '<<w<<qp;
        }
    }
}