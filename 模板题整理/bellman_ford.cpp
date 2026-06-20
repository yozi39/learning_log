#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=1e4+10,INF=2147483647;

int n,m,s;
vector<PII> edge[N];

int dist[N],change;
void bellman_ford(){
    change=1;
    for(int i=1;i<=n;i++)dist[i]=INF;
    dist[s]=0;
    while(change){
        change=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INF)continue;
            for(auto& y:edge[i]){
                int b=y.first,c=y.second;
                if(dist[b] > dist[i]+c){
                    dist[b]=dist[i]+c;
                    change++;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<dist[i]<<' ';
}

int main(){
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edge[a].push_back({b,c});
    }

    bellman_ford();
}