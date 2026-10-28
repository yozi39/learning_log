#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 50 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n,m,k;
vector<PII> edge[N];
struct node{
    LL d,x,cnt;
    bool operator<(const node& a)const{
        return d > a.d;
    }
};
LL dist[N][N];
bool st[N][N];

void dijkstra(){
    memset(dist,INF,sizeof dist);
    priority_queue<node> heap;
    heap.push({0,1,0});
    dist[1][0] = 0;

    while(heap.size()){
        auto t = heap.top();heap.pop();
        auto x = t.x,cnt = t.cnt;
        if(st[x][cnt])continue;
        st[x][cnt] = true;

        for(auto t:edge[x]){
            auto y = t.first,z = t.second;

            if(dist[y][cnt] > dist[x][cnt] + z){
                dist[y][cnt] = dist[x][cnt] + z;
                heap.push({dist[y][cnt],y,cnt});
            }

            if(cnt < k && dist[y][cnt+1] > dist[x][cnt] + z/2){
                dist[y][cnt+1] = dist[x][cnt] + z/2;
                heap.push({dist[y][cnt+1],y,cnt+1});
            }
        }
    }
}

int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int a,b,c;cin>>a>>b>>c;
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }

    dijkstra();

    LL ret = 1e18;
    for(int i=0;i<=k;i++){
        ret = min(ret,dist[n][i]);
    }
    cout<<ret;
}