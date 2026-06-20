#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=1e4+10,INF=2147483647;
int n,m,s;
vector<PII> edge[N];


int dist[N],st[N];
void dijkstra(){
    for(int i=0;i<=n;i++)dist[i]=INF;

    dist[s]=0;

    for(int i=1;i<n;i++){//循环n-1次
        int a=0;//用来挑选min dist
        for(int j=1;j<=n;j++){
            if(!st[j] && dist[a]>dist[j]){
                a=j;
            }
        }

        st[a]=1;

        for(auto& v:edge[a]){
            int b=v.first,w=v.second;

            if(dist[a]+w < dist[b]){
                dist[b]=dist[a]+w;
            }

        }
    }
    for(int i=1;i<=n;i++)cout<<dist[i]<<' ';
}

int main(){
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++){
        int ta,tb,tc;cin>>ta>>tb>>tc;

        edge[ta].push_back({tb,tc});
    }

    dijkstra();
}