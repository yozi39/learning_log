#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;

#define qp '\n'

const int N = 1e5 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;

int n,m;
int v[N];
vector<PII> edge[N];
LL dist[N][3];
bool st[N][3];

struct node{
    LL d;
    int x,k;
    bool operator<(const node& a)const{
        return d > a.d;
    }
};

LL get(LL d,int x,int k){
    if(k==0)return -d;
    if(k==1)return v[x]-d;
    return 100-d;
}

void dijkstra(){
    for(int i=1;i<=n;i++)
        for(int k=0;k<3;k++)dist[i][k] = -LINF;
    priority_queue<node> heap;
    heap.push({0,1,0});
    dist[1][0] = 0;

    while(heap.size()){
        auto tmp = heap.top();heap.pop();
        int x = tmp.x,k = tmp.k;
        if(st[x][k])continue;
        st[x][k] = true;

        if(k<2 && dist[x][k+1] < dist[x][k]){
            dist[x][k+1] = dist[x][k];
            heap.push({get(dist[x][k+1],x,k+1),x,k+1});
        }

        for(auto t:edge[x]){
            int y = t.first;
            LL z = (k==1 ? v[y]-v[x] : 0);
            if(dist[y][k] < dist[x][k]+z){
                dist[y][k] = dist[x][k]+z;
                heap.push({get(dist[y][k],y,k),y,k});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>v[i];
    for(int i=1;i<=m;i++){
        int a,b,c;cin>>a>>b>>c;
        edge[a].push_back({b,0});
        if(c==2)edge[b].push_back({a,0});
    }

    dijkstra();
    cout<<max(0LL,dist[n][2])<<qp;
}