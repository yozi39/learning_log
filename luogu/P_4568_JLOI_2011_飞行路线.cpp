#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 1.1e5 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n,m,k,s,t;
vector<PII> edge[N];
int dist[N];bool st[N];

void dijkstra(){
    memset(dist,INF,sizeof dist);
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,s});
    dist[s] = 0;

    while(heap.size()){
        auto x = heap.top().second;heap.pop();
        if(st[x])continue;
        st[x] = true;

        for(auto t:edge[x]){
            auto y = t.first,z = t.second;
            if(dist[y] > dist[x] + z){
                dist[y] = dist[x] + z;
                heap.push({dist[y],y});
            }
        }
    }
}

int main(){
    cin>>n>>m>>k>>s>>t;
    for(int i=1;i<=m;i++){
        int a,b,c;cin>>a>>b>>c;
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
        //分层
        for(int j=1;j<=k;j++){
            int x = a+n,y = b+n;
            //当前层的普通边
            edge[x].push_back({y,c});edge[y].push_back({x,c});
            //更新夹层边
            edge[a].push_back({y,0});edge[b].push_back({x,0});
            //上层
            a = x,b = y;
        }
    }

    dijkstra();
    
    int ret = 1e9;
    for(int i=0;i<=k;i++){
        ret = min(ret,dist[t+i*n]);
    }
    cout<<ret;
}