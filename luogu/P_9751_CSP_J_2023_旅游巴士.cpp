#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 1e4 + 5,K=105;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n,m,k;
vector<PII> edge[N];
LL dist[N][K];
bool st[N][K];

void dijkstra(){
    memset(dist,INF,sizeof dist);
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,1});
    dist[1][0] = 0;

    while(heap.size()){
        auto tmp = heap.top();heap.pop();
        auto x = tmp.second,t = tmp.first;
        if(st[x][t%k])continue;
        st[x][t%k] = true;

        for(auto ti:edge[x]){
            auto y = ti.first,z = ti.second;
            int p = t;
            if(t<z) p += (z-p+k-1)/k*k;
            if(dist[y][(p+1)%k] > p + 1){
                dist[y][(p+1)%k] = p+1;
                heap.push({p+1,y});
            }
        }
    }
}

int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int a,b,c;cin>>a>>b>>c;
        edge[a].push_back({b,c});       
    }

    dijkstra();

    if(dist[n][0] == LINF)cout<<-1;
    else cout<<dist[n][0];
}