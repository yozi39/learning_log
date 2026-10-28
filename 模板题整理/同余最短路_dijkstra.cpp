//2371
#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+5,INF = 0x3f3f3f3f,M=6e6+5;

typedef long long LL;
typedef pair<LL,int> PII;
int n,m=INF;
LL l,r;
int a[20];

int h[N],e[M],ne[M],w[M],id;
void add(int a,int b,int c){
    id++;
    e[id]=b;w[id]=c;ne[id]=h[a];h[a]=id;
}

LL dist[N];
bool st[N];
void dijkstra(){
    memset(dist,0x3f,sizeof dist);
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    dist[0] = 0;
    heap.push({0,0});

    while(heap.size()){
        auto t = heap.top();heap.pop();
        int x = t.second;
        if(st[x])continue;
        st[x] = true;

        for(int y = h[x];y;y = ne[y]){
            int v = e[y],z = w[y];
            if(dist[v] > dist[x] + z){
                dist[v] = dist[x] + z;
                heap.push({dist[v],v});
            }
        }
    }
}

int main(){
    cin>>n>>l>>r;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>0)m = min(m,a[i]);
    }
    if(m==INF){
        cout<<0;
        return 0; 
    }

    for(int i=1;i<=n;i++){
        if(a[i] == m)continue;
        for(int j=0;j<m;j++)//枚举点
            add(j,(j+a[i])%m,a[i]);
    }
    
    dijkstra();

    long long ret = 0;
    for(int i=0;i<m;i++){
        if(dist[i]>r)continue;
        long long x = dist[i];
        if(x<l)x+=(l-x+m-1)/m*m;
        if(x<=r)ret+=(r-x)/m+1;
    }
    cout<<ret;
}