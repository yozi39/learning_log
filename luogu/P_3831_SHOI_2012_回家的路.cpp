#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 2e5 + 10,M = 1e6+10;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n,m;
int s,t;
LL dist[M];
bool st[M];
struct node{
    LL x,y,id;
}a[N];
int h[N],e[M],ne[M],w[M],id;

void add(int a,int b,int c){
    id++;
    e[id]=b,w[id]=c,ne[id]=h[a],h[a]=id;
}

void build(){
    sort(a+1,a+1+m,[](node& a,node& b){
        if(a.x == b.x)return a.y<b.y;
        return a.x<b.x;
    });
    for(int i=1;i<m;i++){
        if(a[i].x == a[i+1].x){
            int x = a[i].id,y=a[i+1].id,z=(a[i+1].y-a[i].y)*2;
            add(x,y,z);add(y,x,z);
        }
    }

    sort(a+1,a+1+m,[](node& a,node& b){
        if(a.y == b.y)return a.x<b.x;
        return a.y<b.y;
    });
    for(int i=1;i<m;i++){
        if(a[i].y == a[i+1].y){
            int x = a[i].id,y=a[i+1].id,z=(a[i+1].x-a[i].x)*2;
            add(x+m,y+m,z);add(y+m,x+m,z);
        }
    }

    for(int i=1;i<=m;i++){
        int x = a[i].id,y=a[i].id+m,z=1;
        add(x,y,z);add(y,x,z);
    }
    add(s,s+m,0);add(s+m,s,0);
    add(t,t+m,0);add(t+m,t,0);
}

void dijkstra(){
    memset(dist,0x3f,sizeof dist);
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,s});
    dist[s] = 0;

    while (heap.size())
    {
        int x = heap.top().second;heap.pop();
        if(st[x])continue;
        st[x] = true;

        for(int i = h[x];i;i=ne[i]){
            int y = e[i],z=w[i];
            if(dist[x]+z<dist[y]){
                dist[y] = dist[x]+z;
                heap.push({dist[y],y});
            }
        }
    }
    
}

int main(){
    cin>>n>>m;m+=2;
    for(int i=1;i<=m;i++){
        cin>>a[i].x>>a[i].y;
        a[i].id=i;
    }
    s=m-1,t=m;

    build();
    dijkstra();

    if(dist[t] == LINF)cout<<-1<<qp;
    else cout<<dist[t]<<qp;
}