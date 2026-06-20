#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=1e5+10,INF=0x3f3f3f3f;

int n,m,s;
vector<PII> edge[N];
priority_queue<PII,vector<PII>,greater<PII>> heap;

int


long long dist[N],st[N];
void dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[s]=0;
    heap.push({0,s});//因为比较的是第一个所以要前面是数据后面是点

    while(heap.size()){
        auto x=heap.top();heap.pop();//拿数

        int a=x.second;
        if(st[a])continue;
        st[a]=true;

        for(auto& y:edge[a]){
            int c=y.first,b=y.second;
            if(dist[c] > dist[a]+b){
                dist[c]=dist[a]+b;
                heap.push({dist[c],c});
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<dist[i]<<' ';
}

int main(){
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++){
        int a,b,c;cin>>a>>b>>c;
        edge[a].push_back({b,c});
    }

    dijkstra();
}